#include <stdio.h>
#include <time.h>
#include "lista.h"


int main(){
    int Hh,Mm;
    lista l;
    printf ("Insira o horario (hh:mm): ");
    scanf ("%d:%d", &Hh,&Mm);
    Mm += Hh*60;
    inicializarLista(&l);
    inserirInicioLista(&l, Mm);
    return (0);
}