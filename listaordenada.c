#include "lista.h"
#include "listaordenada.h"
#include <stdio.h>
#include <stdlib.h>

// funciona exatamente da mesma maneira da inserção de elementos na inserirElementoLista, porém com ponteiro pra funcao de ordenacao passada como parametro
void insereListaOrdenada(lista *l, Iterador *i, int num, Iterador *(*ordena)(int valor, Iterador *i, lista *l)) {
  if (vaziaLista(l)) {
    inserirInicioListaOrdenada(l, num);
    i->posicao = l->sentinela->proximo;
  } else {
    NodeL *novo = (NodeL *)malloc(sizeof(NodeL));
    if (novo) {
      i = (*ordena)(num, i, l);
      inserirAntesListaOrdenada(l, i, num);
      i->posicao = l->sentinela->proximo;
    }
  }
}

Iterador *ordenalista(int valor, Iterador *i, lista *l) {
  while (valor > i->posicao->valor && i->posicao != l->sentinela) {
    i->posicao = i->posicao->proximo;
  }
  return i;
}

void inserirInicioListaOrdenada(lista *l, int num) {
  NodeL *novo = malloc(sizeof(NodeL));  //é alocado um espaço na memoria para o novo nó

  if (novo) {  // se o novo nó foi alocado corretamente:
    novo->valor = num;
    l->sentinela->proximo->antes = novo;    // a referencia "anterior" do antigo primeiro nó passa a ser o novo nó, uma vez que iremos inserir no inicio
    novo->proximo = l->sentinela->proximo;  // o proximo nó do novo nó passa a ser o antigo primeiro nó
    l->sentinela->proximo = novo;           // é colocado no inicio da Lista, sendo posterior ao sentinela
    novo->antes = l->sentinela;             // a fim de manter a característica circular da Lista, a referencia de anterior do novo nó passa a ser o sentinela
    l->tam++;                               // tamanho da fila é incrementado

  }
}
void inserirAntesListaOrdenada(lista *l, Iterador *i, int valor) {
  NodeL *novo = malloc(sizeof(NodeL));
  NodeL *aux = i->posicao->antes;  //é criado um ponteiro para o nó anterior ao nó que o iterador está apontando.
  if (novo) {                      // se foi alocado corretamente:
    l->tam++;                      // tamanho da Lista aumenta

    // os parâmetros da função são atribuidos ao novo Nó alocado
    novo->valor = valor;
    novo->antes = aux;           // o nó anterior ao novo nó passa a ser o nó que era anterior ao apontado pelo iterador
    novo->proximo = i->posicao;  // o nó posterior ao novo nó é o nó apontado pelo iterador, uma vez que desejamos inserir antes dele
    aux->proximo = novo;       // o nó que era anterior ao apontado pelo iterador se conecta ao novo nó
    i->posicao->antes = novo;  // o nó anterior ao apontado pelo iterador passa a ser o novo nó, preservando a característica circular da Lista
  }
}

// imprime a lista ordenada :D
void imprimirListaOrdenada(lista *l) {
  NodeL *aux = l->sentinela->proximo;
  if (vaziaLista(l)) {
    printf("A lista esta vazia!\n\n");
    return;
  }

  while (aux != l->sentinela) {
    printf("%d\n", aux->valor);
    aux = aux->proximo;
  }
}