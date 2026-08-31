// pilha.h -> h = head
//arquivo onde esta todos os includes
#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    int * dados; //dados é ponteiro de inteiro
    int topo; //inteiro
    int capacidade;
} t_pilha; //recebe o nome tipo pilha

void constroi_pilha (int, t_pilha *); 
int empilha (t_pilha *, int); //empilha um inteiro, referencia no tipo pilha 
//retorno SUCESSO ou FRCASSO
//parametros: a pilha por referencia (pode ser aletrada) e o inteiro de entrada
int desempilha (t_pilha *, int *);//desempilha do tipo pilha (tem que fazer por referenia * para modificar, isso SEMPRE)
//retorno SUCESSO ou FRACASSO 
//paraemtros: a pilha por referencia (pode ser alterada) e o inteiro por referencia (pode receber o valor que vai sair d a pilha)
int tamanho (t_pilha *); //recebe a pilha por referencia
int esta_vazia (t_pilha *);
int esta_cheia (t_pilha *);