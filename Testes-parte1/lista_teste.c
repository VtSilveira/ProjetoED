/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
//A formação correta da fila pode ser vista através de um debugger
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//No teste da lista, são inseridos vários elementos, removemos alguns e depois destruímos a lista, testando todas as funções implementadas.
int main() {
  lista l;
  Iterador *i;

  inicializarLista(&l);
  i = primeiro(&l);
  inserirElementoLista(&l, i, 1020, "joao", "jhonso", 18);
  inserirElementoLista(&l, i, 840, "andre", "jhonso2", 184);
  inserirElementoLista(&l, i, 900, "vitor2", "jhonso3", 183);
  inserirElementoLista(&l, i, 480, "vitor3", "jhonso5", 182);
  inserirElementoLista(&l, i, 510, "vitor4", "jhonso7", 181);
  

  //Ao fim do programa é possível ver que tudo ocorreu dentro do esperado.
  return 0;
}