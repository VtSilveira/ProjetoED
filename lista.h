/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
#ifndef LISTA_H
#define LISTA_H

//O NodeL possui um espaço para um int, como também possui dois ponteiros em sua composição (proximo e anterior), que foram implementados com o intuito de cumprir com a o requisito "Lista duplamente encadeada".
typedef struct nodeL {
  int valor;
  struct nodeL *proximo;
  struct nodeL *antes;
} NodeL;

//o struct Lista possui um ponteiro para o Nó sentinela e também um campo referente ao seu tamanho.
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

/*Parte ainda não implementada.=======================
void inserirMeioDps(lista *l, int num, int ant);
void inserirMeioAntes(lista *l, int num, int depois);
======================================================*/



#endif