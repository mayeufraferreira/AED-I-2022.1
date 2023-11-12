//Considerando as funções na tabela anterior, implemente uma fila que armazena números inteiros,
//utilizando a representação sequencial. Faça uma função main para testar o funcionamento da fila.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct fila {
    int elementos[MAX];
    int particao;
};

void inicializar(struct fila *f) {
    f->particao = 0;
}


int enfileirar (struct fila *f, int num) {
    //Adiciona um elemento no fim da fila
    if(f->particao < MAX) {
        f->elementos[f->particao] = num;
        f->particao++;
        return 1;
    } else {
        return 0;
    }
}

int desenfileirar (struct fila *f) {
    //Retira um elemento do início da fila
    int i;
    for (i = 0; i < f->particao - 1; i++) {
        f->elementos[i] = f->elementos[i + 1];
    }
    f->particao--;
    return 1;
}

int peek (struct fila *f) {
    //Consulta o valor do primeiro elemento da fila, mas não remove.
    return f->elementos[0];
}

int isEmpty (struct fila *f) {
    //Retorna 1 caso a fila esteja vazia e 0 em caso contrário.
    if (f->particao == 0) {
        return 1; 
    } else {
        return 0;
    }
}

void main() {

    //teste de funcionamento da fila

    struct fila *f1;
    f1 = (struct fila *) malloc(sizeof(struct fila));
    inicializar(f1);

    //enfileirando elementos
    enfileirar(f1, 1);
    enfileirar(f1, 2);
    enfileirar(f1, 3);

    //exibindo o primeiro elemento da fila
    int prim1 = peek(f1);
    printf("%d\n", prim1); //deve exibir o número 1, pois foi o primeiro número inserido

    //removendo o primeiro elemento da fila
    desenfileirar(f1);

    //exibindo o primeiro elemento atualizado da fila
    int prim2 = peek(f1);
    printf("%d\n", prim2);

    //esvaziando a fila
    desenfileirar(f1);
    desenfileirar(f1);

    //testando se a função está vazia
    int teste = isEmpty(f1);
    printf("%d\n", teste); //deve retornar 1 pois a fila foi esvaziada
}
