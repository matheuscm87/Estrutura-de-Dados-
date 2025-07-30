#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void exibir_menu() {
    printf("\n------ MENU LISTA ENCADEADA ------\n\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Obter valor de uma posicao\n");
    printf("4. Modificar valor de uma posicao\n");
    printf("5. Imprimir lista\n");
    printf("6. Verificar se a lista esta vazia\n");
    printf("7. Ver tamanho da lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Lista* lista = criar_lista();
    int opcao, posicao, valor;

    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a posicao para insercao (comecando do 1): ");
                scanf("%d", &posicao);
                printf("Informe o valor a ser inserido: ");
                scanf("%d", &valor);
                if (inserir_elemento(lista, posicao, valor))
                    printf("Elemento inserido com sucesso\n");
                else
                    printf("Erro ao inserir elemento (POSICAO INVALIDA).\n");
                break;

            case 2:
                printf("Informe a posicao do elemento a remover: ");
                scanf("%d", &posicao);
                if (remover_elemento(lista, posicao))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover elemento (POSICAO INVALIDA)\n");
                break;

            case 3:
                printf("Informe a posicao do elemento a consultar: ");
                scanf("%d", &posicao);
                if (obter_elemento(lista, posicao, &valor))
                    printf("Valor na posicao %d: %d\n", posicao, valor);
                else
                    printf("POSICAO INVALIDA\n");
                break;

            case 4:
                printf("Informe a posicao do elemento a modificar: ");
                scanf("%d", &posicao);
                printf("Informe o novo valor: ");
                scanf("%d", &valor);
                if (modificar_elemento(lista, posicao, valor))
                    printf("Valor modificado com sucesso!\n");
                else
                    printf("Erro ao modificar valor (POSICAO INVALIDA).\n");
                break;

            case 5:
                imprimir_lista(lista);
                break;

            case 6:
                if (lista_vazia(lista))
                    printf("A lista esta vazia.\n");
                else
                    printf("A lista NAO esta vazia.\n");
                break;

            case 7:
                printf("Tamanho atual da lista: %d\n", tamanho_lista(lista));
                break;

            case 0:
                printf("Saindo....\n");
                break;

            default:
                printf("POSICAO INVALIDA\n");
        }

    } while (opcao != 0);

    liberar_lista(lista);
    return 0;
}
