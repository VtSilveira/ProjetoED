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

typedef struct iterador{
    NodeL *posicao;
    lista *estrutura;
}Iterador;


void inicializarLista(lista *l);
void inserirInicioLista(lista *l, int num);
void inserirFinalLista(lista *l, int num);
void removerInicioLista(lista *l);
void removerFinalLista(lista *l);
void destruirLista(lista *l);
int vaziaLista(lista *l);
void inserirAntes(lista *l, Iterador *i, int valor);
void inserirDepois(lista *l, Iterador *i, int valor);
void removerElemento(lista *l, Iterador *i, int valor);
Iterador* primeiro(lista *l);
Iterador* ultimo(lista *l);
Iterador* buscaPrimeiro(lista *l, int valor);
Iterador* buscaUltimo(Iterador *i, int valor);
Iterador* buscaPosicao(lista *l, int valor);
int proximo(Iterador *i);
int anterior(Iterador *i);
int acabou(Iterador *i);


#endif