#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

Iterador *ordenalista(int valor, Iterador *i, lista *l) {
  while (valor > i->posicao->valor && i->posicao != l->sentinela) {
    i->posicao = i->posicao->proximo;
  }
  return i;
}

int main() {
  lista l;
  Iterador *it;

  it = primeiro(&l);
  inicializarLista(&l);
  insereListaOrdenada(&l, it, 3, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 7, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 1, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 2, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 90, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 92, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 890, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 12312, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 1879, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 3809, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 798, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 9814, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 10, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 15, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 109, "abc", "abc", 4, ordenalista);
  imprimirListaOrdenada(&l);
  insereListaOrdenada(&l, it, 198, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 789, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 1625, "abc", "abc", 4, ordenalista);
  insereListaOrdenada(&l, it, 424, "abc", "abc", 4, ordenalista);
  imprimirListaOrdenada(&l);
  destruirLista(&l);

  return 0;
}