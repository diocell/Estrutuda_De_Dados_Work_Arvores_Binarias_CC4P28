#include <stdio.h>
#include "arvore.h"
#include "percursos.h"
#include "abb.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "");

    No* raiz = NULL;

    // Inser��o
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
        printf("Elemento 30 N�O encontrado!\n");

    // M�nimo e m�ximo
    No* min = encontrar_minimo(raiz);
    No* max = encontrar_maximo(raiz);
    if (min) printf("M�nimo: %d\n", min->valor);
    if (max) printf("M�ximo: %d\n", max->valor);

    // Verificar se � ABB v�lida
    printf("A �rvore � uma ABB v�lida? %s\n", verificar_abb(raiz) ? "Sim" : "N�o");

    // Remo��o
    printf("Removendo 30...\n");
    raiz = remover_abb(raiz, 30);
    printf("ABB ap�s remo��o: ");
    em_ordem(raiz);
    printf("\n");

    liberar_arvore(raiz);
    return 0;
}
