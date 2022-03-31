#ifndef PHILA_H
#define PHILA_H

typedef struct node {
  int idade;
  char urgencia; //Red, Orange, Yellow, Green, Blue (R>O>Y>G>B)
  int index;
  Node *pai;
  Node *filhoEsq;
  Node *filhoDir;
  Node *proximo;
} Node;

typedef struct fila {
  Node *fim;
  Node *inicio;
  int tam;
} Fila;

void inicializarFila(Fila *f);
void inserirFila(int idade, char urgencia, Fila *f);
void retirarFila(Fila *f);
void fixUp(Fila *f,Node *aux);
int vazia(Fila *f);
void trocaNode(Node *a,Node *b);
int encontraPai(Node *novo, Fila *f, Node *aux)

#endif