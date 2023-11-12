#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 1000

struct lista {
        int elementos[MAX];
        int particao;
};

void inicializar(struct lista *l);
int inserirFim(struct lista *l, int valor);
int inserirInicio(struct lista *l, int valor);
void exibir(struct lista *l);
int inserirPosicao(struct lista *l, int valor, int posicao);
int inserirOrdem (struct lista *l, int valor);
void reverso(struct lista *l);
int removerInicio(struct lista *l);
int removerFim(struct lista *l);
int removerPosicao(struct lista *l, int posicao);
int removerValor(struct lista *l, int valor);
int procurar (struct lista *l, int n);
int somatorio (struct lista *l);
int tamanho (struct lista *l);
int quadrado (struct lista *l);
int qtdPrimo (struct lista *l);
void sair ();

#endif
