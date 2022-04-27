#ifndef UTILS_H
#define UTILS_H
#include "fila.h"
#include "lista.h"
#include <time.h>

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