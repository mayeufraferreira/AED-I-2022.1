//Escreva uma função que receba duas filas (L1 e L2) e intercala os seus valores, gerando uma terceira fila, L3.
//Exemplo:
//L1: a1, a2, a3, a4
//L2: b1, b2
//Saída: L3: a1, b1, a2, b2, a3, a4

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no;

typedef no* fila;

fila enfileirar(fila f, int num) {
    //Adiciona um elemento no fim da fila 
    fila aux = f;
    if(f == NULL) {
        fila novo = (fila) malloc(sizeof(no)); 
        novo->valor = num;
        novo->proximo = f;
        return novo;
    }

    while(aux->proximo != NULL) {
        aux = aux->proximo;
    }
    
    fila novo = (fila) malloc(sizeof(no)); 
    novo->valor = num;
    novo->proximo = NULL;

    aux->proximo = novo;
    return f;
}

fila desenfileirar(fila f) {
    //Retira um elemento do início da fila 
    if(f == NULL)
        return NULL;
    fila aux = f->proximo;
    free(f);
    return aux;
}

void intercalar(fila L1, fila L2, fila *L3) {
    //função que intercala as duas filas e enfileira da terceira fila
    fila aux1 = L1;
    fila aux2 = L2;
    
    while (aux1 != NULL && aux2 != NULL) {
        *L3 = enfileirar(*L3, aux1->valor);
        *L3 = enfileirar(*L3, aux2->valor);
        aux1 = aux1->proximo;
        aux2 = aux2->proximo;
    }
    
    while (aux1 != NULL) {
        *L3 = enfileirar(*L3, aux1->valor);
        aux1 = aux1->proximo;
    }
    
    while (aux2 != NULL) {
        *L3 = enfileirar(*L3, aux2->valor);
        aux2 = aux2->proximo;
    }
}

void exibir(fila f) {
    fila aux = f;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void main () {
    //teste do programa
    fila L1 = NULL;
    fila L2 = NULL;
    fila L3 = NULL;
    
    L1 = enfileirar(L1, 1);
    L1 = enfileirar(L1, 3);
    L2 = enfileirar(L2, 2);
    L2 = enfileirar(L2, 4);
    intercalar(L1, L2, &L3);
    exibir(L3);
}
