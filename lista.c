#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


void inicializarLista(lista *l) {
  NodeL *novo = (NodeL*)malloc(sizeof(NodeL));
  l->sentinela = novo;
  novo->proximo = l->sentinela;
  novo->antes = l->sentinela;
}

void destruirLista(lista *l) {
  while (!vaziaLista(l))
    removerInicioLista(l);

  if (vaziaLista(l))
    printf ("A lista foi destruida corretamente.\n");
  else
    printf ("Nao foi possível destruir a lista.\n");

   free(l->sentinela);
}

int vaziaLista(lista *l) {
  return l->sentinela->proximo == l->sentinela;
}

void removerInicioLista(lista *l) {
  NodeL *aux = l->sentinela->proximo;
  if (!vaziaLista(l)) {
    aux->proximo->antes = aux->antes;
    aux->antes->proximo = aux->proximo;
    free(aux);
  }
  l->tam--;
}

void removerFinalLista(lista *l) {
  NodeL *aux = l->sentinela->antes;
  if (!vaziaLista(l)) {
    aux->proximo->antes = aux->antes;
    aux->antes->proximo = aux->proximo;
    free(aux);
  }
  l->tam--;
}

void inserirInicioLista(lista *l, int num) {
  NodeL *novo = malloc(sizeof(NodeL));

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

void inserirFinalLista(lista *l, int num) {
  NodeL *novo = malloc(sizeof(NodeL));

  if (novo) {
    novo->valor = num;
    novo->proximo = l->sentinela;
    l->tam++;

    if (vaziaLista(l)) {
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
  NodeL *aux, *novo = malloc(sizeof(NodeL));

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
  NodeL *aux, *novo = malloc(sizeof(NodeL));

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

void imprimir(NodeL *nodeL) {
  printf("\nLista: ");
  while (nodeL) {
    printf("%d ", nodeL->valor);
    nodeL = nodeL->proximo;
  }
  printf("\n\n");
}