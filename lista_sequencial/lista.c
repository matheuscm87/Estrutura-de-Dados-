#include "lista.h"
#include <stdio.h> 

void criarLista(Lista *l) {
    l->tamanho = 0;
}

int listaVazia(Lista *l) {
    return l->tamanho == 0;
}

int listaCheia(Lista *l) {
    return l->tamanho == MAX;
}

int obterTamanho(Lista *l) {
    return l->tamanho;
}

int obterElemento(Lista *l, int pos, int *valor) {
    if (pos < 1 || pos > l->tamanho)
        return 0;
    *valor = l->dados[pos - 1];
    return 1;
}

int modificarElemento(Lista *l, int pos, int valor) {
    if (pos < 1 || pos > l->tamanho)
        return 0;
    l->dados[pos - 1] = valor;
    return 1;
}

int inserirElemento(Lista *l, int pos, int valor) {
    if (listaCheia(l) || pos < 1 || pos > l->tamanho + 1)
        return 0;
    for (int i = l->tamanho; i >= pos; i--)
        l->dados[i] = l->dados[i - 1];
    l->dados[pos - 1] = valor;
    l->tamanho++;
    return 1;
}

int removerElemento(Lista *l, int pos) {
    if (listaVazia(l) || pos < 1 || pos > l->tamanho)
        return 0;
    for (int i = pos - 1; i < l->tamanho - 1; i++)
        l->dados[i] = l->dados[i + 1];
    l->tamanho--;
    return 1;
}

void exibirLista(Lista *l) {
    printf("Lista: [");
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d", l->dados[i]);
        if (i < l->tamanho - 1)
            printf(", ");
    }
    printf("]\n");
}
