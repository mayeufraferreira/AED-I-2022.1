//Considerando as funções na tabela anterior, implemente uma pilha que armazena números inteiros, 
//utilizando a representação encadeada. Faça uma função main para testar o funcionamento da pilha.

#include<stdio.h>
#include<stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no;

typedef no* pilha;

pilha push (pilha p, int num) {
    //Insere um elemento no topo da pilha
    pilha novo = (pilha) malloc(sizeof(no)); 
    novo->valor = num;
    novo->proximo = p;
    return novo;
}

pilha pop (pilha p) {
    //Retira um elemento do topo da pilha
    pilha aux = p->proximo;
    free(p);
    return aux;
}

int top (pilha p) {
    //Consulta o valor no topo da pilha, mas não remove.
    return p->valor;
}

int isEmpty (pilha p) {
    //Retorna 1 caso a pilha esteja vazia e 0 em caso contrário.
    if (p == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void main () {

    //teste de funcionamento da pilha

    pilha p1 = NULL;

    //empilhando elementos
    p1 = push(p1, 1);
    p1 = push(p1, 2);
    p1 = push(p1, 3);
    
    //exibindo o topo da pilha
    int topo1 = top(p1);
    printf("%d", topo1); //deve exibir o número 3, pois foi o último número inserido

    //removendo o topo da pilha
    p1 = pop(p1);

    //exibindo o topo atualizado da pilha
    int topo2 = top(p1);
    printf("%d\n", topo2); //deve exibir o número 2, pois o topo que era 3 foi removido

    //removendo o topo duas vezes para esvaziar a pilha
    p1 = pop(p1);
    p1 = pop(p1);

    //testando a função para saber se a pilha está vazia
    int teste = isEmpty(p1);
    printf("%d\n", teste); //deve exibir o número 1, pois a pilha foi esvaziada

    free(p1);
}
