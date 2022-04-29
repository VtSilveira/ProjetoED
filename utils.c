#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"
#include "lista.h"

//Função que inicializa as agendas de todos os dias de um mês comercial.
void inicializarDia(dia dia[]) {
  for (int i = 0; i <= 30; i++) {
    dia[i].horario[0] = 480;
    inicializarLista(&dia[i].l);
    dia[i].it = primeiro(&dia[i].l);
    for (int j = 1; j < 23; j++) {
      dia[i].horario[j] = dia[i].horario[0] + (30 * j);
    }
  }
}

//Função que disponibiliza, para o(a) atendente todas as opções disponíveis e retorna a opção escolhida.
char chooser1(){
    char chooser;
    printf("Para emergencia digite M \nPara abrir a aba de consultas digite C \nPara sair do programa, digite S \nPara ir para Interface do medico digite T \nDigite sua escolha: ");
    scanf(" %c", &chooser);
    return chooser;
} 

//Função que disponibiliza, para o(a) médico(a) todas as opções disponíveis e retorna a opção escolhida.
char chooser2(){
    char chooser;
    printf("Para ver a agenda, digite A \nPara ver a fila de emergencia, digite E \nPara chamar o proximo paciente do dia na agenda, digite P \nPara chamar o proximo paciente da fila de emergencia, digite Q \nPara ir para Interface do atendente digite T \nDigite sua escolha: ");
    scanf(" %c", &chooser);
    return chooser;
} 

//Função que abre a aba de consulta para o(a) atendente.
void abaConsulta(dia dia[], struct tm *data_hora_atual){
    char nome[30];
    char consulta[30];
    int day,Hh,Mm;
    char chooser2;

        printf("Para marcar, digite M, para cancelar, digite C: ");
            scanf(" %c", &chooser2);

        switch (chooser2) {
          //Agenda um horário para o paciente de acordo com os dias e horários disponíveis no mês.
          //Dias disponíveis são o dia atual e os dias restantes do mês.
          //Horários disponíveis são aqueles que não possuem paciente marcado.
          case 'M':
            //Recebe nome do paciente.
            printf("Digite o nome do paciente sem espacos (ex:JoaodaSilva): ");
            scanf("%s", nome);

            //Recebe o tipo de consulta que o paciente deseja agendar.
            printf("Digite o tipo de consulta do paciente (ex: dermatologista, dentista, urologista...): ");
            scanf("%s", consulta);

            //Printa os dias disponíveis para o paciente.
            printf("Dias disponiveis: ");
            for (int i = data_hora_atual->tm_mday; i <= 30; i++) 
              printf("%d ", i);
            
            //Recebe o dia escolhido pelo paciente.
            printf("\nDia escolhido pelo paciente: ");
            scanf("%d", &day);

            //Mensagem de erro caso o(a) atendente selecione um dia inválido.
            while (day > 30 || day < data_hora_atual->tm_mday) {
              printf("Por favor, escolha um dia valido: ");
              scanf("%d", &day);
            }

            //Printa os horários disponíveis no dia escolhido pelo paciente.
            //Os horários indisponíveis possuem valor 0 na agenda ao invés do horário em si.
            printf("Os horarios disponiveis sao: \n");
            for (int i = 0; i < 23; i++) {
              if (dia[day - 1].horario[i] && i < 22) //Verifica se o horário na agenda é diferente de 0 e não é o último                                                       horário.
                printf("%02d:%02d - ", dia[day - 1].horario[i] / 60, dia[day - 1].horario[i] % 60);

              else if (dia[day - 1].horario[i] && i == 22)//Verifica se o horário da agenda é diferente de 0 e é o último                                                           horário.
                printf("%02d:%02d\n", dia[day - 1].horario[i] / 60, dia[day - 1].horario[i] % 60);
            }

            //Recebe o horário escolhido pelo paciente em Hh:Mm.
            printf("Horario escolhido pelo paciente: ");
            scanf("%d:%d", &Hh, &Mm);
            Mm += Hh * 60; //Converte o horário escolhido para minutos.
            dia[day - 1].horario[(Mm - 480) / 30] = 0; //Coloca o horário como indisponível.

            //Insere o horário na agenda de horários marcados.
            inserirElementoLista(&dia[day-1].l, dia[day-1].it, Mm, nome, consulta);
            printf("Consulta agendada com sucesso!\n");

            break;

          
          //Desmarca uma consulta já marcada na agenda e disponibiliza novamente o horário.
          default:
            //Recebe o dia e o horário da consulta que será desmarcada.
            printf("Insira o dia e horario da consulta, Dd(dia)-Hh(horas):Mm(minutos): ");
            scanf("%d-%d:%d", &day, &Hh, &Mm);
            //Remove a consulta da agenda.
            removerElemento(&dia[day-1].l, dia[day-1].it, (Hh*60+Mm));

            //Disponibiliza novamente o horário.
            dia[day-1].horario[(((Hh*60)+Mm) - 480) / 30] = Hh*60+Mm;
            break;
        }
}

//Função que abre a aba de emergência para o(a) atentende.
void abaEmergencia(Fila *f){
    char nome[30], urgencia;
    int idade;
        //Recebe o nome do paciente.
        printf("Digite o nome do paciente sem espacos (ex:JoaodaSilva): ");
        scanf("%s", nome);

        //Recebe a idade do paciente.
        printf("Digite a idade do paciente: ");
        scanf("%d", &idade);

        //Mostra e explica os tipos de urgência.
        printf("Urgencia: \nDigite R para vermelho: Necessita de atendimento imediato \nDigite O para laranja: Necessita de atendimento praticamente imediato (10 min) \nDigite Y para amarelo: Necessita de atendimento rapido, mas pode esperar (50 min) \nDigite G para verde: Pode esperar ou ser encaminhado para outro servico de saude (120 min) \nDigite B para azul: Pode esperar atendimento ou ser encaminhado para outro servico de saude (240 min)\n");

        printf("========================================================\n");

        //Recebe o tipo de urgência do paciente de acordo com as informações anteriores.
        printf("Digite a urgencia do paciente: ");
        scanf(" %c", &urgencia);

        //Coloca o paciente na fila de atendimento de emergência.
        inserirFila(nome, idade, urgencia, f);
        printf("Paciente inserido na fila de prioridade com urgencia %c bem-sucedida!\n", urgencia);
}