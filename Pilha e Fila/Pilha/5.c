//Escreva um programa que recebe um string e determina se o string digitado é uma palíndromo.
//Ex: anilina, ovo, osso, radar, sopapos, socos.
//Obs: Acentos e espaços em branco devem ser desconsiderados.
//Ex: A mãe te ama; luz azul; o galo ama o lago.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000

struct pilha {
    char elementos[MAX];
    char topo;
    int particao;
};

void inicializar(struct pilha *p) {
    p->topo = 0;
    p->particao = 0;
}

int push (struct pilha *p, char letra) {
    //Insere um elemento no topo da pilha (inserir no fim)
    if(p->particao < MAX) {
        p->elementos[p->particao] = letra;
        p->particao++;
        p->topo = letra;
        return 1;
    } else {
        return 0;
    }
}

int pop (struct pilha *p) {
    //Retira um elemento do topo da pilha (remover do fim)
    p->topo = p->elementos[p->particao - 2];
    return p->particao--;
}

char top (struct pilha *p) {
    //Consulta o valor no topo da pilha, mas não remove.
    return p->topo;
}

void exibir(struct pilha *p){
    int i;
    for(i=0; i < p->particao; i++) {
        printf("[%c]", p->elementos[i]);
    }
    printf("\n");
}

void palindromo (char *s) {
    int i, tamanho = strlen(s);
    int j =0;
    char nome[100] = "";
    char string[100] = "";
    struct pilha *p;
    p = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p);

    for (i=0; i<tamanho; i++) {
        if (!isspace(s[i])) {
            push(p, s[i]);
            string[j] = s[i];
            j++;
        }
    }

    for (i=0; p->particao>0; i++) {
        nome[i] = top(p);
        pop(p);
    }
    
    if (strcmp(nome, string) == 0) {
        printf("E palindromo");
    } else {
        printf("Nao e palindromo");
    }
} 

void main () {
    char s1[MAX];
    printf("Digite sua string: ");
    fgets(s1, MAX, stdin);
    palindromo(s1);
    free(s1);
}
