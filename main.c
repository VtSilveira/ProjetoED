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
  int escolheInterface;

  struct tm *data_hora_atual;
  inicializarDia(dia);
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);

  inicializarFila(&f);
  inicializarIteradores(dia);

  printf("Para entrar na interface do(a) medico(a), digite 0, para entrar na interface do(a) atendente, digite 1: ");
  scanf("%d", &escolheInterface);
  system("cls");
  while (1) {
    while (!escolheInterface) {
      printf("===========Interface do medico===========\n");
      chooser = chooser2();

      switch (chooser) {
        case 'A':
          imprimirLista(&dia[data_hora_atual->tm_mday - 1].l);
          break;

        case 'E':
          imprimeFila(&f);
          break;

        case 'P':
          removerInicioLista(&dia[data_hora_atual->tm_mday - 1].l);
          printf("Paciente chamado e retirado da agenda com sucesso!\n");
          break;

        case 'Q':
          retirarFila(&f);
          printf("Paciente chamado e retirado da fila de emergencia com sucesso!\n");
          break;

        case 'T':
          escolheInterface = 1;
          system("cls");
          break;

        default:
          break;
      }
    }

    while (escolheInterface) {
      printf("===========Interface do atendente===========\n");
      chooser = chooser1();
      switch (chooser) {
        case 'M':
          abaEmergencia(&f);
          break;

        case 'C':
          abaConsulta(dia, data_hora_atual);
          break;

        case 'S':
          destruirFila(&f);
          for (int i = 0; i < 30; i++) {
            destruirLista(&dia[i].l);
          }
          printf("As listas de todos os dias e a fila do dia atual foram destruidas com sucesso.\n");
          return 0;
          break;

        case 'T':
          escolheInterface = 0;
          system("cls");
          break;

        default:
          printf("Selecione uma opcao valida\n");
          break;
      }
    }
  }
}
