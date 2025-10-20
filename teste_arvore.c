#include <stdio.h>
#include "arvore.h"
#include "locale.h"

int main() {
    setlocale(LC_ALL, "");
    // Cria��o manual de uma �rvore bin�ria
    No* raiz = criar_no(10);
    raiz->esquerda = criar_no(5);
    raiz->direita = criar_no(15);
    raiz->esquerda->esquerda = criar_no(3);
    raiz->esquerda->direita = criar_no(7);
    raiz->direita->direita = criar_no(20);

    printf("�rvore em pr�-ordem: ");
    imprimir_arvore(raiz);
    printf("\n");

    printf("Altura da �rvore: %d\n", altura(raiz));
    printf("Total de n�s: %d\n", contar_nos(raiz));
    printf("Total de folhas: %d\n", contar_folhas(raiz));

    liberar_arvore(raiz);
    return 0;
}
