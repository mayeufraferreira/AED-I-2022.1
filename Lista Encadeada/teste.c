#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(int argc, char *argv) {

    //teste interativo
    lista l1 = NULL;
    int escolha, opcao, valor, aux, numero, posicao;
    
    //preenchimento da lista recebendo entradas do teclado
    printf("Preencha sua lista: \n");
    printf("Primeiro valor: ");
    scanf("%d", &valor);
    l1 = inserirInicio(l1, valor); //insere o primeiro valor na lista
    printf("Deseja inserir outro numero na lista?\n");
    printf("1. Sim\n");
    printf("2. Nao\n");
    scanf("%d", &escolha);
    if (escolha > 2 || escolha < 1) {
        printf("Essa opcao nao existe, tente novamente\n");
        //contorna caso o usuário digite um número diferente dos disponíveis
    }

    //adiciona um número novo até o usuário escolher encerrar a lista
    while (escolha != 2) {
        printf("Insira o numero que voce quer inserir na lista: ");
        scanf("%d", &valor);
        l1 = inserirFim(l1, valor); 
        printf("Deseja inserir outro numero na lista?\n");
        printf("1. Sim\n");
        printf("2. Nao\n");
        scanf("%d", &escolha);
        if (escolha > 2 || escolha < 1) { //contorna caso o usuário digite um número diferente dos disponíveis
           printf("Essa opcao nao existe, tente novamente\n");
            ("Deseja inserir outro numero na lista?\n");
            printf("1. Sim\n");
            printf("2. Nao\n");
            scanf("%d", &escolha);
        }
    }
    
    //interação com o usuário que chama a função correspondente a opção escolhida
    printf("\nAgora escolha o que voce quer fazer com sua lista: \n");
    printf("1. Inserir um numero no inicio \n");
    printf("2. Inserir um numero no final \n");
    printf("3. Inserir um numero em uma posicao especifica \n");
    printf("4. Inserir um numero na lista ordenada mantendo a ordenacao \n");
    printf("5. Exibir sua lista \n");
    printf("6. Exibir sua lista em ordem inversa \n");
    printf("7. Remover o primeiro numero da lista \n");
    printf("8. Remover o ultimo numero da lista \n");
    printf("9. Remover numero em um posicao especifica \n");
    printf("10. Remover um valor especifico \n");
    printf("11. Saber a posicao de um valor especifico na lista \n");
    printf("12. Somatorio de todos os elementos da lista \n");
    printf("13. Quantidade de elementos na lista \n");
    printf("14. Elevar todos os numeros da lista ao quadrado \n");
    printf("15. Saber a quantidade de numeros primos que a lista possui \n");
    printf("99. Sair \n");
    scanf("%d", &opcao); 

    while (opcao) {
        switch (opcao) {
        case  1:
            printf("Digite o numero que voce quer inserir: ");
            scanf("%d", &numero);
            inserirInicio(l1, numero);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 2:
            printf("Digite o numero que voce quer inserir: ");
            scanf("%d", &numero);
            inserirFim(l1, numero);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 3:
            printf("Digite o numero e a posicao que voce quer o inserir: ");
            scanf("%d", &numero);
            scanf("%d", &posicao);
            inserirPosicao(l1, numero, posicao);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 4:
            printf("Digite o numero que voce quer inserir: ");
            scanf("%d", &numero);
            inserirOrdem(l1, numero);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 5:
            exibir(l1);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;
        
        case 6:
            reverso(l1);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 7:
            removerInicio(l1);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 8:
            removerFim(l1);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 9:
            printf("Digite a posicao do elemento que voce quer remover: ");
            scanf("%d", &posicao);
            removerPosicao(l1, posicao);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 10:
            printf("Digite o numero que voce quer remover: ");
            scanf("%d", &numero);
            removerValor(l1, numero);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 11:
            printf("Digite o numero que voce quer encontrar: ");
            scanf("%d", &numero);
            aux = procurar(l1, numero);
            printf("O número [%d] encontra-se na posição [%d]\n", numero, aux);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 12:
            aux = somatorio(l1);
            printf("A soma de todos os números da lista é [%d]\n", aux);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 13:
            aux = tamanho(l1);
            printf("A lista possui [%d] elementos\n", aux);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 14:
            quadrado(l1);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 15:
            aux = qtdPrimo(l1);
            printf("A lista possui [%d] números primos\n", aux);
            printf("Escolha outra opcao: ");
            scanf("%d", &opcao);
            break;

        case 99:
            free(l1);
            exit(0);
            break;

        default:
            printf("Essa opcao nao existe, tente novamente: ");
            scanf("%d", &opcao);
            break;
        }
    }
}
    