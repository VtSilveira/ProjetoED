#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "lista.h"
//Optamos por criar uma nova API para a lista ordenada para facilitar a leitura e por organizacao e modularizacao do codigo

//insere na lista ordenada
void insereListaOrdenada(lista *l, Iterador *i, int num, Iterador *(*ordena)(int valor, Iterador *i, lista *l));

//imprime a lista ordenada
void imprimirListaOrdenada(lista *l);
//funcao de ordenacao
Iterador *ordenalista(int valor, Iterador *i, lista *l);
//insere no inicio da lista ordenada
void inserirInicioListaOrdenada(lista *l, int num);
//Insere antes de um elemento na lista ordenada
void inserirAntesListaOrdenada(lista *l, Iterador *i, int valor);

#endif