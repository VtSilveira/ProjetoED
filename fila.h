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

//inicializa a fila
void inicializarFila(Fila *f);
//insere na fila
void inserirFila(char nome[30], int idade, char urgencia, Fila *f);
//retira o primeiro elemento da fila
void retirarFila(Fila *f);
//checa se a fila esta vazia
int vaziaFila(Fila *f);
//destroi a fila
void destruirFila(Fila *f);
//imprime a fila
void imprimeFila(Fila *f);

//==============================
//Funcoes para uso interno das funções principais

//faz o heapfy de modo bottom-up
void fixUpFila(Fila *f,NodeF *n);
//troca valores dos nós de lugar
void trocaNodeFila(NodeF *a,NodeF *b);
//funcao que ajusta a prioridade
char ajustaUrgenciaFila(char urgencia);
//faz parte da remocao de um elemento da fila, fazendo o heapfy de modo top-down
void ajustaHeapDownFila(Fila *f, NodeF *n);
//faz parte da inserção de elemento na fila, encontrando o pai do nó
NodeF *encontraPai (Fila *f, NodeF *n);
////faz parte da inserção de elemento na fila, atualizando os filhos do pai do nó alocado
void atualizaFilhos(NodeF *n);

#endif