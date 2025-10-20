#include <stdio.h>
#include "arvore_seq.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "");

    ArvoreSeq arvore;
    inicializar_arvore_seq(&arvore);

    int opcao, valor;

    do {
        printf("\n=== �RVORE SEQUENCIAL ===\n");
        printf("1. Inserir valor\n");
        printf("2. Buscar valor\n");
        printf("3. Imprimir �rvore\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (inserir_sequencial(&arvore, valor))
                    printf("Valor %d inserido com sucesso!\n", valor);
                break;

            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                int pos = buscar_sequencial(&arvore, valor);
                if (pos != -1)
                    printf("Valor %d encontrado na posi��o [%d].\n", valor, pos);
                else
                    printf("Valor %d n�o encontrado.\n", valor);
                break;

            case 3:
                imprimir_sequencial(&arvore);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);

    return 0;
}
