#include <stdio.h>
#include "arvore.h"
#include "percursos.h"
#include "abb.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "");

    No* raiz = NULL;

    // Inserção
    raiz = inserir_abb(raiz, 50);
    raiz = inserir_abb(raiz, 30);
    raiz = inserir_abb(raiz, 70);
    raiz = inserir_abb(raiz, 20);
    raiz = inserir_abb(raiz, 40);
    raiz = inserir_abb(raiz, 60);
    raiz = inserir_abb(raiz, 80);

    printf("ABB em ordem (ordenada): ");
    em_ordem(raiz);
    printf("\n");

    // Busca
    No* encontrado = buscar_abb(raiz, 30);
    if (encontrado != NULL)
        printf("Elemento 30 encontrado!\n");
    else
        printf("Elemento 30 NÃO encontrado!\n");

    // Mínimo e máximo
    No* min = encontrar_minimo(raiz);
    No* max = encontrar_maximo(raiz);
    if (min) printf("Mínimo: %d\n", min->valor);
    if (max) printf("Máximo: %d\n", max->valor);

    // Verificar se é ABB válida
    printf("A árvore é uma ABB válida? %s\n", verificar_abb(raiz) ? "Sim" : "Não");

    // Remoção
    printf("Removendo 30...\n");
    raiz = remover_abb(raiz, 30);
    printf("ABB após remoção: ");
    em_ordem(raiz);
    printf("\n");

    liberar_arvore(raiz);
    return 0;
}
