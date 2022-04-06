#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "phila.h"

int main() {
  lista l;
  Fila f;

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
  

  return 0;
}