#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "locale.h"

// ============================================
// Estrutura do nó da árvore de expressão
// ============================================

typedef struct NoExpr {
    char operador;
    int valor;               // usado apenas se operador == '\0'
    struct NoExpr* esquerda;
    struct NoExpr* direita;
} NoExpr;

// ============================================
// Funções de utilidade
// ============================================

NoExpr* criar_no_valor(int valor) {
    NoExpr* novo = (NoExpr*) malloc(sizeof(NoExpr));
    novo->operador = '\0';
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

NoExpr* criar_no_operador(char operador, NoExpr* esquerda, NoExpr* direita) {
    NoExpr* novo = (NoExpr*) malloc(sizeof(NoExpr));
    novo->operador = operador;
    novo->valor = 0;
    novo->esquerda = esquerda;
    novo->direita = direita;
    return novo;
}

void liberar_arvore_expr(NoExpr* raiz) {
    if (raiz != NULL) {
        liberar_arvore_expr(raiz->esquerda);
        liberar_arvore_expr(raiz->direita);
        free(raiz);
    }
}

// ============================================
// Pilha de nós (para montar a árvore)
// ============================================

typedef struct Pilha {
    NoExpr* itens[100];
    int topo;
} Pilha;

void inicializar_pilha(Pilha* p) {
    p->topo = -1;
}

int pilha_vazia(Pilha* p) {
    return p->topo == -1;
}

void empilhar(Pilha* p, NoExpr* no) {
    if (p->topo < 99) {
        p->itens[++p->topo] = no;
    } else {
        printf("Erro: pilha cheia!\n");
        exit(1);
    }
}

NoExpr* desempilhar(Pilha* p) {
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo--];
}

// ============================================
// Construção da árvore a partir da expressão RPN
// ============================================

NoExpr* construir_arvore(char* expressao) {
    Pilha p;
    inicializar_pilha(&p);

    char* token = strtok(expressao, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            // É número
            empilhar(&p, criar_no_valor(atoi(token)));
        } else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            // É operador
            NoExpr* dir = desempilhar(&p);
            NoExpr* esq = desempilhar(&p);
            empilhar(&p, criar_no_operador(token[0], esq, dir));
        } else {
            printf("Token inválido: %s\n", token);
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    return desempilhar(&p); // raiz final
}

// ============================================
// Avaliação da expressão (pós-ordem)
// ============================================

int avaliar(NoExpr* raiz) {
    if (raiz == NULL)
        return 0;

    // Nó folha: número
    if (raiz->operador == '\0')
        return raiz->valor;

    int esq = avaliar(raiz->esquerda);
    int dir = avaliar(raiz->direita);

    switch (raiz->operador) {
        case '+': return esq + dir;
        case '-': return esq - dir;
        case '*': return esq * dir;
        case '/':
            if (dir == 0) {
                printf("Erro: divisão por zero!\n");
                exit(1);
            }
            return esq / dir;
        default:
            printf("Operador desconhecido: %c\n", raiz->operador);
            exit(1);
    }
}

#include <math.h>

#define MAX_LARGURA 200

void imprimir_nivel(NoExpr* raiz, int nivel, int pos, int largura, char tela[][MAX_LARGURA], int altura, int espacamento) {
    if (raiz == NULL || nivel >= altura)
        return;

    char texto[10];
    if (raiz->operador == '\0')
        sprintf(texto, "%d", raiz->valor);
    else
        sprintf(texto, "%c", raiz->operador);

    int meio = pos + largura / 2;
    int col = meio - (int)strlen(texto) / 2;

    // Desenha o valor ou operador
    for (int i = 0; i < (int)strlen(texto); i++) {
        if (col + i < MAX_LARGURA)
            tela[nivel * 2][col + i] = texto[i];
    }

    // Conexões visuais
    if (raiz->esquerda != NULL) {
        int esq = pos + largura / 4;
        tela[nivel * 2 + 1][esq + espacamento / 2] = '/';
        imprimir_nivel(raiz->esquerda, nivel + 1, pos, largura / 2, tela, altura, espacamento / 2);
    }

    if (raiz->direita != NULL) {
        int dir = pos + 3 * largura / 4;
        tela[nivel * 2 + 1][dir - espacamento / 2] = '\\';
        imprimir_nivel(raiz->direita, nivel + 1, pos + largura / 2, largura / 2, tela, altura, espacamento / 2);
    }
}

int calcular_altura(NoExpr* raiz) {
    if (raiz == NULL) return 0;
    int e = calcular_altura(raiz->esquerda);
    int d = calcular_altura(raiz->direita);
    return (e > d ? e : d) + 1;
}

void imprimir_arvore_expr(NoExpr* raiz) {
    if (raiz == NULL) {
        printf("(árvore vazia)\n");
        return;
    }

    int altura = calcular_altura(raiz);
    int largura_inicial = 8 * (int)pow(2, altura - 1); // Ajuste dinâmico
    if (largura_inicial > MAX_LARGURA) largura_inicial = MAX_LARGURA;

    char tela[altura * 2][MAX_LARGURA];

    // Limpa o "canvas"
    for (int i = 0; i < altura * 2; i++)
        for (int j = 0; j < MAX_LARGURA; j++)
            tela[i][j] = ' ';

    imprimir_nivel(raiz, 0, 0, largura_inicial, tela, altura, largura_inicial / 4);

    // Mostra a árvore
    printf("\n");
    for (int i = 0; i < altura * 2; i++) {
        tela[i][MAX_LARGURA - 1] = '\0';
        printf("%s\n", tela[i]);
    }
    printf("\n");
}



// ============================================
// Programa principal

int main() {
    setlocale(LC_ALL, "");

    char expressao[200];

    printf("Digite a expressão em notação pós-fixa (RPN): ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0'; // remove \n

    NoExpr* raiz = construir_arvore(expressao);

    printf("\nÁrvore construída:\n");
    imprimir_arvore_expr(raiz);

    int resultado = avaliar(raiz);
    printf("\nResultado: %d\n", resultado);

    liberar_arvore_expr(raiz);
    return 0;
}
