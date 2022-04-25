/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
#ifndef FILA_H
#define FILA_H

//O nodeF tem duas representações: Uma de "vetor", onde o próximo será apenas o elemento de index incrementado em um e o anterior o contrário disso, e outra de grafo, sendo essa composta pelo pai, filho esq e filho dir.
typedef struct nodeF {
  char nome[30];
  int idade;
  char urgencia; //Red, Orange, Yellow, Green, Blue (R>O>Y>G>B)(A<B<C<D<E)
  int index;
  struct nodeF *pai;
  struct nodeF *filhoEsq;
  struct nodeF *filhoDir;
  struct nodeF *proximo;
  struct nodeF *anterior;
} NodeF;

//A fila tem campos Node fim e inicio e o tamanho.
typedef struct fila {
  NodeF *fim;
  NodeF *inicio;
  int tam;
} Fila;

void inicializarFila(Fila *f);
void inserirFila(char nome[30], int idade, char urgencia, Fila *f);
void retirarFila(Fila *f);
int vaziaFila(Fila *f);
void destruirFila(Fila *f);

//==============================
//Funcoes para uso interno das funções principais

void fixUpFila(Fila *f,NodeF *n);
void fixDownFila(Fila *f,NodeF *n);
void trocaNodeFila(NodeF *a,NodeF *b);
char ajustaUrgenciaFila(char urgencia);
void ajustaHeapDownFila(Fila *f, NodeF *n);

#endif