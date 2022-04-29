#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Bibliotecas criadas
#include "fila.h"
#include "lista.h"
#include "utils.h"

int main() {
  char chooser;
  dia dia[31];
  Fila f;
  int escolheInterface;

  //Instruções da biblioteca time.h para utilizarmos hora e data em tempo real.
  struct tm *data_hora_atual;
  inicializarDia(dia);
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);

  //Inicialização da Fila de Prioridade e dos Iteradores de todos os dias.
  inicializarFila(&f);
  inicializarIteradores(dia);

  //Seleção de Interface (Interface do(a) medico(a) ou do(a) atendente).
  printf("Para entrar na interface do(a) medico(a), digite 0, para entrar na interface do(a) atendente, digite 1: ");
  scanf("%d", &escolheInterface);

  //Loop que mantém o programa rodando, podendo ser realizada a troca entre interfaces 
  while (1) {
    //Abre a interface do(a) médico(a).
    while (!escolheInterface) {
      printf("===========Interface do(a) medico(a)===========\n");
      //Printa as opções disponíveis para o(a) médico(a).
      chooser = chooser2();

      switch (chooser) {
        //Imprime a lista de consultas no dia atual.
        case 'A':
          imprimirLista(&dia[data_hora_atual->tm_mday - 1].l);
          break;
        
        //Imprime a fila de espera para atendimento de emergência.
        case 'E':
          imprimeFila(&f);
          break;
        
        //Chama paciente com horário agendado e o retira da agenda.
        case 'P':
          removerInicioLista(&dia[data_hora_atual->tm_mday - 1].l);
          printf("Paciente chamado e retirado da agenda com sucesso!\n");
          break;

        //Chama próximo da fila de atendimento de emergência e o remove da fila.
        case 'Q':
          retirarFila(&f);
          printf("Paciente chamado e retirado da fila de emergencia com sucesso!\n");
          break;

        //Troca para a interface de atendente.
        case 'T':
          escolheInterface = 1;

          break;

        //Mensagem de erro caso uma opção inválida seja escolhida.
        default:
          printf("Selecione uma opcao valida\n");
          break;
      }
    }

    while (escolheInterface) {
      //Abre a interface do(a) atendente.
      printf("===========Interface do atendente===========\n");
      //Printa as opções disponíveis para o(a) atendente.
      chooser = chooser1();
      
      switch (chooser) {
        //Abre a aba de atendimento de emergência.
        case 'M':
          abaEmergencia(&f);
          break;

        //Abre a aba de agendamento/cancelamento de consulta.
        case 'C':
          abaConsulta(dia, data_hora_atual);
          break;

        //Destrói as agendas(listas) de todos os dias, a fila do dia atual e encerra o programa.
        case 'S':
          destruirFila(&f);
          for (int i = 0; i < 30; i++) {
            destruirLista(&dia[i].l);
          }
          return 0;
          break;

        //Troca para a interface do(a) médico(a).
        case 'T':
          escolheInterface = 0;

          break;

        //Mensagem de erro caso uma opção inválida seja escolhida.
        default:
          printf("Selecione uma opcao valida\n");
          break;
      }
    }
  }
}