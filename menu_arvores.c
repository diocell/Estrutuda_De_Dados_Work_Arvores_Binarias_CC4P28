#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "percursos.h"
#include "abb.h"
#include "locale.h"

// Prot�tipos
void menu_principal();
void menu_arvore_simples();
void menu_abb();

// Fun��es auxiliares
No* inserir_manual(No* raiz, int valor);
No* buscar_manual(No* raiz, int valor);
No* remover_manual(No* raiz, int valor);

int main() {
    //setando locale para resolver problemas das letras
    setlocale(LC_ALL, "");

    int opcao;

    do {
        menu_principal();
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_arvore_simples();
                break;
            case 2:
                menu_abb();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// MENUS PRINCIPAIS

void menu_principal() {
    printf("\n=== MENU DE �RVORES ===\n");
    printf("1. Usar �rvore Bin�ria Simples (inser��o manual)\n");
    printf("2. Usar �rvore Bin�ria de Busca (ABB)\n");
    printf("0. Sair\n");
}

// �rvore Bin�ria Simples

void menu_arvore_simples() {
    int opcao, valor;
    No* raiz = NULL;

    do {
        printf("\n=== �RVORE BIN�RIA SIMPLES ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Imprimir (pr�-ordem)\n");
        printf("5. An�lise da �rvore (altura, n�s, folhas)\n");
        printf("6. Percursos (pr�, em, p�s, n�veis)\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                raiz = inserir_manual(raiz, valor);
                break;

            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                if (buscar_manual(raiz, valor))
                    printf("Valor %d encontrado!\n", valor);
                else
                    printf("Valor %d n�o encontrado.\n", valor);
                break;

            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                raiz = remover_manual(raiz, valor);
                printf("Remo��o conclu�da (se existia).\n");
                break;

            case 4:
                printf("�rvore (pr�-ordem): ");
                imprimir_arvore(raiz);
                printf("\n");
                break;

            case 5:
                printf("Altura: %d\n", altura(raiz));
                printf("Total de n�s: %d\n", contar_nos(raiz));
                printf("Total de folhas: %d\n", contar_folhas(raiz));
                break;

            case 6:
                printf("\nPr�-ordem: ");
                pre_ordem(raiz);
                printf("\nEm-ordem: ");
                em_ordem(raiz);
                printf("\nP�s-ordem: ");
                pos_ordem(raiz);
                printf("\nPor n�veis: ");
                percurso_por_niveis(raiz);
                printf("\n");
                break;

            case 0:
                liberar_arvore(raiz);
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);
}

// �rvore Bin�ria de Busca (ABB)

void menu_abb() {
    int opcao, valor;
    No* raiz = NULL;
    No* encontrado;

    do {
        printf("\n=== �RVORE BIN�RIA DE BUSCA (ABB) ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Imprimir (em-ordem)\n");
        printf("5. Mostrar m�nimo e m�ximo\n");
        printf("6. Verificar se � ABB v�lida\n");
        printf("7. Percursos (pr�, em, p�s, n�veis)\n");
        printf("8. An�lise da �rvore (altura, n�s, folhas)\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                raiz = inserir_abb(raiz, valor);
                printf("Valor %d inserido!\n", valor);
                break;

            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                encontrado = buscar_abb(raiz, valor);
                if (encontrado)
                    printf("Valor %d encontrado!\n", valor);
                else
                    printf("Valor %d n�o encontrado.\n", valor);
                break;

            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                raiz = remover_abb(raiz, valor);
                printf("Remo��o conclu�da (se existia).\n");
                break;

            case 4:
                printf("�rvore em ordem: ");
                em_ordem(raiz);
                printf("\n");
                break;

            case 5: {
                No* min = encontrar_minimo(raiz);
                No* max = encontrar_maximo(raiz);
                if (min) printf("M�nimo: %d\n", min->valor);
                if (max) printf("M�ximo: %d\n", max->valor);
                break;
            }

            case 6:
                printf("A �rvore � uma ABB v�lida? %s\n",
                       verificar_abb(raiz) ? "Sim" : "N�o");
                break;

            case 7:
                printf("\nPr�-ordem: ");
                pre_ordem(raiz);
                printf("\nEm-ordem: ");
                em_ordem(raiz);
                printf("\nP�s-ordem: ");
                pos_ordem(raiz);
                printf("\nPor n�veis: ");
                percurso_por_niveis(raiz);
                printf("\n");
                break;

            case 8:
                printf("Altura: %d\n", altura(raiz));
                printf("Total de n�s: %d\n", contar_nos(raiz));
                printf("Total de folhas: %d\n", contar_folhas(raiz));
                break;

            case 0:
                liberar_arvore(raiz);
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 0);
}

// Fun��es auxiliares da �rvore Simples

// Inser��o manual (usu�rio escolhe o lado)
No* inserir_manual(No* raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    int direcao;
    printf("Inserir � esquerda (1) ou direita (2) de %d? ", raiz->valor);
    scanf("%d", &direcao);

    if (direcao == 1)
        raiz->esquerda = inserir_manual(raiz->esquerda, valor);
    else if (direcao == 2)
        raiz->direita = inserir_manual(raiz->direita, valor);
    else
        printf("Op��o inv�lida! N�o inserido.\n");

    return raiz;
}

// Busca manual
No* buscar_manual(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;
    if (raiz->valor == valor)
        return raiz;

    No* esq = buscar_manual(raiz->esquerda, valor);
    if (esq != NULL) return esq;
    return buscar_manual(raiz->direita, valor);
}

// Remo��o simples (sem reorganizar)
No* remover_manual(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (raiz->valor == valor) {
        liberar_arvore(raiz);
        return NULL; // remove toda sub�rvore
    }

    raiz->esquerda = remover_manual(raiz->esquerda, valor);
    raiz->direita = remover_manual(raiz->direita, valor);
    return raiz;
}
