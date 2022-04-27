#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"
#include "lista.h"

void inicializarDia(dia dia[]) {
  for (int i = 0; i <= 30; i++) {
    dia[i].horario[0] = 480;
    for (int j = 1; j < 23; j++) {
      dia[i].horario[j] = dia[i].horario[0] + (30 * j);
    }
  }
}

void inicializarIteradores(dia dia[]){     
  for (int i = 0; i < 30; i++) {
    inicializarLista(&dia[i].l);
    dia[i].it = primeiro(&dia[i].l);
  }
}

char chooser1(){
    char chooser;
    printf("Para emergencia digite M \nPara abrir a aba de consultas digite C \nPara sair do programa, digite S \nPara ir para Interface do medico digite T \nDigite sua escolha: ");
    scanf(" %c", &chooser);
    return chooser;
} 
char chooser2(){
    char chooser;
    printf("Para ver a agenda, digite A \nPara ver a fila de emergencia, digite E \nPara chamar o proximo paciente do dia na agenda, digite P \nPara chamar o proximo paciente da fila de emergencia, digite Q \nPara ir para Interface do atendente digite T \nDigite sua escolha: ");
    scanf(" %c", &chooser);
    return chooser;
} 

void abaConsulta(dia dia[], struct tm *data_hora_atual){
    char nome[30];
    char consulta[30];
    int idade,day,Hh,Mm;
    char chooser2;

        printf("Para marcar, digite M, para cancelar, digite C: ");
            scanf(" %c", &chooser2);

        switch (chooser2) {
          case 'M':
            printf("Digite o nome do paciente sem espacos (ex:JoaodaSilva): ");
            scanf("%s", nome);

            printf("Digite a idade do paciente: ");
            scanf("%d", &idade);

            printf("Digite o tipo de consulta do paciente (ex: dermatologista, dentista, urologista...): ");
            scanf("%s", consulta);

            printf("Dias disponiveis: ");
            for (int i = data_hora_atual->tm_mday; i <= 30; i++) 
              printf("%d ", i);
            

            printf("\nDia escolhido pelo paciente: ");
            scanf("%d", &day);

            while (day > 30 || day < data_hora_atual->tm_mday) {
              printf("Por favor, escolha um dia valido: ");
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

            inserirElementoLista(&dia[day-1].l, dia[day-1].it, Mm, nome, consulta, idade);
            printf("Consulta agendada com sucesso!\n");

            break;

          default:
            printf("Insira o dia e horario da consulta, Dd(dia)-Hh(horas):Mm(minutos): ");
            scanf("%d-%d:%d", &day, &Hh, &Mm);
            removerElemento(&dia[day-1].l, dia[day-1].it, (Hh*60+Mm));

            dia[day-1].horario[(((Hh*60)+Mm) - 480) / 30] = Hh*60+Mm;

            printf("Os horarios disponiveis sao: \n");

            for (int i = 0; i < 23; i++) {
              if (dia[day - 1].horario[i] && i < 22)
                printf("%02d:%02d - ", dia[day - 1].horario[i] / 60, dia[day - 1].horario[i] % 60);

              else if (dia[day - 1].horario[i] && i == 22)
                printf("%02d:%02d\n", dia[day - 1].horario[i] / 60, dia[day - 1].horario[i] % 60);
            }

            break;
        }
}

void abaEmergencia(Fila *f){
    char nome[30], urgencia;
    int idade;
        printf("Digite o nome do paciente sem espacos (ex:JoaodaSilva): ");
        scanf("%s", nome);

        printf("Digite a idade do paciente: ");
        scanf("%d", &idade);

        printf("Urgencia: \nDigite R para vermelho: Necessita de atendimento imediato \nDigite O para laranja: Necessita de atendimento praticamente imediato (10 min) \nDigite Y para amarelo: Necessita de atendimento rapido, mas pode esperar (50 min) \nDigite G para verde: Pode esperar ou ser encaminhado para outro servico de saude (120 min) \nDigite B para azul: Pode esperar atendimento ou ser encaminhado para outro servico de saude (240 min)\n");

        printf("========================================================\n");
        printf("Digite a urgencia do paciente: ");
        scanf(" %c", &urgencia);

        inserirFila(nome, idade, urgencia, f);
        printf("Paciente inserido na fila de prioridade com urgencia %c bem-sucedida!\n", urgencia);
}