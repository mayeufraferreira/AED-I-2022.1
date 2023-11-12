#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"
#include<math.h>

lista inserirInicio(lista l, int valor) {
    //Opção 1
    //Recebe como parâmetros um número inteiro e um ponteiro para uma
    //lista encadeada, retorna o ponteiro para a cabeça da lista modificada.
    
    lista novo = (lista) malloc(sizeof(no)); 
    novo->valor = valor;
    novo->proximo = l;
    return novo;
}

lista inserirFim(lista l, int valor) {
    //Opção 2
    //Recebe como parâmetros um número inteiro e um ponteiro para lista encadeada, 
    //retorna o ponteiro para a cabeça da lista modificada.
    
    lista aux = l;
    if(l == NULL) {
        return inserirInicio(l, valor);
    }

    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    
    lista novo = (lista) malloc(sizeof(no)); 
    novo->valor = valor;
    novo->proximo = NULL;

    aux->proximo = novo;
    return l;
}

lista inserirPosicao (lista l, int valor, int posicao) {
    //Opção 3
    //Recebe como parâmetros um número inteiro(valor), um número
    //inteiro (posição), e um ponteiro para lista encadeada, retorna o
    //ponteiro para a cabeça da lista modificada.
    //Se a posição passada como parâmetro for maior do que a quantidade de elementos
    //contida na lista, o comportamento desta função se iguala ao inserirFim.
    
    lista novo = (lista) malloc(sizeof(no)); 
    
    if (posicao == 0) { //caso a posicao escolhida seja a primeira, chama a função inserir no início 
        inserirInicio(l, valor);
    }

    no *atual = l; //define o começo da lista para começar a percorrer
    int contador = 0; 

    while(atual != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }

    if (posicao > contador) { //laço que chama a função inserirFim caso a posição passada seja maior que a quantidade de elementos na lista
        inserirFim(l, valor);
    } else {
        no* proximo = atual->proximo;
        novo->valor = valor;
        novo->proximo = proximo;
        atual->proximo = novo;
    }
    
    return l;
}

