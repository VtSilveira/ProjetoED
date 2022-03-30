#ifndef LISTA_H
#define LISTA_H

typedef struct node {
  int valor;
  struct node *proximo;
  struct node *antes;
} Node;

typedef struct lista {
  Node *sentinela;
  int tam;
} lista;

void inicializarlista(lista *l);
void inserirInicio(lista *l, int num);
void destruir(lista *l);
int vazia(lista *l);
void removerInicio(lista *l);
void removerFinal(lista *l);
void inserirFinal(lista *l, int num);
void inserirMeioDps(lista *l, int num, int ant);
void inserirMeioAntes(lista *l, int num, int depois);
void imprimir(Node *node);

#endif