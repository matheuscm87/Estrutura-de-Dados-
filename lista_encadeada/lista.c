#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criar_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

int lista_vazia(Lista* lista) {
    return (lista->tamanho == 0);
}

int tamanho_lista(Lista* lista) {
    return lista->tamanho;
}

int inserir_elemento(Lista* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho + 1) return 0;

    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return 0;

    novo->valor = valor;

    if (posicao == 1) {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        for (int i = 1; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    lista->tamanho++;
    return 1;
}

int remover_elemento(Lista* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) return 0;

    No* removido;
    if (posicao == 1) {
        removido = lista->inicio;
        lista->inicio = lista->inicio->proximo;
    } else {
        No* anterior = lista->inicio;
        for (int i = 1; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        removido = anterior->proximo;
        anterior->proximo = removido->proximo;
    }

    free(removido);
    lista->tamanho--;
    return 1;
}

int obter_elemento(Lista* lista, int posicao, int* valor) {
    if (posicao < 1 || posicao > lista->tamanho) return 0;

    No* atual = lista->inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }

    *valor = atual->valor;
    return 1;
}

int modificar_elemento(Lista* lista, int posicao, int novo_valor) {
    if (posicao < 1 || posicao > lista->tamanho) return 0;

    No* atual = lista->inicio;
    for (int i = 1; i < posicao; i++) {
        atual = atual->proximo;
    }

    atual->valor = novo_valor;
    return 1;
}

void imprimir_lista(Lista* lista) {
    No* atual = lista->inicio;
    printf("Lista: ");
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n\n");
}

void liberar_lista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}