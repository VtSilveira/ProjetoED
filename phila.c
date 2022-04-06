#include "phila.h"

#include <stdio.h>
#include <stdlib.h>

void inicializarFila(Fila *f) {
  f->tam = 0;
  f->fim = NULL;
  f->inicio = NULL;
}

void inserirFila(int idade, char urgencia, Fila *f) {
  NodeF *novo = (NodeF *)malloc(sizeof(NodeF));
  novo->idade = idade;

  novo->urgencia = ajustaUrgenciaFila(urgencia);
  if((novo->idade >= 60) && (novo->urgencia <'B'))
    novo->urgencia = 'B';
  
  novo->filhoDir = NULL;
  novo->filhoEsq = NULL;
  novo->proximo = NULL;

  if (novo) {
    if (vaziaFila(f)) {
      f->tam++;
      f->fim = novo;
      f->inicio = novo;
      novo->pai = novo;
      novo->index = f->tam;
      novo->anterior = NULL;

    } else {
      novo->anterior = f->fim;
      f->tam++;
      f->fim->proximo = novo;
      f->fim = novo;
      novo->index = f->tam;

      NodeF *aux = f->inicio;

      int i = 1;
      while (i != (novo->index / 2)) {
        aux = aux->proximo;
        i++;
      }

      novo->pai = aux;

      if (novo->pai->index * 2 == novo->index)
        novo->pai->filhoEsq = novo;
      else
        novo->pai->filhoDir = novo;
      
      fixUpFila(f, novo);
    }
  } else {
    printf("A memoria nao foi alocada corretamente.\n");
  }
}

void retirarFila(Fila *f) {
  trocaNodeFila(f->fim, f->inicio);

  if (f->fim->index%2 == 0)
    f->fim->pai->filhoEsq = NULL;
  else
    f->fim->pai->filhoDir = NULL;
  
  f->fim = f->fim->anterior;

  if (f->fim)
    f->fim->proximo = NULL;
  
  f->tam--;
  
  ajustaHeapDownFila(f, f->inicio);
}

void fixUpFila(Fila *f, NodeF *n) {
  if (n->pai != n) {
    if (n->urgencia == n->pai->urgencia) {
      if (n->idade > n->pai->idade) {
        trocaNodeFila(n, n->pai);
        fixUpFila(f, n->pai);
      }
    } else if (n->urgencia > n->pai->urgencia) {
      trocaNodeFila(n, n->pai);
      fixUpFila(f, n->pai);
    }
  }
}

int vaziaFila(Fila *f) {
  return f->tam == 0;
}

void trocaNodeFila(NodeF *a, NodeF *b) {
  NodeF *aux = (NodeF *)malloc(sizeof(NodeF));

  aux->idade = a->idade;
  aux->urgencia = a->urgencia;


  a->idade = b->idade;
  a->urgencia = b->urgencia;


  b->idade = aux->idade;
  b->urgencia = aux->urgencia;

  free(aux);
}

char ajustaUrgenciaFila(char urgencia) {
  switch (urgencia) {
    case 'R':
      return 'E';
    case 'O':
      return 'D';
    case 'Y':
      return 'C';
    case 'G':
      return 'B';
    case 'B':
      return 'A';
    default:
      return 'Z';
  }
}

void ajustaHeapDownFila(Fila *f, NodeF *n) {
  NodeF *maior = n;
  if (n->filhoEsq) {
    if (n->urgencia == n->filhoEsq->urgencia) {
      if (n->idade < n->filhoEsq->idade) {
        maior = n->filhoEsq;
      }
    } else if (n->urgencia < n->filhoEsq->urgencia) {
      maior = n->filhoEsq;
    }
  }

  if (n->filhoDir) {
    if (maior->urgencia == n->filhoDir->urgencia) {
      if (maior->idade < n->filhoDir->idade) {
        maior = n->filhoDir;
      }
    } else if (maior->urgencia < n->filhoDir->urgencia) {
      maior = n->filhoDir;
    }
  }

  if (maior != n) {
    trocaNodeFila(n, maior);
    ajustaHeapDownFila(f, maior);
  }
}

void destruirFila(Fila *f){
  while (!vaziaFila(f))
    retirarFila(f);

  free(f->inicio);
}