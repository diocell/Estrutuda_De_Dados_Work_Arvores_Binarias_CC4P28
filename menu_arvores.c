#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "percursos.h"
#include "abb.h"
#include "locale.h"

// Protótipos
void menu_principal();
void menu_arvore_simples();
void menu_abb();

// Funções auxiliares
No* inserir_manual(No* raiz, int valor);
No* buscar_manual(No* raiz, int valor);
No* remover_manual(No* raiz, int valor);

int main() {
    //setando locale para resolver problemas das letras
    setlocale(LC_ALL, "");

    int opcao;

    do {
        menu_principal();
        printf("Escolha uma opção: ");
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
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// MENUS PRINCIPAIS

void menu_principal() {
    printf("\n=== MENU DE ÁRVORES ===\n");
    printf("1. Usar Árvore Binária Simples (inserção manual)\n");
    printf("2. Usar Árvore Binária de Busca (ABB)\n");
    printf("0. Sair\n");
}

// Árvore Binária Simples

void menu_arvore_simples() {
    int opcao, valor;
    No* raiz = NULL;

    do {
        printf("\n=== ÁRVORE BINÁRIA SIMPLES ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Imprimir (pré-ordem)\n");
        printf("5. Análise da árvore (altura, nós, folhas)\n");
        printf("6. Percursos (pré, em, pós, níveis)\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
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
                    printf("Valor %d não encontrado.\n", valor);
                break;

            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                raiz = remover_manual(raiz, valor);
                printf("Remoção concluída (se existia).\n");
                break;

            case 4:
                printf("Árvore (pré-ordem): ");
                imprimir_arvore(raiz);
                printf("\n");
                break;

            case 5:
                printf("Altura: %d\n", altura(raiz));
                printf("Total de nós: %d\n", contar_nos(raiz));
                printf("Total de folhas: %d\n", contar_folhas(raiz));
                break;

            case 6:
                printf("\nPré-ordem: ");
                pre_ordem(raiz);
                printf("\nEm-ordem: ");
                em_ordem(raiz);
                printf("\nPós-ordem: ");
                pos_ordem(raiz);
                printf("\nPor níveis: ");
                percurso_por_niveis(raiz);
                printf("\n");
                break;

            case 0:
                liberar_arvore(raiz);
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

// Árvore Binária de Busca (ABB)

void menu_abb() {
    int opcao, valor;
    No* raiz = NULL;
    No* encontrado;

    do {
        printf("\n=== ÁRVORE BINÁRIA DE BUSCA (ABB) ===\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Imprimir (em-ordem)\n");
        printf("5. Mostrar mínimo e máximo\n");
        printf("6. Verificar se é ABB válida\n");
        printf("7. Percursos (pré, em, pós, níveis)\n");
        printf("8. Análise da árvore (altura, nós, folhas)\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
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
                    printf("Valor %d não encontrado.\n", valor);
                break;

            case 3:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                raiz = remover_abb(raiz, valor);
                printf("Remoção concluída (se existia).\n");
                break;

            case 4:
                printf("Árvore em ordem: ");
                em_ordem(raiz);
                printf("\n");
                break;

            case 5: {
                No* min = encontrar_minimo(raiz);
                No* max = encontrar_maximo(raiz);
                if (min) printf("Mínimo: %d\n", min->valor);
                if (max) printf("Máximo: %d\n", max->valor);
                break;
            }

            case 6:
                printf("A árvore é uma ABB válida? %s\n",
                       verificar_abb(raiz) ? "Sim" : "Não");
                break;

            case 7:
                printf("\nPré-ordem: ");
                pre_ordem(raiz);
                printf("\nEm-ordem: ");
                em_ordem(raiz);
                printf("\nPós-ordem: ");
                pos_ordem(raiz);
                printf("\nPor níveis: ");
                percurso_por_niveis(raiz);
                printf("\n");
                break;

            case 8:
                printf("Altura: %d\n", altura(raiz));
                printf("Total de nós: %d\n", contar_nos(raiz));
                printf("Total de folhas: %d\n", contar_folhas(raiz));
                break;

            case 0:
                liberar_arvore(raiz);
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

// Funções auxiliares da Árvore Simples

// Inserção manual (usuário escolhe o lado)
No* inserir_manual(No* raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    int direcao;
    printf("Inserir à esquerda (1) ou direita (2) de %d? ", raiz->valor);
    scanf("%d", &direcao);

    if (direcao == 1)
        raiz->esquerda = inserir_manual(raiz->esquerda, valor);
    else if (direcao == 2)
        raiz->direita = inserir_manual(raiz->direita, valor);
    else
        printf("Opção inválida! Não inserido.\n");

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

// Remoção simples (sem reorganizar)
No* remover_manual(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (raiz->valor == valor) {
        liberar_arvore(raiz);
        return NULL; // remove toda subárvore
    }

    raiz->esquerda = remover_manual(raiz->esquerda, valor);
    raiz->direita = remover_manual(raiz->direita, valor);
    return raiz;
}
