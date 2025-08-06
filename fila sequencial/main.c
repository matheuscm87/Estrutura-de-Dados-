#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu() {
    printf("\n===== MENU =====\n");
    printf("1. Inserir no fim da fila\n");
    printf("2. Remover do início da fila\n");
    printf("3. Consultar início da fila\n");
    printf("4. Verificar se a fila está vazia\n");
    printf("5. Verificar se a fila está cheia\n");
    printf("6. Exibir todos os elementos da fila\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Fila f;
    int capacidade;

    printf("Digite o tamanho da fila: ");
    scanf("%d", &capacidade);
    criarFila(&f, capacidade);

    int opcao, valor;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (inserirFim(&f, valor))
                    printf("Valor inserido com sucesso.\n");
                else
                    printf("A FILA ESTÁ CHEIA!!!\n");
                break;

            case 2:
                if (removerInicio(&f, &valor))
                    printf("Valor removido: %d\n", valor);
                else
                    printf("A FILA ESTÁ VAZIA!!!\n");
                break;

            case 3:
                if (consultarInicio(&f, &valor))
                    printf("Início da fila: %d\n", valor);
                else
                    printf("A FILA ESTÁ VAZIA!!!\n");
                break;

            case 4:
                printf(filaVazia(&f) ? "A fila está vazia.\n" : "A fila NÃO está vazia.\n");
                break;

            case 5:
                printf(filaCheia(&f) ? "A fila está cheia.\n" : "A fila NÃO está cheia.\n");
                break;

            case 6:
                exibirFila(&f);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    liberarFila(&f);
    return 0;
}
