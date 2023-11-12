//Considerando as funções na tabela anterior, implemente uma pilha que armazena números
//inteiros, utilizando a representação sequencial. Faça uma função main para testar o funcionamento da pilha.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct pilha {
    int elementos[MAX];
    int topo;
};

void inicializar(struct pilha *p) {
    p->topo = 0;
}

int push (struct pilha *p, int num) {
    //Insere um elemento no topo da pilha (inserir no fim)
    if(p->topo < MAX) {
        p->elementos[++p->topo] = num;
        return 1;
    } else {
        return 0;
    }
}

int pop (struct pilha *p) {
    //Retira um elemento do topo da pilha (remover do fim)
    p->topo--;
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

void main () {

    //teste de funcionamento da pilha

    struct pilha *p1;
    p1 = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p1);

    //empilhando elementos
    push(p1, 1);
    push(p1, 2);
    push(p1, 3);
    
    //exibindo o topo da pilha
    int topo1 = top(p1);
    printf("%d\n", topo1); //deve exibir o número 3, pois foi o último número inserido

    //removendo o topo da pilha
    pop(p1);

    //exibindo o topo atualizado da pilha
    int topo2 = top(p1);
    printf("%d\n", topo2); //deve exibir o número 2, pois o topo que era 3 foi removido

    //removendo o topo duas vezes para esvaziar a pilha
    pop(p1);
    pop(p1);

    //testando a função para saber se a pilha está vazia
    int teste = isEmpty(p1);
    printf("%d\n", teste); //deve exibir o número 1, pois a pilha foi esvaziada

    free(p1);
}
