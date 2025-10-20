#include <stdio.h>
#include "arvore.h"
#include "percursos.h"
#include "locale.h"


int main() {
    setlocale(LC_ALL, "");
    // Construindo árvore de exemplo
    No* raiz = criar_no(1);
    raiz->esquerda = criar_no(2);
    raiz->direita = criar_no(3);
    raiz->esquerda->esquerda = criar_no(4);
    raiz->esquerda->direita = criar_no(5);
    raiz->direita->esquerda = criar_no(6);
    raiz->direita->direita = criar_no(7);

    printf("Pré-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf("Em-ordem: ");
    em_ordem(raiz);
    printf("\n");

    printf("Pós-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    printf("Por níveis: ");
    percurso_por_niveis(raiz);
    printf("\n");

    liberar_arvore(raiz);
    return 0;
}
