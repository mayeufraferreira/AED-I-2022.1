//Escreva um programa COMPUTACIONALMENTE EFICIENTE que acumula n valores da sequência de Fibonacci em uma pilha. 
//Observação: Não utilize função recursiva e evite cálculos epetitivos.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct pilha {
    int elementos[MAX];
    int topo;
    int particao;

};

void inicializar(struct pilha *p) {
    p->particao = 0;
}

int push (struct pilha *p, int num) {
    //Insere um elemento no topo da pilha (inserir no fim)
    if(p->particao < MAX) {
        p->elementos[p->particao] = num;
        p->particao++;
        return 1;
    } else {
        return 0;
    }
}

int pop (struct pilha *p) {
    //Retira um elemento do topo da pilha (remover do fim)
    p->particao--;
    return 0;
}

int top (struct pilha *p) {
    //Consulta o valor no topo da pilha, mas não remove.
    return p->elementos[p->particao - 1];
}

void sequencia (struct pilha *p, int num) {
    //Função que empilha os números da sequência
    inicializar(p);
    int i, num1 = 0, num2 = 1, aux = num1;
    push(p, num1);
    for (i = 0; i < num; i++) {
        aux = num1 + num2;
        push(p, aux);
        num1 = num2;
        num2 = aux;
    }
}

void main () {
    //Implementação e leitura do número pelo teclado
    struct pilha *p1;
    p1 = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p1);
    int i, n;
    printf("Quantos valores da sequencia de Fibonacci voce deseja acumular? ");
    scanf("%d", &n);
    sequencia(p1, n);
    for (i = 0; i < n; i++) {
        printf("%d \n", top(p1));
        pop(p1);
    }

    free(p1);
}
