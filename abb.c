#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

// Inserção
No* inserir_abb(No* raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir_abb(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir_abb(raiz->direita, valor);

    // Se o valor já existir, não faz nada
    return raiz;
}

// Busca
No* buscar_abb(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar_abb(raiz->esquerda, valor);
    else
        return buscar_abb(raiz->direita, valor);
}

// Encontrar mínimo/máximo
No* encontrar_minimo(No* raiz) {
    if (raiz == NULL)
        return NULL;

    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

No* encontrar_maximo(No* raiz) {
    if (raiz == NULL)
        return NULL;

    while (raiz->direita != NULL)
        raiz = raiz->direita;
    return raiz;
}

// Remoção
No* remover_abb(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover_abb(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_abb(raiz->direita, valor);
    } else {
        // Encontrou o nó a ser removido

        // Caso 1: sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        // Caso 2: apenas um filho
        else if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Caso 3: dois filhos
        else {
            No* sucessor = encontrar_minimo(raiz->direita);
            raiz->valor = sucessor->valor;
            raiz->direita = remover_abb(raiz->direita, sucessor->valor);
        }
    }
    return raiz;
}

// Verificar se é ABB
static int verificar_abb_aux(No* raiz, int min, int max) {
    if (raiz == NULL)
        return 1;

    if (raiz->valor <= min || raiz->valor >= max)
        return 0;

    return verificar_abb_aux(raiz->esquerda, min, raiz->valor) &&
           verificar_abb_aux(raiz->direita, raiz->valor, max);
}

int verificar_abb(No* raiz) {
    return verificar_abb_aux(raiz, -2147483648, 2147483647);
}
