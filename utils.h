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

void inicializarDia(dia dia[]);
void inicializarIteradores(dia dia[]);
char chooser1();
char chooser2();
void abaConsulta(dia dia[], struct tm *data_hora_atual);
void abaEmergencia(Fila *f);


#endif