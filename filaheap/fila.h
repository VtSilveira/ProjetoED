#ifndef FILA_H
#define FILA_H

#include "heap.h"
#include <stdbool.h>

typedef struct node {
  int idade;
  struct node *proximo;
} Node;

typedef struct fila {
  Node *fim;
  Node *inicio;
  int tam;
} Fila;


bool vazia(Fila *f);

void insere(Fila *f, int idade);
void remove(Fila *f, int idade);

int tamanho(Fila *f);



#endif