/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
//A formação correta da fila pode ser vista através de um debugger
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//No teste da lista, são inseridos vários elementos, removemos alguns e depois destruímos a lista, testando todas as funções implementadas.
int main() {
  lista l;

  inicializarLista(&l);
  inserirInicioLista(&l, 3);
  inserirInicioLista(&l, 5);
  inserirInicioLista(&l, 6);
  inserirInicioLista(&l, 7);
  inserirInicioLista(&l, -2);
  inserirInicioLista(&l, 1);
  inserirInicioLista(&l, 69);
  inserirInicioLista(&l, 24);
  inserirFinalLista(&l, 90);
  removerInicioLista(&l);
  removerFinalLista(&l);
  destruirLista(&l);

  //Ao fim do programa é possível ver que tudo ocorreu dentro do esperado.
  return 0;
}