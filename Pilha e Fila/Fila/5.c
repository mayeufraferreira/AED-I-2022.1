//Torre de Discos

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

no* enfileirar(struct no** inicio, struct no** fim, int num) {
    //Adiciona um elemento no fim da fila 
    fila novo = (fila) malloc(sizeof(no)); 
    if (*fim == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->proximo = novo;
        *fim = novo;
    }
    return novo;
}

fila desenfileirar(struct no** inicio, struct no** fim) {
    //Retira um elemento do início da fila 
    struct no* aux = *inicio;
    int valor = aux->valor;
    *inicio = (*inicio)->proximo;
    if (*inicio == NULL)
        *fim = NULL;
    free(aux);
    return *inicio;
}

int peek (fila f) {
    //Consulta o valor do primeiro elemento da fila, mas não remove.
    return f->valor;
}

void disco (int num, int* tamanhos) {
    no* inicio = NULL;
    no* fim = NULL;

    for (int i = 0; i < num; i++) {
        enfileirar(&inicio, &fim, tamanhos[i]);
        printf("Dia %d: ", i + 1);
        while (!isEmpty(inicio)) {
            int disco = peek(inicio);
            desenfileirar(&inicio, &fim);
            printf("%d ", disco);
            for (int j = i + 1; j < num; j++) {
                if (tamanhos[j] > disco)
                    enfileirar(&inicio, &fim, tamanhos[j]);
            }
        }
        printf("\n");
    }
}

void main () {
    int num;
    printf("Informe o numero total de discos: ");
    scanf("%d", &num);

    int* tamanhos = (int*)malloc(num * sizeof(int));
    printf("Informe os tamanhos dos discos: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &tamanhos[i]);
    }
        
    disco(num, tamanhos);
    free(tamanhos);
}