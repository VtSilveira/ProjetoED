#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "lista.h"

typedef struct dia {
  int index;
  int horario[23];
  lista l;
  Iterador *it;
} dia;

int main() {
  char chooser, urgencia;
  char nome[30], consulta[30];
  dia dia[30];
  int idade;
  int Hh, Mm;
  int day;
  Fila f;


  for (int i = 0; i <= 30; i++) {
    dia[i].horario[0] = 480;
    for (int j = 1; j < 23; j++) {
      dia[i].horario[j] = dia[i].horario[0] + (30 * j);
    }
  }

  struct tm *data_hora_atual;

  // variável do tipo time_t para armazenar o tempo em segundos
  time_t segundos;

  // obtendo o tempo em segundos
  time(&segundos);

  // para converter de segundos para o tempo local
  // utilizamos a função localtime
  data_hora_atual = localtime(&segundos);

  inicializarFila(&f);
  for(int i=0;i<30;i++){
    inicializarLista(&dia[i].l);
    dia[i].it = primeiro(&dia[i].l);
  }

  while (1) {
    printf("Para emergencia, digite M, para agendar consultas, digite C, para sair do programa, digite S: ");
    scanf(" %c", &chooser);

    switch (chooser) {
      case 'M':
        printf("Digite o nome do paciente sem espacos (ex:JoaodaSilva): ");
        scanf("%s", nome);

        printf("Digite a idade do paciente: ");
        scanf("%d", &idade);

        printf("Urgencia: \nDigite R para vermelho: Necessita de atendimento imediato \nDigite O para laranja: Necessita de atendimento praticamente imediato (10 min) \nDigite Y para amarelo: Necessita de atendimento rapido, mas pode esperar (50 min) \nDigite G para verde: Pode esperar ou ser encaminhado para outro servico de saude (120 min) \nDigite B para azul: Pode esperar atendimento ou ser encaminhado para outro servico de saude (240 min)\n");

        printf("========================================================\n");
        printf("Digite a urgencia do paciente: ");
        scanf(" %c", &urgencia);

        inserirFila(nome, idade, urgencia, &f);
        break;

      case 'C':

        printf("Digite o nome do paciente sem espacos (ex:JoaodaSilva): ");
        scanf("%s", nome);

        printf("Digite a idade do paciente: ");
        scanf("%d", &idade);

        printf("Digite o tipo de consulta do paciente (ex: dermatologista, dentista, urologista...): ");
        scanf("%s", consulta);

        printf("Dias disponiveis: ");
        for (int i = data_hora_atual->tm_mday; i <= 30; i++) {
          printf("%d ", i);
        }

        printf("\nDia escolhido pelo paciente: ");
        scanf("%d", &day);
          
        while (day>30 || day<data_hora_atual->tm_mday){
          printf ("Por favor, escolha um dia valido: ");
          scanf("%d", &day);
        }

        printf("Os horarios disponiveis sao: \n");

        for (int i = 0; i < 23; i++) {
          if (dia[day - 1].horario[i] && i < 22)
            printf("%02d:%02d - ", dia[day - 1].horario[i] / 60, dia[day - 1].horario[i] % 60);

          else if (dia[day - 1].horario[i] && i == 22)
            printf("%02d:%02d\n", dia[day - 1].horario[i] / 60, dia[day - 1].horario[i] % 60);
        }

        printf("Horario escolhido pelo paciente: ");
        scanf("%d:%d", &Hh, &Mm);
        Mm += Hh * 60;
        dia[day - 1].horario[(Mm - 480) / 30] = 0; 

        inserirElementoLista(&dia[day].l, dia[day].it, Mm, nome, consulta, idade);
        printf ("Consulta agendada com sucesso!\n");
        break;

      case 'S':
        return 0;
        break;

      default:
        printf("Selecione uma opcao valida\n");
        break;
    }
  }
}