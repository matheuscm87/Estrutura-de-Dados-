#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Lista;

// Operações da lista
Lista* criar_lista();
int lista_vazia(Lista* lista);
int tamanho_lista(Lista* lista);
int obter_elemento(Lista* lista, int posicao, int* valor);
int modificar_elemento(Lista* lista, int posicao, int novo_valor);
int inserir_elemento(Lista* lista, int posicao, int valor);
int remover_elemento(Lista* lista, int posicao);
void imprimir_lista(Lista* lista);
void liberar_lista(Lista* lista);

#endif
