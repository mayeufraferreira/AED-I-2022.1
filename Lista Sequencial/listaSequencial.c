#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listaSequencial.h"

#define MAX 1000

void inicializar(struct lista *l) {
    l->particao = 0;
}

int inserirInicio(struct lista *l, int valor) {
    //Opcao 1
    //Detalhes: Recebe como parametros um numero inteiro e um ponteiro para uma
    //lista sequencial, retorna o valor 0 ou 1, indicando se o numero foi
    //inserido com sucesso. Todos os numeros existentes na lista devem ser
    //deslocados a direita.
    int i;
    if(l->particao < MAX) {
        for(i=l->particao; i > 0; i--) {
            l->elementos[i] = l->elementos[i-1];
        }

        l->elementos[0] = valor;
        l->particao++;

        return 1;
    } else {
        return 0;
    }
}

int inserirFim(struct lista *l, int valor) {
    //Opcao 2
    //Detalhes: Recebe como parametros um numero inteiro e um ponteiro para lista
    //sequencial, retorna o valor 0 ou 1, indicando se o numero foi inserido
    //com sucesso.
    if(l->particao < MAX) {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    } else {
        return 0;
    }
}

int inserirPosicao(struct lista *l, int valor, int posicao) {
    //Opcao 3
    //Detalhes: Recebe como parametros um numero inteiro(valor), um numero
    //inteiro (posicao), e um ponteiro para lista sequencial, retorna o valor 0
    //ou 1, indicando se o numero foi inserido com sucesso. Todos os
    //numeros existentes na lista a partir da posicao passada como
    //parametro devem ser deslocados a direita.
    int i;
    if(l->particao < MAX) {
        for(i=l->particao; i >posicao; i--) {
        l->elementos[i] = l->elementos[i-1];
        }

        l->elementos[posicao] = valor;
        l->particao++;

        return 1;
    } else {
        return 0;
    }
}

int inserirOrdem(struct lista *l, int valor) {
    //Opcao 4
    //Recebe como parametros um numero inteiro(valor) e um ponteiro para
    //lista sequencial ORDENADA, retorna o valor 0 ou 1, indicando se o
    //numero foi inserido com sucesso. Apos a execucao desta funcao, a
    //lista deve permanecer ordenada.
    int i;
    if(l->particao < MAX) {
        l->elementos[l->particao] = valor;
        l->particao++;
    } 

    for (i = 0; i < l->particao; i++) {
        int aux = l->elementos[i], j = i - 1;
        while (j >= 0 && aux < l->elementos[j]) {
            l->elementos[j + 1] = l->elementos[j];
            j = j - 1;
        }
        l->elementos[j + 1] = aux;
    }
}

void exibir(struct lista *l){
    //Opcao 5
    //Detalhes: Imprime todos os elementos da lista com os valores entre colchetes
    int i;
    for(i=0; i < l->particao; i++) {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

void reverso(struct lista *l){
    //Opcao 6
    //Detalhes: Imprime todos os elementos da lista, em ordem reversa, com os valores entre colchetes.
    int i;
    for(i=l->particao - 1; i >= 0; i--) {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int removerInicio(struct lista *l) {
    //Opcao 7
    //Detalhes: Recebe como parametro um ponteiro para uma lista sequencial,
    //retorna o valor 0 ou 1, indicando se o numero foi removido com sucesso. 
    //Todos os numeros existentes na lista devem ser deslocados a esquerda.
    int i;
    for (i = 0; i < l->particao - 1; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }

    l->particao--;

    return 1;
}

int removerFim(struct lista *l) {
    //Opcao 8
    //Detalhes: Recebe como parâmetro um ponteiro para uma lista sequencial, retorna o valor 0 ou 1, 
    //indicando se o número foi removido com sucesso.
    l->particao--;
    return 1;
}

int removerPosicao(struct lista *l, int posicao) {
    //Opcao 9
    //Detalhes: Recebe como parametros um numero inteiro(posição) e um ponteiro para uma lista sequencial, 
    //retorna o valor 0 ou 1, indicando se o numero foi removido com sucesso. Todos os numeros existentes na
    //lista, a partir da posição passada como parâmetro, devem ser deslocados a esquerda.
    int i;
    if(l->particao < MAX) {
        for(i=l->particao; i > posicao; i--) {
        l->elementos[i] = l->elementos[i-1];
        }

        l->elementos[posicao] = l->elementos[posicao] + 1;
        l->particao--;

        return 1;
    } else {
        return 0;
    }
}

int removerValor(struct lista *l, int valor) {
    //Opcao 10
    //Detalhes: Recebe como parametros um numero inteiro(valor) e um ponteiro para uma lista sequencial, 
    //retorna o valor 0 ou 1, indicando se o numero foi removido com sucesso. 
    //Caso o valor passado como parametro exista, todos os numeros existentes na lista, 
    //a partir da sua posicao, devem ser deslocados a esquerda.
    int i, posicao;
    if(l->particao < MAX) {
        for(i=0; i < l->particao; i++) {
            if (l->elementos[i] == valor) {
                posicao = i;
            }
        }

        for (i = posicao; i < l->particao - 1; i++) {
            l->elementos[i] = l->elementos[i] + 1;
        }
        
        l->particao--;

        return 1;
    } else {
        return 0;
    }
}

int procurar(struct lista *l, int n) {
    //Opcao 11
    //Detalhes: Recebe como parametros um ponteiro para uma lista e um numero inteiro n e retorna a posicao 
    //na lista em que o valor n se encontra. Caso n nao exista, a funcao deve retornar o valor -1.
    int i;
    for(i = 0; i < l->particao; i++) {
        if (l->elementos[i] == n) {
            printf("O valor %d se encontra na posicao %d\n", n, i);
            return i;
        }
    }

    return -1;
}

int somatorio(struct lista *l) {
    //Opcao 12
    //Detalhes: Recebe como parametro o ponteiro para uma lista sequencial e retorna o somatorio de 
    //todos os valores armazenados na lista.
    int i, soma = 0;
    for (i=0; i < l->particao; i++) {
        soma = soma + l->elementos[i];
    }

    printf("Somatorio de todos os numeros da lista: %d\n", soma);
    return soma;
}

int tamanho(struct lista *l) {
    //Opcao 13
    //Detalhes: Recebe como parametro o ponteiro para uma lista sequencial e retorna 
    //a quantidade de elementos armazenados na lista.
    int i, qntd = 0;
    for (i=0; i < l->particao; i++) {
        qntd++;
    }

    printf("A lista possui %d elementos\n", qntd);
    return qntd;
}

int quadrado(struct lista *l) {
    //Opcao 14
    //Detalhes: Recebe como parametro o ponteiro para uma lista sequencial e modifica a lista, 
    //elevando ao quadrado todos os seus elementos.
    int i;
    for (i=0; i < l->particao; i++) {
        l->elementos[i] = pow(l->elementos[i], 2);
    }

    return 1;
}

int qtdPrimo(struct lista *l) {
    //Opcao 15
    //Detalhes: Recebe como parametro o ponteiro para uma lista sequencial e retorna a quantidade de 
    //numeros primos armazenados na lista. 
    int i, j, primo = 1, qntd = 0;
    for (i = 0; i < l->particao; i++) {
        for (j = 2; j < l->elementos[i]; j++) {
            if (l->elementos[i] % j == 0) {
                primo = 0; 
            }
        }
        
        if (primo) {
            qntd++;
        }
    }

    printf("A lista possui %d numeros primos\n", qntd);
    return qntd;
}
