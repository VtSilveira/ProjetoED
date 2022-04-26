#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "lista.h"
#include "utils.h"


int main() {
  char chooser;
  dia dia[30];
  Fila f;

  struct tm *data_hora_atual;
  inicializarDia(dia);
  time_t segundos;
  time(&segundos);

  data_hora_atual = localtime(&segundos);

  inicializarFila(&f);

  inicializarIteradores(dia);

  while (1) {
    chooser = chooser1();
    switch (chooser) {
      case 'M':
        abaEmergencia(&f);       
        break;

      case 'C':
        abaConsulta(dia,data_hora_atual);
        break;

      case 'S':
        destruirFila(&f);
        for (int i = 0; i < 30; i++)
        {
          destruirLista(&dia[i].l);
        }
        printf ("As listas de todos os dias e a fila do dia atual foram destruidas com sucesso.\n");
        return 0;
        break;

      default:
        printf("Selecione uma opcao valida\n");
        break;
    }
  }
}
//imprimirLista(&dia[data_hora_atual->tm_mday-1].l);