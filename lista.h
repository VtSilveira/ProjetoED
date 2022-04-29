/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor
 * Silveira*/
#ifndef LISTA_H
#define LISTA_H

// O NodeL possui um espaço para um int, como também possui dois ponteiros em
// sua composição (proximo e anterior), que foram implementados com o intuito de
// cumprir com a o requisito "Lista duplamente encadeada".
typedef struct nodeL {
  int valor;
  char nome[30];
  char consulta[30];
  struct nodeL *proximo;
  struct nodeL *antes;
} NodeL;

// o struct Lista possui um ponteiro para o Nó sentinela e também um campo
// referente ao seu tamanho.
typedef struct lista {
  NodeL *sentinela;
  int tam;
} lista;

// o struct Iterador possui um ponteiro para um Nó (escolhido de acordo com a aplicação)
// e um ponteiro para uma Lista.
typedef struct iterador {
  NodeL *posicao;
  lista *estrutura;
} Iterador;

//insere um elemento em sua posicao correta, de modo que a lista esteja sempre ordenada para facilitar o uso de funcoes da lista
void inserirElementoLista(lista *l, Iterador *i, int num, char nome[], char consulta[], int idade);
//inicializa a lista
void inicializarLista(lista *l);
//insere no inicio da lista
void inserirInicioLista(lista *l, int num, char nome[], char consulta[]);
//insere no final da lista
void inserirFinalLista(lista *l, int num, char nome[], char consulta[]);
//remove o inicio da lista
void removerInicioLista(lista *l);
//remove o final da lista
void removerFinalLista(lista *l);
//destroi a lista usando função de remover
void destruirLista(lista *l);
//checa se a lista está vazia
int vaziaLista(lista *l);

//funcoes que inserem e removem com o auxilio do iterador
void inserirAntes(lista *l, Iterador *i, int valor, char nome[], char consulta[]);
void inserirDepois(lista *l, Iterador *i, int valor, char nome[], char consulta[]);
void removerElemento(lista *l, Iterador *i, int valor);
void insereListaOrdenada(lista *l, Iterador *i, int num, char nome[], char consulta[], int idade, Iterador* (*ordena)(int valor, Iterador *i, lista *l));

//funcoes para o uso dos iteradores
Iterador *primeiro(lista *l);
Iterador *ultimo(lista *l);
Iterador *buscaPosicao(lista *l, int valor);
int acabou(Iterador *i);

void imprimirLista(lista *l);
void imprimirListaOrdenada(lista *l);
#endif