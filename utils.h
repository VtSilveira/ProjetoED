#ifndef UTILS_H
#define UTILS_H
#include "fila.h"
#include "lista.h"
#include <time.h>


//A struct dia possui um inteiro "index" para informar o dia do mês (index = dia-1. Exemplo: Dia 26, index 25).
//Possui um vetor de inteiros "horario[23]" para guardar todos os horários disponíveis no dia (horários vão das 08h00 até //19h00, variando em 30 minutos.
//Possui uma lista "l", que serve como agenda de consultas para o dia.
//Possui um iterador para a lista do dia.
typedef struct dia {
  int index;
  int horario[23];
  lista l;
  Iterador *it;
} dia;

//inicializa as agendas dos dias do mes
void inicializarDia(dia dia[]);
//inicializa os iteradores
void inicializarIteradores(dia dia[]);
//funcao que escolhe as opcoes da interface do atendente
char chooser1();
//funcao que escolhe as opcoes da interface do medico
char chooser2();
//funcao que abre os requisitos para marcar ou cancelar uma consulta, baseado no dia atual
void abaConsulta(dia dia[], struct tm *data_hora_atual);
//funcao que abre os requisitos para inserir um paciente na fila de emergencia
void abaEmergencia(Fila *f);


#endif