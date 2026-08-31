//quando se usa "" -> diz que é para retirar de onde selecionamos 
#include "pilha.h" // implementa da pasta pilha.h 
void constroi_pilha (int capacidade, t_pilha *p){ //ponteiro de tipo pilha 
    p -> dados = (int *) malloc(sizeof(int) *capacidade); //malloc te da o endereço de memoria, sizeof = quantidade que o usuario declara 
    p -> topo = 0; 
    p -> capacidade = capacidade; //vefificar se o vetor esta cheio 
} 
int empilha (t_pilha *p, int i){
    if (esta_cheio(p)) return FRACASSO;
    //if (!esta_cheia(p)){ //se nao esta cheio
        p->dados[p -> topo] = i; //ponteiro aponta para os dados, vai ao ultimo que é o topo, e adiciona
        p -> topo++;
        return SUCESSO; 
     //}
}
int desempilha (t_pilha *p, int *i){
    if(esta_vazia(p)) return FRACASSO;
    p -> topo--; //descer o topo, pq o topo é vazio, entao precisa descer para a que esta preenchida 
    *i = p -> dados[p-> topo];
    return SUCESSO;
}
int tamanho (t_pilha *p){
    return p -> topo; //tamanho == topo
} 
int esta_vazia (t_pilha *p){
    return p -> topo == 0; 
}
int esta_cheia (t_pilha *p){
    return p -> topo == p -> capacidade; //MESMA ESTRUTURA DO IF ELSE
    //if(p -> topo == p -> capacidade) // se o tpo for igual a capacidade = esta cheio
      //  return 1;
    //else //se nao, ainda nn esta cheio
    //    return 0;
};