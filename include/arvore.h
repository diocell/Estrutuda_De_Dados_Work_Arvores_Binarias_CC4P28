#ifndef ARVORE_H
#define ARVORE_H

// Estrutura básica de nó de árvore binária
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Criação e liberação
No* criar_no(int valor);
void liberar_arvore(No* raiz);

// Análises
int altura(No* raiz);
int contar_nos(No* raiz);
int contar_folhas(No* raiz);

// Impressão (pré-ordem)
void imprimir_arvore(No* raiz);

#endif
