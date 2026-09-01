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
void exibir_pilha (t_pilha *);
int empilha (t_pilha *, int);
int esta_vazia (t_pilha *);
int esta_cheia (t_pilha *);

void constroi_pilha (int capacidade, t_pilha *p){ //ponteiro de tipo pilha 
    p -> dados = (int *) malloc(sizeof(int) *capacidade); //malloc te da o endereço de memoria, sizeof = quantidade que o usuario declara 
    p -> topo = 0; 
    p -> capacidade = capacidade; //vefificar se o vetor esta cheio 
} 
void exibir_pilha(t_pilha *p){
    for(int i = p -> topo - 1; i >= 0; i-- ){ // p->topo -1 = índice do elemento do topo, onde o valor esta guardado e sempre um amneos
        //i >= 0 = pq o menor valor do topo é 0
        //i -- = pq esta diminu8indo
        printf("Pilha do topo para baixo: %d\n", p->dados[i]); //mostra o valor guardado, não a posição
    }
} 
int empilha (t_pilha *p , int i){
    if(esta_cheia(p)) return FRACASSO; //verifica se esta cheia antes de guardar, para nn estourar o vetor
    p -> dados[p -> topo] = i; //ponteiro aponta para os dados, que depois guarda o valor no topo 
    p ->topo++; //incrementa no topo antes de guardar
    return SUCESSO;
} 
int esta_cheia (t_pilha *p){
    return p -> topo == p -> capacidade;
    //if(p -> topo == p -> capacidade)
      //  return 1;
   // else return 0;
}
int esta_vazia (t_pilha *p){
    return p -> topo != p-> capacidade;
}
  
    
