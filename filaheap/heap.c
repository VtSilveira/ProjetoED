#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"

Heap* inicializa(Fila *f){
    Heap *h = malloc(sizeof(Heap));
    h->tam=0;
    h->inicio=f->inicio;
    return h;
}

int encontraPai(NodeP *novo, Fila *f, NodeP *aux){
    int indiceDoNovo = f->h->tam;
    int i=1;
    while(i!=(int)floor(indiceDoNovo/2)){
        aux = (aux)->proximo;
        i++;
    }
    if(i!=1)
        novo->pai=aux;
    else    
        novo->pai=NULL; 

    return i;      
}

*/*NodeP encontraFilhoEsq(Fila *f, NodeP *n, int indice){
    Node *aux=n;
    i=indice
    while(i!=(2*indice)){
        if(aux->proximo==f->inicio) return NULL;
        aux = n->proximo;
        i++;
    }
    return aux;
}

*NodeP encontraFilhoDir(Fila *f, NodeP *n, int indice){
    if(n->filhoEsq->proximo==f->inicio) return NULL;
    else return n->filhoEsq->proximo;
}*/

void AjustaDescendo (Heap h, NodeP *aux){
    NodeP *maior = aux;
    if(aux->filhoEsq && aux->idade > aux->filhoEsq->idade)
        maior = aux->filhoEsq;
    if(aux->filhoDir && aux->idade > aux->filhoDir->idade)
        maior = aux->filhoDir;
    if(maior != aux){
        trocaNodeP(aux, maior);
        AjustaDescendo(h, aux);
    }
}

void AjustaSubindo (Heap h, NodeP *aux){
    if(aux->pai && aux->idade>aux->idade->pai){
        trocaNodeP(aux,aux->pai);
        AjustaSubindo(h,aux);
    }
}


void trocaNodeP(NodeP *a,NodeP *b){
    NodeP *aux = malloc(sizeof(NodeP));

    aux->proximo = a->proximo;
    aux->filhoDir = a->filhoDir;
    aux->filhoEsq = a->filhoEsq;
    aux->idade = a->idade;

    a->proximo=b->proximo;
    a->filhoDir=b->filhoDir;
    a->filhoEsq=b->filhoEsq;
    a->idade=b->idade;

    b->proximo = aux->proximo;
    b->filhoDir = aux->filhoDir;
    b->filhoEsq = aux->filhoEsq;
    b->idade = aux->idade;

    free(aux);
}






