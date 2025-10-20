#ifndef ARVORE_SEQ_H
#define ARVORE_SEQ_H

#define MAX_NOS 100
#define VAZIO -1

typedef struct {
    int valor[MAX_NOS];
    int tamanho;
} ArvoreSeq;

// Inicializa a árvore (todas as posições como VAZIO)
void inicializar_arvore_seq(ArvoreSeq* arvore);

// Insere um novo valor na primeira posição livre
int inserir_sequencial(ArvoreSeq* arvore, int valor);

// Busca um valor no vetor (retorna índice ou -1)
int buscar_sequencial(const ArvoreSeq* arvore, int valor);

// Imprime a árvore em formato sequencial
void imprimir_sequencial(const ArvoreSeq* arvore);

#endif
