/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Essa função apenas inicializa a Lista, criando o Nó sentinela e fazendo suas referencias anterior e próximo apontarem para si mesmo, uma vez que a Lista está vazia e é circular.
void inicializarLista(lista *l) {
  NodeL *novo = (NodeL *)malloc(sizeof(NodeL));
  l->sentinela = novo;
  novo->proximo = l->sentinela;
  novo->antes = l->sentinela;
  l->tam = 0;
}

void inserirElementoLista(lista *l, Iterador *i, int num, char nome[], char consulta[], int idade) {
  if (vaziaLista(l)) {
    inserirInicioLista(l, num, nome, consulta);
    i->posicao = l->sentinela->proximo;
  } else {
    NodeL *novo = (NodeL *)malloc(sizeof(NodeL));
    if (novo) {
      while (num > i->posicao->valor && i->posicao != l->sentinela){
        i->posicao = i->posicao->proximo;
      }
      inserirAntes(l,i,num,nome,consulta);
      i->posicao = l->sentinela->proximo;
    }
  }
}

// Destruição da Lista baseada nas funções vazia e removerInicio (poderia ser removerFim também).
void destruirLista(lista *l) {
  while (!vaziaLista(l))    // enquanto a Lista não estiver vazia
    removerInicioLista(l);  // remove o nó do inicio
    
  free(l->sentinela);  // desaloca o nó sentinela da memória que não é considerado como nó na função "removerInicio"
}

// checa se o próximo nó do sentinela é ele mesmo. Se sim, significa que ela está vazia.
int vaziaLista(lista *l) {
  return l->sentinela->proximo == l->sentinela;
}

void removerInicioLista(lista *l) {
  NodeL *aux = l->sentinela->proximo;    //é criado um ponteiro para o inicio da fila
  if (!vaziaLista(l)) {                  // se a lista não tiver vazia
    aux->proximo->antes = aux->antes;    // o nó anterior ao segundo antigo nó passa a ser o sentinela, tornando-o o primeiro nó da Lista
    aux->antes->proximo = aux->proximo;  // o nó posterior ao sentinela passa a ser o antigo segundo nó da Lista
    free(aux);                           // o antigo primeiro nó da Lista é desalocado
  }
  l->tam--;  // o tamanho da fila é decrementado
}

void removerFinalLista(lista *l) {
  NodeL *aux = l->sentinela->antes;      //é criado um ponteiro para o fim da fila
  if (!vaziaLista(l)) {                  // se a lista não tiver vazia
    aux->proximo->antes = aux->antes;    // o nó anterior ao penultimo antigo nó passa a ser o sentinela, tornando-o o ultimo nó da Lista
    aux->antes->proximo = aux->proximo;  // o nó posterior ao sentinela passa a ser o antigo penultimo nó da Lista, conservando a característica circular da Lista
    free(aux);                           // o antigo ultimo nó da Lista é desalocado
  }
  l->tam--;  // o tamanho da fila é decrementado
}

void inserirInicioLista(lista *l, int num, char nome[], char consulta[]) {
  NodeL *novo = malloc(sizeof(NodeL));  //é alocado um espaço na memoria para o novo nó

  if (novo) {  // se o novo nó foi alocado corretamente:
    novo->valor = num;
    strcpy(novo->nome, nome);
    strcpy(novo->consulta, consulta);

    l->sentinela->proximo->antes = novo;    // a referencia "anterior" do antigo primeiro nó passa a ser o novo nó, uma vez que iremos inserir no inicio
    novo->proximo = l->sentinela->proximo;  // o proximo nó do novo nó passa a ser o antigo primeiro nó
    l->sentinela->proximo = novo;           // é colocado no inicio da Lista, sendo posterior ao sentinela
    novo->antes = l->sentinela;             // a fim de manter a característica circular da Lista, a referencia de anterior do novo nó passa a ser o sentinela
    l->tam++;                               // tamanho da fila é incrementado

  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}

void inserirFinalLista(lista *l, int num, char nome[], char consulta[]) {
  NodeL *novo = malloc(sizeof(NodeL));

  if (novo) {  // se o nó foi alocado corretamente:
    novo->valor = num;
    strcpy(novo->nome, nome);
    strcpy(novo->consulta, consulta);
    novo->proximo = l->sentinela;  // o nó posterior ao novo nó passa a ser o sentinela
    novo->antes = l->sentinela->antes;
    l->sentinela->antes->proximo = novo;
    l->sentinela->antes = novo;  // o novo nó passa a ser o nó anterior ao sentinela
    l->tam++;

  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}

void inserirAntes(lista *l, Iterador *i, int valor, char nome[], char consulta[]) {
  NodeL *novo = malloc(sizeof(NodeL));
  NodeL *aux = i->posicao->antes;
  if (novo) {
    l->tam++;
    novo->valor = valor;
    strcpy(novo->nome, nome);
    strcpy(novo->consulta, consulta);

    novo->antes = aux;
    novo->proximo = i->posicao;

    aux->proximo = novo;
    i->posicao->antes = novo;
  }
}
void inserirDepois(lista *l, Iterador *i, int valor, char nome[], char consulta[]) {
  NodeL *novo = malloc(sizeof(NodeL));
  NodeL *aux = i->posicao->proximo;
  if (novo) {
    l->tam++;
    novo->valor = valor;
    strcpy(novo->nome, nome);
    strcpy(novo->consulta, consulta);

    novo->proximo = aux;
    novo->antes = i->posicao;

    aux->antes = novo;
    i->posicao->proximo = novo;
  }
}

void removerElemento(lista *l, Iterador *i, int valor) {
  if (!vaziaLista(l)) {  // se a lista não estiver vazia:
    i = buscaPosicao(l, valor);
    if (i) {
      i->posicao->proximo->antes = i->posicao->antes;
      i->posicao->antes->proximo = i->posicao->proximo;
      free(i->posicao);
      l->tam--;
    }
    i->posicao = l->sentinela->proximo;
  }
}

Iterador *primeiro(lista *l) {
  Iterador *i = malloc(sizeof(Iterador));
  i->posicao = l->sentinela->proximo;
  i->estrutura = l;
  return i;
}

Iterador *ultimo(lista *l) {
  Iterador *i = malloc(sizeof(Iterador));
  i->posicao = l->sentinela->antes;
  i->estrutura = l;
  return i;
}

Iterador *buscaPosicao(lista *l, int valor) {
  Iterador *i;
  i = primeiro(l);
  while (!acabou(i) && i->posicao->valor != valor)
    i->posicao = i->posicao->proximo;
  // ou acabou a lista ou achou o valor
  if (i->posicao->valor == valor) {
    return i;
  } else {
    printf("Não existe esse valor na lista!\n");
    return NULL;
  }
}

int acabou(Iterador *i) {
  return i->posicao == i->estrutura->sentinela;
}

int elemento(Iterador *i) {
  if (!acabou(i)) {
    return i->posicao->valor;
  }
}

void imprimirLista(lista *l) {
  NodeL *aux = l->sentinela->proximo;
  if (vaziaLista(l)){
    printf ("A lista esta vazia!\n\n");
    return;
  }

  while (aux != l->sentinela) {
    printf("%02d:%02d - %s - %s\n", (aux->valor/60),(aux->valor%60),aux->nome, aux->consulta);
    aux = aux->proximo;
  }
}
