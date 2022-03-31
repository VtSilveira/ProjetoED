#include "phila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarFila(Fila *f) {
  f->tam = 0;
  f->fim = NULL;
  f->inicio = NULL;
}


void inserirFila(int idade, char urgencia, Fila *f) {

  Node *novo = (Node *)malloc(sizeof(Node));
  novo->idade = idade;
  novo->urgencia = urgencia;
  novo->filhoDir = NULL;
  novo->filhoEsq = NULL;
  novo->proximo = NULL;
  f->tam++;

  if (vazia(f)) {

    f->fim = novo;
    f->inicio = novo;
    novo->pai = novo;
    novo->index = f->tam;

  } else {

    f->fim->proximo = novo;
    f->fim = novo;
    

    Node *aux = (Node *)malloc(sizeof(Node));

    aux = f->inicio;

    int i=1;
    while(i != (novo->index/2)){
      aux = aux->proximo;
      i++;
    }

    novo->pai = aux;

    if (novo->pai->index*2 == novo->index)
      novo->pai->filhoEsq = novo; 
    else
      novo->pai->filhoDir = novo;
    
    free(aux);

    fixUp(f, novo);
  }
}

void retirarFila(Fila *f) {
}

void fixUp(Fila *f, Node *n) {
  if (n->pai != n) {
    if (n->urgencia == n->pai->urgencia) {
      if (n->idade > n->pai->idade) {
        trocaNode(n, n->pai);
        fixUp(f, n);
      }
    } else if (n->urgencia > n->pai->urgencia) {
      trocaNode(n, n->pai);
      fixUp(f, n);
    }
  }
}

int vazia(Fila *f) {
  return f->tam == 0;
}

void trocaNode(Node *a, Node *b) {
  Node *aux = (Node *)malloc(sizeof(Node));

  aux->proximo = a->proximo;
  aux->filhoDir = a->filhoDir;
  aux->filhoEsq = a->filhoEsq;
  aux->idade = a->idade;

  a->proximo = b->proximo;
  a->filhoDir = b->filhoDir;
  a->filhoEsq = b->filhoEsq;
  a->idade = b->idade;

  b->proximo = aux->proximo;
  b->filhoDir = aux->filhoDir;
  b->filhoEsq = aux->filhoEsq;
  b->idade = aux->idade;

  free(aux);
}
