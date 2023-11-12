//Escreva um programa que recebe um string do teclado e determina se os parênteses, colchetes e
//chaves estão bem balanceados. Ex: 9 * { 10 + [2 / 3] + [ (-2) + (6 * 9 )] } / {-11}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

struct pilha {
    char elementos[MAX];
    char topo;
    int particao;
};

void inicializar(struct pilha *p) {
    p->particao = 0;
}

int push (struct pilha *p, char simbolo) {
    //Insere um elemento no topo da pilha (inserir no fim)
    if(p->particao < MAX) {
        p->elementos[p->particao] = simbolo;
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

char top (char *s) {
    //Consulta o valor no topo da pilha, mas não remove.
    struct pilha *p;
    p = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p);
    return p->elementos[p->topo];
}

int isEmpty (struct pilha *p) {
    //Retorna 1 caso a pilha esteja vazia e 0 em caso contrário.
    if (p->topo == 0) {
        return 1; 
    } else {
        return 0;
    }
}

int balanceamento (char *s) {
    //Analisa o balanceamento da expressão
    struct pilha *p;
    p = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p);
    int i, j;
    char topo = top(s);
    for (i=0; i < strlen(s); i++) {
        if ((isEmpty(p)) && (s[i] == '}' || s[i] == ']' || s[i] == ')')) {
            return 0;
        }
        
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            push(p, s[i]);
        }
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            if (topo == '{') {
                if (s[i] == '}') {
                    pop(p);
                } else {
                    return 0;
                }
            }
            
            if (topo == '[') {
                if (s[i] == ']') {
                    pop(p);
                } else {
                    return 0;
                }
            }

            if (topo == '(') {
                if (s[i] == ')') {
                    pop(p);
                } else {
                    return 0;
                }
            }
        } 
    }

    if (isEmpty(p) == 1) {
        return 1;
    } else if (isEmpty(p) == 0) {
        return 0;
    }
} 

int main () {
    struct pilha *p1;
    p1 = (struct pilha *) malloc(sizeof(struct pilha));
    inicializar(p1);
    char s1[MAX];
    printf("Digite sua expressao: ");
    fgets(s1, MAX, stdin);
    int resultado = balanceamento(s1);
    if (resultado == 1) {
        printf("A expressao esta balanceada"); 
    } else {
        printf("A expressao nao esta balanceada");
    }

    free(p1);
}
