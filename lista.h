#ifndef LISTA_H
#define LISTA_H

typedef struct node Node;
typedef struct lista lista;

void inicializarlista(lista *l);
void inserir_no_inicio(lista *l, int num);
void destruir(lista *l);
int vazia(lista *l);
void removerInicio(lista *l);
void removerFinal(lista *l);
void inserir_no_final(lista *l, int num);
void inserir_meio_dps(lista *l, int num, int ant);
void inserir_meio_antes(lista *l, int num, int depois);
void imprimir(Node *node);

#endif