#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Cria��o e libera��o

No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

// An�lises

int altura(No* raiz) {
    if (raiz == NULL)
        return 0;
    int alt_esq = altura(raiz->esquerda);
    int alt_dir = altura(raiz->direita);
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

int contar_nos(No* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

int contar_folhas(No* raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    return contar_folhas(raiz->esquerda) + contar_folhas(raiz->direita);
}

// Visualiza��o

void imprimir_arvore(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimir_arvore(raiz->esquerda);
        imprimir_arvore(raiz->direita);
    }
}
