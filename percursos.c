#include <stdio.h>
#include <stdlib.h>
#include "percursos.h"

// Percursos recursivos

void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Percurso por níveis

typedef struct Fila {
    No* no;
    struct Fila* prox;
} Fila;

// Funções auxiliares da fila
static Fila* criar_fila(No* no) {
    Fila* novo = (Fila*) malloc(sizeof(Fila));
    novo->no = no;
    novo->prox = NULL;
    return novo;
}

static void enfileirar(Fila** inicio, Fila** fim, No* no) {
    Fila* novo = criar_fila(no);
    if (*fim == NULL) {
        *inicio = *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }
}

static No* desenfileirar(Fila** inicio, Fila** fim) {
    if (*inicio == NULL)
        return NULL;

    Fila* temp = *inicio;
    No* no = temp->no;
    *inicio = (*inicio)->prox;
    if (*inicio == NULL)
        *fim = NULL;
    free(temp);
    return no;
}

void percurso_por_niveis(No* raiz) {
    if (raiz == NULL)
        return;

    Fila *inicio = NULL, *fim = NULL;
    enfileirar(&inicio, &fim, raiz);

    while (inicio != NULL) {
        No* atual = desenfileirar(&inicio, &fim);
        printf("%d ", atual->valor);

        if (atual->esquerda != NULL)
            enfileirar(&inicio, &fim, atual->esquerda);
        if (atual->direita != NULL)
            enfileirar(&inicio, &fim, atual->direita);
    }
}
