#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//No teste da fila, são inseridos vários elementos e depois são destruídos, testando todas as funções implementadas, já que a funcão de destruir contém a vazia e a retirar.
int main() {
  Fila f;

  inicializarFila(&f);
  inserirFila(20, 'R', &f);
  inserirFila(60, 'O', &f);
  inserirFila(19, 'R', &f);
  inserirFila(47, 'B', &f);
  inserirFila(37, 'Y', &f);
  inserirFila(45, 'O', &f);
  inserirFila(90, 'G', &f);
  inserirFila(108, 'B', &f);
  destruirFila(&f);
  
  //Ao fim do programa é possível ver que tudo ocorreu dentro do esperado.
  return 0;
}