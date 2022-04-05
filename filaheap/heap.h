#ifndef HEAP_H
#define HEAP_H

typedef struct nodep{
	int idade;
	NodeP *pai;
	NodeP *filhoEsq;
	NodeP *filhoDir;
	NodeP *proximo;
}NodeP;

typedef struct heap{
	NodeP *inicio;
	NodeP *fim;	
	int tam;	    
} Heap;


Heap* inicializa(Fila *f);

NodeP* encontraPai(Fila *f, NodeP **aux);
//NodeP* encontraFilhoEsq(Node *n, int indice);
//NodeP* encontraFilhoDir(Node *n, int indice);

void AjustaSubindo (Heap h, int indice);

#endif