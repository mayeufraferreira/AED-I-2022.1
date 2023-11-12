//Biblioteca de Alice
//o programa recebe um string e remove suas barras e os empilha para inverter sua ordem desempilhando

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct pilha {
    char elementos[MAX];
    char topo;
    int particao;
};

void inicializar(struct pilha *p) {
    p->particao = 0;
}

int push (struct pilha *p, int letra) {
    //Insere um elemento no topo da pilha (inserir no fim)
    if(p->particao < MAX) {
        p->elementos[p->particao] = letra;
        p->particao++;
        return 1;
    } else {
        return 0;
    }
}

void pop (struct pilha *p) {
    //Retira um elemento do topo da pilha (remover do fim)
    p->particao--;
}

void inverter (struct pilha *p) {
    //função que inverte os livros, desempilhando os itens da pilha recebida
    struct pilha *aux;
    aux = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(aux);

    while (p->particao >= 0) {
        push(aux, p->elementos[p->particao - 1]);
        pop(p);
    }

    while (aux->particao >= 0) {
        push(p, aux->elementos[aux->particao - 1]);
        pop(aux);
    }

    free(aux);
}

void main() {
    char biblioteca[MAX];
    printf("Insira sua string: ");
    scanf("%s", biblioteca);
    struct pilha *p1;
    p1 = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p1);
    inverter(p1);
    int i;
    for (i = 0; i < p1->particao; i++) {
        printf("%c", p1->elementos[i]);
    }
    free(p1);
}