lista inserirOrdem (lista l, int valor) {
    //Opção 4
    //Recebe como parâmetros um número inteiro(valor) e um ponteiro para
    //lista encadeada ORDENADA, retorna o ponteiro para a cabeça da lista
    //modificada. Após a execução desta função, a lista deve permanecer ordenada.
    
    lista novo = (lista) malloc(sizeof(no));

    if (l == NULL || valor < l->valor) { //se a lista estiver vazia ou o valor for menor que o do início da lista, chama a função inserirInicio
        inserirInicio(l, valor);
        return l;
    }

    no* atual = l;

    while(atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    no* proximo = atual->proximo;
    novo->valor = valor;
    novo->proximo = proximo;
    atual->proximo = novo;

    return l;
}

void exibir (lista l) {
    //Opção 5
    //Imprime todos os elementos da lista com os valores entre colchetes.
    
    lista aux = l;
    while(aux != NULL) {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void reverso (lista l) {
    //Opção 6
    //Imprime todos os elementos da lista, em ordem reversa, com os valores entre colchetes.
    
    if(l == NULL) {
        printf("\n");
        return ;
    }
    reverso(l->proximo);
    printf("[%d]", l->valor);
    printf("\n");
}

lista removerInicio (lista l) {
    //Opção 7
    //Recebe como parâmetro um ponteiro para uma lista encadeada,
    //retorna o ponteiro para a cabeça da lista modificada. Todos os
    //números existentes na lista devem ser deslocados à esquerda. Se a lista
    //passada estiver vazia, a função retorna uma lista vazia.
    
    if(l==NULL)
        return NULL;
    lista aux = l->proximo;
    free(l);
    return aux;
}

lista removerFim (lista l) {
    //Opção 8
    //Recebe como parâmetro um ponteiro para uma lista encadeada,
    //retorna o ponteiro para a cabeça da lista modificada. Se a lista passada
    //estiver vazia, a função retorna uma lista vazia.
    
    if(l == NULL)
        return NULL;

    if(l->proximo == NULL)
       return removerInicio(l);

    lista aux = l;
    while(aux->proximo->proximo != NULL) {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
    return l;
}

lista removerPosicao (lista l, int posicao) {
    //Opção 9
    //Recebe como parâmetros um número inteiro(posição) e um ponteiro
    //para uma lista encadeada, retorna o ponteiro para a cabeça da lista
    //modificada. Se a posição for inválida(maior que a quantidade de elementos) a função deve retornar a lista inalterada.

    lista novo = (lista) malloc(sizeof(no)); //alocação do espaço para o novo nó
    
    if (posicao == 0) { //caso a posicao escolhida seja a primeira, chama a função remover no início 
        removerInicio(l);
    }

    no *atual = l; //define o começo da lista para começar a percorrer
    int contador = 0; 

    while(atual != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }

    if (atual == NULL || atual->proximo == NULL) { //retorna a lista inalterada caso a posição passada seja maior que a quantidade de elementos na lista
        return l;
    } else {
        no* proximo = atual->proximo; 
        atual->proximo = proximo->proximo; 
        free(proximo); 
        return l;
    }  
}

lista removerValor(lista l, int valor) {
    //Opção 10
    //Recebe como parâmetros um número inteiro(valor) e um ponteiro para
    //uma lista encadeada, retorna o ponteiro para a cabeça da lista
    //modificada. Caso o valor passado como parâmetro não exista, a função retorna a lista inalterada.

    lista novo = (lista) malloc(sizeof(no)); 

    no* atual = l; //definição do começo da lista
    no* aux = NULL; //auxiliar que guarda o anterior do nó atual

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (aux == NULL) { //verifica se está no início da lista
                l = atual->proximo;
            } else {
                aux->proximo = atual->proximo;
            }
            free(atual);
            return l; 
        }
        aux = atual;
        atual = atual->proximo;
    }
    return l;
}

int procurar (lista l, int n) {
    //Opção 11
    //Recebe como parâmetros um número inteiro n e um ponteiro para uma lista encadeada, 
    //retorna um ponteiro para o nó que armazena o valor n. Caso n não exista, a função deve retornar o valor NULL.

    lista novo = (lista) malloc(sizeof(no)); 

    no* atual = l; //início da lista
    int posicao = 0; //contador que guardará a posição do valor informado

    while (atual != NULL) {
        if (atual->valor == n) {
            return posicao; 
        } 
        atual = atual->proximo;
        posicao++;
    }
    
    return -1;
}

int somatorio (lista l) {
    //Opção 12
    //Recebe como parâmetro o ponteiro para uma lista encadeada e retorna o somatório 
    //de todos os valores armazenados na lista.

    lista novo = (lista) malloc(sizeof(no));

    no* atual = l;
    int soma = 0; //incremento que será somado a cada valor novo

    while (atual != NULL) {
        soma += atual->valor;
        atual = atual->proximo;
    }

    return soma;
}

int tamanho (lista l) {
    //Opção 13
    //Recebe como parâmetro o ponteiro para uma lista encadeada e retorna a quantidade de elementos 
    //armazenados na lista.

    lista novo = (lista) malloc(sizeof(no)); 

    no* atual = l;
    int tamanho = 0; //contador que guardará o tamanho final da lista

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    return tamanho;
}

lista quadrado (lista l) {
    //Opção 14
    //Recebe como parâmetro o ponteiro para uma lista encadeada e modifica a lista, 
    //elevando ao quadrado todos os seus elementos.

    lista novo = (lista) malloc(sizeof(no)); //alocação do espaço para o novo nó
    no* atual = l;

    while (atual != NULL) {
        atual->valor = pow(atual->valor, 2);
        atual = atual->proximo;
    }

    return l;
}

int qtdPrimo (lista l) {
    //Opção 15
    //Recebe como parâmetro o ponteiro para uma lista encadeada e retorna a quantidade de números primos armazenados na lista.

    lista novo = (lista) malloc(sizeof(no)); 
    no* atual = l;
    int i, primo = 1, qntd = 0; //qntd é o contador dos números que são primos
    //i é usado para percorrer a lista e verificar a condição de primo

    while (atual != NULL) {
        for (i=2; i<=atual->valor; i++) {
            if (atual->valor % i == 0) {
                primo = 0; //primo é dado como falso a partir do momento que o número possuir divisores além do 1 e dele mesmo
            }
        }

        if (primo) {
            qntd++;
        }

        atual = atual->proximo;
    }

    return qntd;
}
