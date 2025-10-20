#ifndef ABB_H
#define ABB_H

#include "arvore.h"

// Opera��es de ABB
No* inserir_abb(No* raiz, int valor);
No* buscar_abb(No* raiz, int valor);
No* remover_abb(No* raiz, int valor);

// Fun��es auxiliares
No* encontrar_minimo(No* raiz);
No* encontrar_maximo(No* raiz);

// Verifica��o
int verificar_abb(No* raiz);

#endif
