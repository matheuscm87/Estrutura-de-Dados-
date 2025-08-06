#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void criarFila(Fila *f, int capacidade) {
    f->dados = (int *) malloc(capacidade * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;
}

void liberarFila(Fila *f) {
    free(f->dados);
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == f->capacidade;
}

int inserirFim(Fila *f, int valor) {
    if (filaCheia(f))
        return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
    return 1;
}

int removerInicio(Fila *f, int *valor) {
    if (filaVazia(f))
        return 0;

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    return 1;
}

int consultarInicio(Fila *f, int *valor) {
    if (filaVazia(f))
        return 0;

    *valor = f->dados[f->inicio];
    return 1;
}

void exibirFila(Fila *f) {
    printf("Fila: [");
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % f->capacidade;
        printf("%d", f->dados[idx]);
        if (i < f->tamanho - 1)
            printf(", ");
    }
    printf("]\n");
}
