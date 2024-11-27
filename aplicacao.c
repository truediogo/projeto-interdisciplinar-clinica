#include <stdio.h>
#include <string.h>

#include "aplicacao.h"

#include "lib/estrutura.h"
#include "lib/validacoes.h"

void carregarDados(NoArvore** raiz, NoLista** inicio) {
    FILE* arquivo = fopen("pacientes.dat", "rb");
    if (arquivo == NULL) {
        *raiz = NULL;
        *inicio = NULL;
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    int num_registros = tamanho / sizeof(Paciente);

    for (int i = 0; i < num_registros; i++) {
        Paciente paciente;
        fread(&paciente, sizeof(Paciente), 1, arquivo);

        *raiz = inserirArvore(*raiz, paciente.cpf, i);
        *inicio = inserirListaOrdenada(*inicio, paciente.nome, i);
    }

    fclose(arquivo);
}



int salvarPaciente(Paciente* paciente) {
    FILE* arquivo = fopen("pacientes.dat", "ab");
    if (arquivo == NULL) {
        return -1;
    }

    int num_registro = ftell(arquivo) / sizeof(Paciente);
    fwrite(paciente, sizeof(Paciente), 1, arquivo);
    fclose(arquivo);

    return num_registro;
}

Paciente lerPaciente(int num_registro) {
    Paciente paciente;
    FILE* arquivo = fopen("pacientes.dat", "rb");

    if (arquivo != NULL) {
        fseek(arquivo, num_registro * sizeof(Paciente), SEEK_SET);
        fread(&paciente, sizeof(Paciente), 1, arquivo);
        fclose(arquivo);
    }

    return paciente;
}

void adicionar(NoArvore** raiz, NoLista** inicio) {
    Paciente paciente;
    printf("\nDigite o CPF: ");
    scanf("%lld", &paciente.cpf);

    if (!validarCPF(paciente.cpf)) {
        printf("CPF inválido!\n");
        return;
    }

    if (buscarArvore(*raiz, paciente.cpf) != NULL) {
        printf("CPF já cadastrado!\n");
        return;
    }

    printf("Nome: ");
    getchar();
    fgets(paciente.nome, MAX_NOME, stdin);
    paciente.nome[strcspn(paciente.nome, "\n")] = 0;

    if (!validarCampoTexto(paciente.nome, 3)) {
        printf("Nome inválido! Deve ter pelo menos 3 caracteres.\n");
        return;
    }

    printf("Endereco: ");
    fgets(paciente.endereco, MAX_ENDERECO, stdin);
    paciente.endereco[strcspn(paciente.endereco, "\n")] = 0;

    if (!validarCampoTexto(paciente.endereco, 5)) {
        printf("Endereço inválido! Deve ter pelo menos 5 caracteres.\n");
        return;
    }

    printf("Telefone: ");
    fgets(paciente.telefone, MAX_TELEFONE, stdin);
    paciente.telefone[strcspn(paciente.telefone, "\n")] = 0;

    if (!validarTelefone(paciente.telefone)) {
        printf("Telefone inválido! Deve conter 10 ou 11 dígitos.\n");
        return;
    }

    printf("Email: ");
    fgets(paciente.email, MAX_EMAIL, stdin);
    paciente.email[strcspn(paciente.email, "\n")] = 0;

    if (!validarEmail(paciente.email)) {
        printf("Email inválido!\n");
        return;
    }

    int num_registro = salvarPaciente(&paciente);
    if (num_registro >= 0) {
        *raiz = inserirArvore(*raiz, paciente.cpf, num_registro);
        *inicio = inserirListaOrdenada(*inicio, paciente.nome, num_registro);
        printf("Paciente cadastrado com sucesso!\n");
    } else {
        printf("Erro ao cadastrar paciente!\n");
    }
}

void procurar(NoArvore* raiz) {
    long long cpf;
    printf("\nDigite o CPF: ");
    scanf("%lld", &cpf);

    NoArvore* no = buscarArvore(raiz, cpf);
    if (no == NULL) {
        printf("CPF não cadastrado!\n");
        return;
    }

    Paciente paciente = lerPaciente(no->num_registro);
    printf("\nDados do Paciente:\n");
    printf("CPF: %lld\n", paciente.cpf);
    printf("Nome: %s\n", paciente.nome);
    printf("Endereco: %s\n", paciente.endereco);
    printf("Telefone: %s\n", paciente.telefone);
    printf("Email: %s\n", paciente.email);
}

void excluir(NoArvore** raiz, NoLista** inicio) {
    long long cpf;
    printf("\nDigite o CPF do paciente a ser excluído: ");
    scanf("%lld", &cpf);

    NoArvore* no = buscarArvore(*raiz, cpf);
    if (no == NULL) {
        printf("CPF não cadastrado!\n");
        return;
    }

    int num_registro;
    *raiz = removerDaArvore(*raiz, cpf, &num_registro);
    *inicio = removerDaLista(*inicio, num_registro);

    printf("Paciente excluído com sucesso!\n");
}

void relatorio(NoLista* inicio) {
    if (inicio == NULL) {
        printf("\nNenhum paciente cadastrado!\n");
        return;
    }

    printf("\n=== Relatório de Pacientes (Ordenado por Nome) ===\n");
    printf("------------------------------------------------\n");

    NoLista* atual = inicio;
    while (atual != NULL) {
        Paciente paciente = lerPaciente(atual->num_registro);
        printf("Nome: %s\n", paciente.nome);
        printf("CPF: %lld\n", paciente.cpf);
        printf("Endereço: %s\n", paciente.endereco);
        printf("Telefone: %s\n", paciente.telefone);
        printf("Email: %s\n", paciente.email);
        printf("------------------------------------------------\n");
        atual = atual->proximo;
    }
}

void alterar(NoArvore* raiz, NoLista** inicio) {
    long long cpf;
    printf("\nDigite o CPF do paciente a ser alterado: ");
    scanf("%lld", &cpf);

    if (!validarCPF(cpf)) {
        printf("CPF inválido!\n");
        return;
    }

    NoArvore* no = buscarArvore(raiz, cpf);
    if (no == NULL) {
        printf("CPF não cadastrado!\n");
        return;
    }

    Paciente paciente = lerPaciente(no->num_registro);
    char nome_antigo[MAX_NOME];
    strcpy(nome_antigo, paciente.nome);

    printf("Novos dados (pressione Enter para manter o valor atual):\n");

    getchar();
    printf("Nome atual: %s\nNovo nome: ", paciente.nome);
    char temp[MAX_NOME];
    fgets(temp, MAX_NOME, stdin);
    temp[strcspn(temp, "\n")] = 0;

    if (strlen(temp) > 0) {
        if (!validarCampoTexto(temp, 3)) {
            printf("Nome inválido! Deve ter pelo menos 3 caracteres.\n");
            return;
        }
        strcpy(paciente.nome, temp);
    }

    printf("Endereco atual: %s\nNovo endereco: ", paciente.endereco);
    fgets(temp, MAX_ENDERECO, stdin);
    temp[strcspn(temp, "\n")] = 0;

    if (strlen(temp) > 0) {
        if (!validarCampoTexto(temp, 5)) {
            printf("Endereço inválido! Deve ter pelo menos 5 caracteres.\n");
            return;
        }
        strcpy(paciente.endereco, temp);
    }

    printf("Telefone atual: %s\nNovo telefone: ", paciente.telefone);
    fgets(temp, MAX_TELEFONE, stdin);
    temp[strcspn(temp, "\n")] = 0;

    if (strlen(temp) > 0) {
        if (!validarTelefone(temp)) {
            printf("Telefone inválido! Deve conter 10 ou 11 dígitos.\n");
            return;
        }
        strcpy(paciente.telefone, temp);
    }

    printf("Email atual: %s\nNovo email: ", paciente.email);
    fgets(temp, MAX_EMAIL, stdin);
    temp[strcspn(temp, "\n")] = 0;

    if (strlen(temp) > 0) {
        if (!validarEmail(temp)) {
            printf("Email inválido!\n");
            return;
        }
        strcpy(paciente.email, temp);
    }

    FILE* arquivo = fopen("pacientes.dat", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para alterações!\n");
        return;
    }
    fseek(arquivo, no->num_registro * sizeof(Paciente), SEEK_SET);
    fwrite(&paciente, sizeof(Paciente), 1, arquivo);
    fclose(arquivo);

    if (strcmp(nome_antigo, paciente.nome) != 0) {
        *inicio = removerDaLista(*inicio, no->num_registro);
        *inicio = inserirListaOrdenada(*inicio, paciente.nome, no->num_registro);
    }

    printf("Paciente alterado com sucesso!\n");
}