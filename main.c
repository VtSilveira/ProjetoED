#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "lista.h"

int main() {
  lista l;

  inicializarlista(&l);
  inserirInicio(&l, 3);
  inserirInicio(&l, 5);
  inserirInicio(&l, 6);
  inserirInicio(&l, 7);
  inserirInicio(&l, -2);
  inserirInicio(&l, 1);
  inserirInicio(&l, 69);
  inserirInicio(&l, 24);
  inserirFinal(&l, 90);
  removerInicio(&l);
  removerFinal(&l);
  destruir(&l);
  destruir(&l);

  return 0;
}