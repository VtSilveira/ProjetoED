#ifndef PHILA_H
#define PHILA_H

typedef struct nodeF {
  int idade;
  char urgencia; //Red, Orange, Yellow, Green, Blue (R>O>Y>G>B)(A<B<C<D<E)
  int index;
  struct nodeF *pai;
  struct nodeF *filhoEsq;
  struct nodeF *filhoDir;
  struct nodeF *proximo;
  struct nodeF *anterior;
} NodeF;

typedef struct fila {
  NodeF *fim;
  NodeF *inicio;
  int tam;
} Fila;

void inicializarFila(Fila *f);
void inserirFila(int idade, char urgencia, Fila *f);
void retirarFila(Fila *f);
int vaziaFila(Fila *f);
void destruirFila(Fila *f);

//==============================
//Funcoes para uso interno das funções principais acima 

void fixUpFila(Fila *f,NodeF *n);
void fixDownFila(Fila *f,NodeF *n);
void trocaNodeFila(NodeF *a,NodeF *b);
char ajustaUrgenciaFila(char urgencia);
void ajustaHeapDownFila(Fila *f, NodeF *n);

#endif