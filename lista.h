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
void inserirFinal(lista *l, int num);
void removerInicio(lista *l);
void removerFinal(lista *l);
void destruir(lista *l);

/*Parte ainda não implementada.=======================
void inserirMeioDps(lista *l, int num, int ant);
void inserirMeioAntes(lista *l, int num, int depois);
void imprimir(Node *node);
======================================================*/

int vazia(lista *l);

#endif