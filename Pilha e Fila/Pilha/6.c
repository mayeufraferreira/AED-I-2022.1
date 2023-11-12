//Pilha de Chocolate

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

void pop (struct pilha *p) {
    //Retira um elemento do topo da pilha (remover do fim)
    p->particao--;
}

int top (struct pilha *p) {
    //Consulta o valor no topo da pilha, mas não remove.
    return p->topo;
}

int isEmpty (struct pilha *p) {
    //Retorna 1 caso a pilha esteja vazia e 0 em caso contrário.
    if (p->topo == 0) {
        return 1; 
    } else {
        return 0;
    }
}

void solve (int N, int *c) {
    struct pilha *p;
    p = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p);
    int i;

    for (i=0; i<N; i++) {
        if (c[i] == 0) {
            if (top >= 0) {
                printf("%d ", p->topo);
                pop(p);
            }
        } else {
            push(p, c[i]);
            p->topo = c[i];
        }
    }
}

void main () {
    struct pilha *p1;
    p1 = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p1);
    int i, N;
    printf("Insira a quantidade de minutos: ");
    scanf("%d", &N);
    int c[N];
    for(i=0; i < N; i++) {
        scanf("%d", &c[i]);
    }
    solve(N, c);
    int topo = top(p1);
    printf("%d", topo);
    free(p1);
}
