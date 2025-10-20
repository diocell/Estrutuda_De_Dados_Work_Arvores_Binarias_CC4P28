#include <stdio.h>
#include "arvore_seq.h"

// Inicializa a árvore (define todos como VAZIO)
void inicializar_arvore_seq(ArvoreSeq* arvore) {
    arvore->tamanho = 0;
    for (int i = 0; i < MAX_NOS; i++) {
        arvore->valor[i] = VAZIO;
    }
}

// Insere um novo valor na primeira posição livre
int inserir_sequencial(ArvoreSeq* arvore, int valor) {
    if (arvore->tamanho >= MAX_NOS) {
        printf("Erro: árvore cheia!\n");
        return 0;
    }

    arvore->valor[arvore->tamanho] = valor;
    arvore->tamanho++;
    return 1;
}

// Busca sequencial no vetor (retorna índice ou -1)
int buscar_sequencial(const ArvoreSeq* arvore, int valor) {
    for (int i = 0; i < arvore->tamanho; i++) {
        if (arvore->valor[i] == valor)
            return i;
    }
    return -1;
}

// Imprime árvore em formato sequencial (índices e filhos)
void imprimir_sequencial(const ArvoreSeq* arvore) {
    printf("\nRepresentação sequencial da árvore:\n");
    for (int i = 0; i < arvore->tamanho; i++) {
        printf("[%d] = %d  ", i, arvore->valor[i]);
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        if (esq < arvore->tamanho && arvore->valor[esq] != VAZIO)
            printf("(E:%d) ", arvore->valor[esq]);
        if (dir < arvore->tamanho && arvore->valor[dir] != VAZIO)
            printf("(D:%d) ", arvore->valor[dir]);

        printf("\n");
    }
}
