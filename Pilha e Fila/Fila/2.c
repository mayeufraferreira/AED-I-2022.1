//Implemente uma fila que armazena números inteiros,
//utilizando a representação encadeada. Faça uma função main para testar o funcionamento da fila.

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

void main() {

    //teste de funcionamento da fila
    fila f1 = NULL;

    //enfileirando os itens
    f1 = enfileirar(f1, 1);
    f1 = enfileirar(f1, 2);    
    f1 = enfileirar(f1, 3);

    //exibindo o primeiro elemento
    int topo1 = peek(f1);
    printf("%d\n", topo1); //deve exibir 1
    
    f1 = desenfileirar(f1); //tira o primeiro elemento que foi enfileirado

    //exibindo o primeiro elemento
    int topo2 = peek(f1);
    printf("%d\n", topo2); //deve exibir 2, visto que o 1 foi desenfileirado

    f1 = desenfileirar(f1);
    f1 = desenfileirar(f1);

    //testando se a fila está vazia
    int vazio = isEmpty(f1);
    printf("%d\n", vazio); //deve exibir 1, visto que a fila foi esvaziada
}
