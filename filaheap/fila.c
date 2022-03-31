#include "fila.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool vazia(Fila *f){
    if(f->tam==0)
        return TRUE;
    else
        return FALSE;
}

void insere(Fila *f, int idade){
    if(idade<60){
        Node *novo = malloc(sizeof(Node));
        novo->idade=idade;
        if(novo){
            f->tam++;
            f->fim->proximo = novo;
            f->fim = novo;
            novo->proximo = NULL;
        }
    }
    else{
        NodeP *aux, *novo = malloc(sizeof(NodeP));

        if(!f->h){//se não tem heap, cria
            Heap *h = inicializa(f);
            f->h = h;
            f->h->inicio = f->h->fim = novo;
            novo->proximo = NULL;
        }
        
        novo->idade=idade;
        if(novo){
            f->h->tam++;
            f->tam++;
            novo->filhoEsq = novo->filhoDir = NULL;
            int indicePai = encontraPai(f,&f->h->inicio);

            if(f->h->tam == indicePai*2)
                aux->filhoEsq = novo;
            if(f->h->tam == indicePai*2 + 1)
                aux->filhoDir = novo;

            AjustaSubindo(Heap h, int indice);

        }
    }
}

void remove(Fila *f, int idade){
    Node *aux;
    if(f->h->inicio){
        aux=f->h->inicio;
        trocaNodeP(f->h->inicio, f->h->fim);
        AjustaDescendo(f->h,f->h->inicio);
        f->h->tam--;
    }     
    else{
        aux=f->inicio;
        f->inicio=aux->proximo;
        f->tam--;
    }    
    free(aux);
}

int tam(Fila *f){
    return f->tam;
}