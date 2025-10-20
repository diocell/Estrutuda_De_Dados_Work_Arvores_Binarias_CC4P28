#ifndef PERCURSOS_H
#define PERCURSOS_H

#include "arvore.h"

// Percursos recursivos
void pre_ordem(No* raiz);
void em_ordem(No* raiz);
void pos_ordem(No* raiz);

// Percurso por níveis (iterativo usando fila)
void percurso_por_niveis(No* raiz);

#endif
