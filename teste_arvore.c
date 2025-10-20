#include <stdio.h>
#include "arvore.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "");
    // Criação manual de uma árvore binária
    No* raiz = criar_no(10);
    raiz->esquerda = criar_no(5);
    raiz->direita = criar_no(15);
    raiz->esquerda->esquerda = criar_no(3);
    raiz->esquerda->direita = criar_no(7);
    raiz->direita->direita = criar_no(20);

    printf("Árvore em pré-ordem: ");
    imprimir_arvore(raiz);
    printf("\n");

    printf("Altura da árvore: %d\n", altura(raiz));
    printf("Total de nós: %d\n", contar_nos(raiz));
    printf("Total de folhas: %d\n", contar_folhas(raiz));

    liberar_arvore(raiz);
    return 0;
}
