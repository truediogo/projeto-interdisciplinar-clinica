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

    // Obtém o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    // Calcula o número de registros
    int num_registros = tamanho / sizeof(Paciente);

    // Lê cada registro e reconstrói as estruturas
    for (int i = 0; i < num_registros; i++) {
        Paciente paciente;
        fread(&paciente, sizeof(Paciente), 1, arquivo);

        // Insere na árvore e na lista
        *raiz = inserirArvore(*raiz, paciente.cpf, i);
        *inicio = inserirListaOrdenada(*inicio, paciente.nome, i);
    }

    fclose(arquivo);
}

int validarCPF(long long cpf) {
    if (cpf <= 0) return 0;

    int digitos[11];
    long long temp = cpf;
    for (int i = 10; i >= 0; i--) {
        digitos[i] = temp % 10;
        temp /= 10;
    }

    int todosIguais = 1;
    for (int i = 1; i < 11; i++) {
        if (digitos[i] != digitos[0]) {
            todosIguais = 0;
            break;
        }
    }
    if (todosIguais) return 0;

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += digitos[i] * (10 - i);
    }

    int dv1 = 11 - (soma % 11);
    if (dv1 > 9) dv1 = 0;
    if (dv1 != digitos[9]) return 0;

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += digitos[i] * (11 - i);
    }
    int dv2 = 11 - (soma % 11);
    if (dv2 > 9) dv2 = 0;
    if (dv2 != digitos[10]) return 0;

    return 1;
}

int validarEmail(const char* email) {
    if (strlen(email) == 0) return 0;

    const char* arroba = strchr(email, '@');
    if (!arroba) return 0;

    if (arroba == email || *(arroba + 1) == '\0') return 0;

    const char* ponto = strchr(arroba, '.');
    if (!ponto || *(ponto + 1) == '\0') return 0;

    return 1;
}

int validarTelefone(const char* telefone) {
    if (strlen(telefone) == 0) return 0;

    int numDigitos = 0;
    for (int i = 0; telefone[i]; i++) {
        if (isdigit(telefone[i])) {
            numDigitos++;
        }
    }

    return (numDigitos == 10 || numDigitos == 11);
}

int validarCampoTexto(const char* texto, int tamanhoMinimo) {
    if (!texto || strlen(texto) < tamanhoMinimo) return 0;
    return 1;
}


NoArvore* criarNoArvore(long long cpf, int num_registro) {
    NoArvore* novo = (NoArvore*)malloc(sizeof(NoArvore));
    novo->cpf = cpf;
    novo->num_registro = num_registro;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

NoArvore* inserirArvore(NoArvore* raiz, long long cpf, int num_registro) {
    if (raiz == NULL) {
        return criarNoArvore(cpf, num_registro);
    }

    if (cpf < raiz->cpf) {
        raiz->esquerda = inserirArvore(raiz->esquerda, cpf, num_registro);
    }
    else if (cpf > raiz->cpf) {
        raiz->direita = inserirArvore(raiz->direita, cpf, num_registro);
    }

    return raiz;
}

NoArvore* buscarArvore(NoArvore* raiz, long long cpf) {
    if (raiz == NULL || raiz->cpf == cpf) {
        return raiz;
    }

    if (cpf < raiz->cpf) {
        return buscarArvore(raiz->esquerda, cpf);
    }

    return buscarArvore(raiz->direita, cpf);
}

NoLista* criarNoLista(char* nome, int num_registro) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    strcpy(novo->nome, nome);
    novo->num_registro = num_registro;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

NoLista* inserirListaOrdenada(NoLista* inicio, char* nome, int num_registro) {
    NoLista* novo = criarNoLista(nome, num_registro);

    if (inicio == NULL) {
        return novo;
    }

    NoLista* atual = inicio;

    while (atual->proximo != NULL && strcmp(nome, atual->nome) > 0) {
        atual = atual->proximo;
    }

    if (strcmp(nome, atual->nome) <= 0) {
        if (atual->anterior == NULL) {
            novo->proximo = atual;
            atual->anterior = novo;
            return novo;
        } else {
            novo->anterior = atual->anterior;
            novo->proximo = atual;
            atual->anterior->proximo = novo;
            atual->anterior = novo;
        }
    } else {
        novo->anterior = atual;
        novo->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = novo;
        }
        atual->proximo = novo;
    }

    return inicio;
}

NoLista* removerDaLista(NoLista* inicio, int num_registro) {
    NoLista* atual = inicio;

    while (atual != NULL) {
        if (atual->num_registro == num_registro) {
            if (atual->anterior == NULL) {
                NoLista* proximo = atual->proximo;
                if (proximo != NULL) {
                    proximo->anterior = NULL;
                }
                free(atual);
                return proximo;
            } else {
                atual->anterior->proximo = atual->proximo;
                if (atual->proximo != NULL) {
                    atual->proximo->anterior = atual->anterior;
                }
                free(atual);
                return inicio;
            }
        }
        atual = atual->proximo;
    }
    return inicio;
}

NoArvore* encontrarMenor(NoArvore* node) {
    NoArvore* atual = node;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

NoArvore* removerDaArvore(NoArvore* raiz, long long cpf, int* num_registro) {
    if (raiz == NULL) return raiz;

    if (cpf < raiz->cpf) {
        raiz->esquerda = removerDaArvore(raiz->esquerda, cpf, num_registro);
    }
    else if (cpf > raiz->cpf) {
        raiz->direita = removerDaArvore(raiz->direita, cpf, num_registro);
    }
    else {
        *num_registro = raiz->num_registro;

        if (raiz->esquerda == NULL) {
            NoArvore* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            NoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        NoArvore* temp = encontrarMenor(raiz->direita);
        raiz->cpf = temp->cpf;
        raiz->num_registro = temp->num_registro;
        raiz->direita = removerDaArvore(raiz->direita, temp->cpf, num_registro);
    }
    return raiz;
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