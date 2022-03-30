#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


void inicializarlista(lista *l) {
  Node *novo = (Node*)malloc(sizeof(Node));
  l->sentinela = novo;
  novo->proximo = l->sentinela;
  novo->antes = l->sentinela;
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

void inserirInicio(lista *l, int num) {
  Node *novo = malloc(sizeof(Node));

  if (novo) {
    novo->valor = num;
    l->sentinela->proximo->antes = novo;
    novo->proximo = l->sentinela->proximo;
    l->sentinela->proximo = novo;
    novo->antes = l->sentinela;
    l->tam++;

  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}

void inserirFinal(lista *l, int num) {
  Node *novo = malloc(sizeof(Node));

  if (novo) {
    novo->valor = num;
    novo->proximo = l->sentinela;
    l->tam++;

    if (vazia(l)) {
      l->sentinela->antes = novo;
      l->sentinela->proximo = novo;
      novo->antes = l->sentinela;

    } else {
      l->sentinela->antes->proximo = novo;
      novo->antes = l->sentinela->antes;
      l->sentinela->antes = novo;
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