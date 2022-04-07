#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

//Essa função apenas inicializa a Lista, criando o Nó sentinela e fazendo suas referencias anterior e próximo apontarem para si mesmo, uma vez que a Lista está vazia e é circular.
void inicializarLista(lista *l) {
  NodeL *novo = (NodeL*)malloc(sizeof(NodeL));
  l->sentinela = novo;
  novo->proximo = l->sentinela;
  novo->antes = l->sentinela;
  l->tam=0;
}

//Destruição da Lista baseada nas funções vazia e removerInicio (poderia ser removerFim também).
void destruirLista(lista *l) {
  while (!vaziaLista(l))//enquanto a Lista não estiver vazia
    removerInicioLista(l);//remove o nó do inicio

  if (vaziaLista(l))//caso a Lista estiver vazia no final do loop, aparece a mensagem de sucesso, senão, a de erro.
    printf ("A lista foi destruida corretamente.\n");
  else
    printf ("Nao foi possível destruir a lista.\n");

   free(l->sentinela);//desaloca o nó sentinela da memória que não é considerado como nó na função "removerInicio"
}

//checa se o próximo nó do sentinela é ele mesmo. Se sim, significa que ela está vazia.
int vaziaLista(lista *l) {
  return l->sentinela->proximo == l->sentinela;
}


void removerInicioLista(lista *l) {
  NodeL *aux = l->sentinela->proximo;//é criado um ponteiro para o inicio da fila
  if (!vaziaLista(l)) {//se a lista não tiver vazia
    aux->proximo->antes = aux->antes; // o nó anterior ao segundo antigo nó passa a ser o sentinela, tornando-o o primeiro nó da Lista
    aux->antes->proximo = aux->proximo; //o nó posterior ao sentinela passa a ser o antigo segundo nó da Lista
    free(aux);//o antigo primeiro nó da Lista é desalocado
  }
  l->tam--;//o tamanho da fila é decrementado
}

void removerFinalLista(lista *l) {
  NodeL *aux = l->sentinela->antes;//é criado um ponteiro para o fim da fila
  if (!vaziaLista(l)) {//se a lista não tiver vazia
    aux->proximo->antes = aux->antes;// o nó anterior ao penultimo antigo nó passa a ser o sentinela, tornando-o o ultimo nó da Lista
    aux->antes->proximo = aux->proximo;//o nó posterior ao sentinela passa a ser o antigo penultimo nó da Lista, conservando a característica circular da Lista
    free(aux);//o antigo ultimo nó da Lista é desalocado
  }
  l->tam--;//o tamanho da fila é decrementado
}

void inserirInicioLista(lista *l, int num) {
  NodeL *novo = malloc(sizeof(NodeL));//é alocado um espaço na memoria para o novo nó

  if (novo) {//se o novo nó foi alocado corretamente:
    novo->valor = num;
    l->sentinela->proximo->antes = novo;//a referencia "anterior" do antigo primeiro nó passa a ser o novo nó, uma vez que iremos inserir no inicio
    novo->proximo = l->sentinela->proximo;//o proximo nó do novo nó passa a ser o antigo primeiro nó
    l->sentinela->proximo = novo;// é colocado no inicio da Lista, sendo posterior ao sentinela
    novo->antes = l->sentinela; // a fim de manter a característica circular da Lista, a referencia de anterior do novo nó passa a ser o sentinela
    l->tam++;//tamanho da fila é incrementado

  } else {
    printf("A memoria não foi alocada corretamente\n");
  }
}

void inserirFinalLista(lista *l, int num) {
  NodeL *novo = malloc(sizeof(NodeL));

  if (novo) {//se o nó foi alocado corretamente:
    novo->valor = num;
    novo->proximo = l->sentinela;//o nó posterior ao novo nó passa a ser o sentinela
    l->sentinela->antes = novo;// o novo nó passa a ser o nó anterior ao sentinela
    l->tam++;

    if (vaziaLista(l)) {//se a lista estiver vazia:
      //tanto o nó posterior como o anterior ao sentinela será o novo nó alocado
      l->sentinela->proximo = novo;
      novo->antes = l->sentinela;// a fim de manter a característica circular da Lista, a referencia de anterior do novo nó passa a ser o sentinela, uma vez que inserir no fim nesse caso é a mesma coisa que inserir no inicio

    } else {// se ela não estiver vazia
      l->sentinela->antes->proximo = novo;//a referencia "anterior" do antigo ultimo nó passa a ser o novo nó, uma vez que iremos inserir no fim
      novo->antes = l->sentinela->antes; // o no anterior ao novo nó será o antigo ultimo nó da Lista
      
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
  while (nodeL) {//
    printf("%d ", nodeL->valor);
    nodeL = nodeL->proximo;
  }
  printf("\n\n");
}