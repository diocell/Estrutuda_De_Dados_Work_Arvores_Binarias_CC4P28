#ifndef ABB_H
#define ABB_H

#include "arvore.h"

// Operações de ABB
No* inserir_abb(No* raiz, int valor);
No* buscar_abb(No* raiz, int valor);
No* remover_abb(No* raiz, int valor);

// Funções auxiliares
No* encontrar_minimo(No* raiz);
No* encontrar_maximo(No* raiz);

// Verificação
int verificar_abb(No* raiz);

#endif
