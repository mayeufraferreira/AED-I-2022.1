//Escreve um programa EFICIENTE que recebe um número inteiro n e imprime os números
//binários entre 1 e n. Exemplo: para a entrada n=16, a saída deve ser: 1 10 11 100 101 110 111 1000
//1001 1010 1011 1100 1101 1110 1111 10000

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no;

typedef no* fila;

int isEmpty(fila f) {
    //Retorna 1 caso a fila esteja vazia e 0 em caso contrário.
    if (f == NULL) {
        return 1;
    } else {
        return 0;
    }
}

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

int peek (fila f) {
    //Consulta o valor do primeiro elemento da fila, mas não remove.
    return f->valor;
}

fila binarios(fila f, int n) {
    //calcula os números binarios e armazena em uma fila
    for (int i = 1; i <= n; i++) {
        int num = i;
        int binario = 0;
        int base = 1;

        while (num > 0) {
            binario += (num % 2) * base;
            num /= 2;
            base *= 10;
        }

        f = enfileirar(f, binario);
    }

    return f;
}

void exibir (fila f) {
    fila aux = f;
    while(aux != NULL) {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }
    printf("\n");
}

void main() {
    fila f1 = NULL;
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    f1 = binarios(f1, n);
    exibir(f1);
}
