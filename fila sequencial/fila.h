#ifndef FILA_H
#define FILA_H

typedef struct {
    int *dados;       
    int inicio;       
    int fim;          
    int tamanho;      
    int capacidade;   
} Fila;

void criarFila(Fila *f, int capacidade);
void liberarFila(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
int inserirFim(Fila *f, int valor);
int removerInicio(Fila *f, int *valor);
int consultarInicio(Fila *f, int *valor);
void exibirFila(Fila *f);

#endif
