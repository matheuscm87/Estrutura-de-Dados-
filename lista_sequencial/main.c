#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu() {
    printf("----- MENU ----- \n\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Obter elemento de uma posicao\n");
    printf("4. Modificar elemento de uma posicao\n");
    printf("5. Mostrar tamanho da lista\n");
    printf("6. Verificar se a lista esta vazia\n");
    printf("7. Verificar se a lista esta cheia\n");
    printf("8. Exibir todos os elementos da lista\n"); 
    printf("0. Sair\n\n");
    printf("Escolha uma opcao: ");
}


int main() {
    Lista l;
    criarLista(&l);

    int opcao, pos, valor;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a posicao para inserir (1 a %d): ", l.tamanho + 1);
                scanf("%d", &pos);
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (inserirElemento(&l, pos, valor))
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir elemento (POSICAO LISTA ou LISTA CHEIA).\n");
                break;

            case 2:
                printf("Digite a posicao para remover (1 a %d): ", l.tamanho);
                scanf("%d", &pos);
                if (removerElemento(&l, pos))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover elemento (POSICAO INVALIDA ou LISTA VAZIA).\n");
                break;

            case 3:
                printf("Digite a posicao para obter o valor: ");
                scanf("%d", &pos);
                if (obterElemento(&l, pos, &valor))
                    printf("Valor da posicao %d: %d\n", pos, valor);
                else
                    printf("POSICAO INVALIDA!\n");
                break;

            case 4:
                printf("Digite a posicao para modificar: ");
                scanf("%d", &pos);
                printf("Digite o novo valor: ");
                scanf("%d", &valor);
                if (modificarElemento(&l, pos, valor))
                    printf("Valor da posicao %d modificado corretamente!\n", pos);
                else
                    printf("POSICAO INVALIDA!\n");
                break;

            case 5:
                printf("Tamanho da lista: %d\n", obterTamanho(&l));
                break;

            case 6:
                if (listaVazia(&l))
                    printf("A lista esta vazia.\n");
                else
                    printf("A lista nao esta vazia.\n");
                break;

            case 7:
                if (listaCheia(&l))
                    printf("A lista esta cheia.\n");
                else
                    printf("A lista nao esta cheia.\n");
                break;

            case 8:
                exibirLista(&l);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("OPCAO INVALIDA\n");
        }

    } while (opcao != 0);

    return 0;
}
