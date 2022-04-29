/*Nomes: Andre Luis Zitelli Rettondini, Sergio Neres Pereira Junior, Vitor Silveira*/
//Antes de ler o arquivo, recomendo ler o arquivo resumoprojeto.pdf.
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Essa função apenas inicializa a Fila, colocando tamanho zero, fim e inicio nulos.
void inicializarFila(Fila *f) {
  f->tam = 0;
  f->fim = NULL;
  f->inicio = NULL;
}


void inserirFila(char nome[],int idade, char urgencia, Fila *f) {
  //É feita a alocação de um novo nó e as devidas instancias dos nós são passadas: idade e urgência.
  NodeF *novo = (NodeF *)malloc(sizeof(NodeF));
  novo->idade = idade;
  strcpy(novo->nome, nome);
  
  //A urgência é ajustada para facilitar a implementação da prioridade da fila e caso a pessoa atendida seja um idoso, sua urgencia será, no minímo, verde ((G)reen == B).
  novo->urgencia = ajustaUrgenciaFila(urgencia);
  if((novo->idade >= 60) && (novo->urgencia <'B'))
    novo->urgencia = 'B';
  
  //Como a inserção na fila é feita no final e o fixUp corrige possíveis alterações necessárias, os filhos são nulos e o próximo também.
  novo->filhoDir = NULL;
  novo->filhoEsq = NULL;
  novo->proximo = NULL;

  //Se a fila for bem alocada, continua, se não printa mensagem de erro.
  if (novo) {
    //Se a fila estiver vazia, o fim e inicio da fila recebem o elemento inserido, além do index ser atualizado e o pai do elemento ser definido como o próprio elemento.
    if (vaziaFila(f)) {
      f->tam++;
      f->fim = novo;
      f->inicio = novo;
      novo->pai = novo;
      novo->index = f->tam;
      novo->anterior = NULL;
    //Se a fila não estiver vazia
    } else {
      novo->anterior = f->fim;
      f->tam++;
      f->fim->proximo = novo;
      f->fim = novo;
      novo->index = f->tam;
      novo->pai = encontraPai(f,novo);

      /*Atualizando o índice filho do pai do elemento recebido. Se o index do novo elemento for exatamente a multiplicação do index do pai por 2, será o filho da esquerda, se não, será o filho da direita.
      if (novo->pai->index * 2 == novo->index)
        novo->pai->filhoEsq = novo;
      else
        novo->pai->filhoDir = novo;*/
      atualizaFilhos(novo);
      
      //Feito o fixUp para atualizar a prioridade da lista
      fixUpFila(f, novo);
    }
  } else {
    printf("A memoria nao foi alocada corretamente.\n");
  }
}


void retirarFila(Fila *f) {
  //Primeiramente inverte-se o fim da lista com o começo, para retirar o último (que agora é o primeiro).
  trocaNodeFila(f->fim, f->inicio);

  //Aqui é feita a atualização dos índicies dos filhos do pai do elemento que vai ser retirado, se ele for o filho da esquerda, terá index par e consequentemente o pai do elemento não vai mais ter filhoEsq, se não, será o filhoDir.
  if (f->fim->index%2 == 0)
    f->fim->pai->filhoEsq = NULL;
  else
    f->fim->pai->filhoDir = NULL;
  
  f->fim = f->fim->anterior;

  //Como o fim pode ser nulo, essa condição é feita para garantir que não será acessada memória não permitida
  if (f->fim)
    f->fim->proximo = NULL;
  
  //O tamanho da fila é decrementado e é feito o Heapfy Top-Down, pois o elemento desbalanceado estará no topo da lista.
  f->tam--;
  ajustaHeapDownFila(f, f->inicio);
}

//Função recursiva fixUp
void fixUpFila(Fila *f, NodeF *n) {
  //Caso base consiste em: o pai do elemento é diferente de si mesmo.
  if (n->pai != n) {
    //Caso as urgencias sejam iguais, o desempate é feito pela idade.
    if (n->urgencia == n->pai->urgencia) {
      if (n->idade > n->pai->idade) {
        //Feito a troca de node e chamado o fixUp novamente, mas com o pai do elemento.
        trocaNodeFila(n, n->pai);
        fixUpFila(f, n->pai);
      }
      //Caso em que as urgencias são diferentes
    } else if (n->urgencia > n->pai->urgencia) {
      //Feito a troca de node e chamado o fixUp novamente, mas com o pai do elemento.
      trocaNodeFila(n, n->pai);
      fixUpFila(f, n->pai);
    }
  }
}

