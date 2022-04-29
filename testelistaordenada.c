#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "listaordenada.h"

//Programa-Teste da lista ordenada, insere varios elementos e printa, depois insere ainda mais elementos e printa denovo, terminando destruindo a lista.
int main() {
  lista l;
  Iterador *it;

  
  it = primeiro(&l);
  inicializarLista(&l);
  insereListaOrdenada(&l, it, 3, ordenalista);
  insereListaOrdenada(&l, it, 7, ordenalista);
  insereListaOrdenada(&l, it, 1,  ordenalista);
  insereListaOrdenada(&l, it, 2,  ordenalista);
  insereListaOrdenada(&l, it, 90, ordenalista);
  insereListaOrdenada(&l, it, 92, ordenalista);
  insereListaOrdenada(&l, it, 890, ordenalista);
  insereListaOrdenada(&l, it, 12312, ordenalista);
  insereListaOrdenada(&l, it, 1879, ordenalista);
  insereListaOrdenada(&l, it, 3809, ordenalista);
  insereListaOrdenada(&l, it, 798, ordenalista);
  insereListaOrdenada(&l, it, 9814, ordenalista);
  insereListaOrdenada(&l, it, 10, ordenalista);
  insereListaOrdenada(&l, it, 15, ordenalista);
  insereListaOrdenada(&l, it, 109, ordenalista);
  imprimirListaOrdenada(&l);
  insereListaOrdenada(&l, it, 198, ordenalista);
  insereListaOrdenada(&l, it, 789, ordenalista);
  insereListaOrdenada(&l, it, 1625, ordenalista);
  insereListaOrdenada(&l, it, 424, ordenalista);
  imprimirListaOrdenada(&l);
  destruirLista(&l);

  return 0;
}
