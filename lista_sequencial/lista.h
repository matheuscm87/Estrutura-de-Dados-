#ifndef LISTA_H
#define LISTA_H

#define MAX 7

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

void criarLista(Lista *l);
int listaVazia(Lista *l);
int listaCheia(Lista *l);
int obterTamanho(Lista *l);
int obterElemento(Lista *l, int pos, int *valor);
int modificarElemento(Lista *l, int pos, int valor);
int inserirElemento(Lista *l, int pos, int valor);
int removerElemento(Lista *l, int pos);
void exibirLista(Lista *l);


#endif