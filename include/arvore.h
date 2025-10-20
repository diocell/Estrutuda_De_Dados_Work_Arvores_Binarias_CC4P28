#ifndef ARVORE_H
#define ARVORE_H

// Estrutura b�sica de n� de �rvore bin�ria
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Cria��o e libera��o
No* criar_no(int valor);
void liberar_arvore(No* raiz);

// An�lises
int altura(No* raiz);
int contar_nos(No* raiz);
int contar_folhas(No* raiz);

// Impress�o (pr�-ordem)
void imprimir_arvore(No* raiz);

#endif
