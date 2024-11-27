#include "aplicacao.h"

int main() {
    NoArvore* raiz = NULL;
    NoLista* inicio = NULL;
    int opcao;

    carregarDados(&raiz, &inicio);

    do {
        printf("\n=== Menu Principal ===\n");
        printf("1. Adicionar Paciente\n");
        printf("2. Alterar Paciente\n");
        printf("3. Excluir Paciente\n");
        printf("4. Procurar Paciente\n");
        printf("5. Relatório\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionar(&raiz, &inicio);
                break;
            case 2:
                alterar(raiz, &inicio);
                break;
            case 3:
                excluir(&raiz, &inicio);
                break;
            case 4:
                procurar(raiz);
                break;
            case 5:
                relatorio(inicio);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}