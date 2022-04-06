#ifndef LISTA_H
#define LISTA_H

typedef struct nodeL {
  int valor;
  struct nodeL *proximo;
  struct nodeL *antes;
} NodeL;

typedef struct lista {
  NodeL *sentinela;
  int tam;
} lista;

void inicializarLista(lista *l);
void inserirInicioLista(lista *l, int num);
void inserirFinalLista(lista *l, int num);
void removerInicioLista(lista *l);
void removerFinalLista(lista *l);
void destruirLista(lista *l);
int vaziaLista(lista *l);
void imprimirLista(NodeL *nodeL);

/*Parte ainda não implementada.=======================
void inserirMeioDps(lista *l, int num, int ant);
void inserirMeioAntes(lista *l, int num, int depois);
void imprimir(NodeL *nodeL);
======================================================*/



#endif