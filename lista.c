#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int valor;
  struct node *proximo;
  struct node *antes;
} Node;

typedef struct lista {
  Node *sentinela;
  int tam;
} lista;

void inicializarlista(lista *l) {
  Node *novo = malloc(sizeof(Node));
  novo->proximo = novo->antes = l->sentinela = novo;
  l->tam = 0;
}

void destruir(lista *l) {
  while (!vazia(l))
    removerInicio(l);
  free(l->sentinela);
}

int vazia(lista *l) {
  return l->sentinela->proximo == l->sentinela;
}

void removerInicio(lista *l) {
  Node *aux = l->sentinela->proximo;
  if (!vazia(l)) {
    aux->proximo->antes = aux->antes;
    aux->antes->proximo = aux->proximo;
    free(aux);
  }
  l->tam--;
}

void removerFinal(lista *l) {
  Node *aux = l->sentinela->antes;
  if (!vazia(l)) {
    aux->proximo->antes = aux->antes;
    aux->antes->proximo = aux->proximo;
    free(aux);
  }
  l->tam--;
}

void inserir_no_inicio(lista *l, int num) {
  Node *novo = malloc(sizeof(Node));

  if (novo) {
    novo->valor = num;
    l->sentinela->proximo = novo;
    novo->proximo = l->sentinela;
    l->tam++;

  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}

void inserir_no_final(lista *l, int num) {
  Node *aux = l->sentinela->antes, *novo = malloc(sizeof(Node));

  if (novo) {
    novo->valor = num;
    novo->proximo = l->sentinela;
    l->tam++;

    if (vazia(l)) {
      l->sentinela->antes = novo;
      l->sentinela->proximo = novo;
      novo->antes = l->sentinela;

    } else {
      l->sentinela->antes = novo;
      aux->proximo = novo;
      novo->antes = aux;
    }

  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}

/*void inserir_meio_dps(lista *l, int num, int ant) {
  Node *aux, *novo = malloc(sizeof(Node));

  if (novo) {
    novo->valor = num;
    l->tam++;
    if (!l->sentinela) {
      novo->proximo = NULL;
      l->sentinela = novo;
    } else {
      aux =  l->sentinela;

      while (aux->valor != ant && aux->proximo)
        aux = aux->proximo;

      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}*/

/*void inserir_meio_antes(lista *l, int num, int depois) {
  Node *aux, *novo = malloc(sizeof(Node));

  if (novo) {
    novo->valor = num;
    l->tam++;
    if (!l->sentinela) {
      novo->proximo = NULL;
      l->sentinela = novo;
    } else {
      aux =  l->sentinela;

      while (aux->proximo->proximo->valor != depois && aux->proximo->proximo)
        aux = aux->proximo;

      novo->proximo = aux->proximo->proximo;
      aux->proximo->proximo = novo;
    }
  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}*/

void imprimir(Node *node) {
  printf("\nLista: ");
  while (node) {
    printf("%d ", node->valor);
    node = node->proximo;
  }
  printf("\n\n");
}