//Checa se o tamanho da fila é zero. Se sim, está vazia.
int vaziaFila(Fila *f) {
  return f->tam == 0;
}

//Essa função é apenas um swap das urgencia e idade do node para que as operações funcionem corretamente.
void trocaNodeFila(NodeF *a, NodeF *b) {
  NodeF *aux = (NodeF *)malloc(sizeof(NodeF));

  aux->idade = a->idade;
  aux->urgencia = a->urgencia;
  strcpy(aux->nome,a->nome);


  a->idade = b->idade;
  a->urgencia = b->urgencia;
   strcpy(a->nome,b->nome);


  b->idade = aux->idade;
  b->urgencia = aux->urgencia;
  strcpy(b->nome,aux->nome);

  free(aux);
}

//O ajusta urgencia foi colocado para facilitar a implementação, onde o (R)ed, maior urgencia, é substituido por E, (O)range por D [...], para que os codigos ASCII associados sirvam como o elemento que vai ser comparado. 
char ajustaUrgenciaFila(char urgencia) {
  switch (urgencia) {
    case 'R':
      return 'E';
    case 'O':
      return 'D';
    case 'Y':
      return 'C';
    case 'G':
      return 'B';
    case 'B':
      return 'A';
    default:
      return 'Z';
  }
}


void ajustaHeapDownFila(Fila *f, NodeF *n) {
  NodeF *maior = n;
  if (n->filhoEsq) {
    //Se o filho da esquerda não é nulo, será comparada a urgencia de 'n' com seu filho da esquerda, caso iguais, a idade desempatará. Caso diferentes, o de maior urgencia será atribuído ao node maior.
    if (n->urgencia == n->filhoEsq->urgencia) {
      if (n->idade < n->filhoEsq->idade) {
        maior = n->filhoEsq;
      }
    } else if (n->urgencia < n->filhoEsq->urgencia) {
      maior = n->filhoEsq;
    }
  }

  //Aqui será feito o mesmo processo feito acima, usando o maior e o filho da direita como referencias. 
  if (n->filhoDir) {
    if (maior->urgencia == n->filhoDir->urgencia) {
      if (maior->idade < n->filhoDir->idade) {
        maior = n->filhoDir;
      }
    } else if (maior->urgencia < n->filhoDir->urgencia) {
      maior = n->filhoDir;
    }
  }

  //Caso base da recursão, quando o maior for igual ao node passado como argumento na função, siginifica que ele está no lugar certo.
  if (maior != n) {
    trocaNodeFila(n, maior);
    ajustaHeapDownFila(f, maior);
  }
}

//Destruição da lista baseada nas funções vazia e retirar. Se ela estiver vazia ao fim, será exibida a mensagem de sucesso, se não, a de erro.
void destruirFila(Fila *f){
  while (!vaziaFila(f))
    retirarFila(f);

  free(f->inicio);
}

//Imprime a fila! :D
void imprimeFila(Fila *f){
  int i=0;
  if (vaziaFila(f))
    printf ("A fila esta vazia!\n\n");
  else
    printf ("A: Azul\nB: Verde\nC: Amarelo\nD: Laranja\nE: Vermelho\nNome - Idade - Urgencia\n");
    
  NodeF *aux = f->inicio;
  while(i<f->tam){
       printf("%s - %d - %c\n", aux->nome, aux->idade, aux->urgencia);
       aux=aux->proximo;
       i++;
   }
}

NodeF *encontraPai (Fila *f,NodeF *n){
  NodeF *aux = f->inicio;

      //Encontra pai pela relação pai-filho. Enquanto 'i' for diferente do index do pai, o auxiliar percorre a fila, até que o pai seja encontrado. Ao fim, o pai do novo elemento recebe o auxiliar. Esse auxiliar não precisará ser desalocado pois ele não foi alocado dinamicamente. 
      int i = 1;
      while (i != (n->index / 2)) {
        aux = aux->proximo;
        i++;
      }
      return aux;
}

void atualizaFilhos(NodeF *n){
      //Atualizando o índice filho do pai do elemento recebido. Se o index do novo elemento for exatamente a multiplicação do index do pai por 2, será o filho da esquerda, se não, será o filho da direita.
      if (n->pai->index * 2 == n->index)
        n->pai->filhoEsq = n;
      else
        n->pai->filhoDir = n;
}