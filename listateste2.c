/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
//A formação correta da fila pode ser vista através de um debugger
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//No teste da lista, são inseridos vários elementos, removemos alguns e depois destruímos a lista, testando todas as funções implementadas.
int main() {
  lista l;
  Iterador *first, *last, *random;
  
  inicializarLista(&l);
  
  inserirFinalLista(&l, 90);
  imprimirLista(&l);
  printf("\n");
  
  inserirFinalLista(&l,89);
  imprimirLista(&l);
  printf("\n");
  
  inserirFinalLista(&l,-2);
  imprimirLista(&l);
  printf("\n");
  
  inserirFinalLista(&l,4);
  imprimirLista(&l);
  printf("\n");
  
  first = primeiro(&l);
  last = ultimo(&l);
  random = buscaPosicao(&l,-2);
  
  inserirAntes(&l,random,-4);
  imprimirLista(&l);
  printf("\n");
  
  inserirAntes(&l,first,50);
  imprimirLista(&l);
  printf("\n");
  
  inserirAntes(&l,last,23);
  imprimirLista(&l);
  printf("\n");

  inserirDepois(&l,random,-7);
  imprimirLista(&l);
  printf("\n");
  
  inserirDepois(&l,first,55);
  imprimirLista(&l);
  printf("\n");
  
  inserirDepois(&l,last,21);
  imprimirLista(&l);
  printf("\n");

  removerElemento(&l,first,-2);
  removerInicioLista(&l);
  removerFinalLista(&l);
  imprimirLista(&l);
  destruirLista(&l);

  //Ao fim do programa é possível ver que tudo ocorreu dentro do esperado.
  return 0;
}