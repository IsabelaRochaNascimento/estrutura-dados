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
int desempilha (t_pilha *p, int *i){ //pilha e um inteiro por referencia 
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
void exibirDecimaPrabaixo(t_pilha *p){ 
    if(esta_vazia(p)){ //tratamento para verificar se a pilha esta vazia
        printf("pilha vazia\n");
    }
    for(int i = p -> topo; i >= 0; i--){ 
        printf("[%2d]: %d\n", i+1, p ->dados[i]);
    }
} 
int extrai_abaixo_do_topo(t_pilha *p){ //extrair o elemento abaixo do topo, se possivel
    if(tamanho(p) < 2){ //se o tamanho da pilha for menor que 2, nn da pra realizar!!
        return -1;
    }else{
        int aux, que_sai; //que_sai = ele vai tirar o abaixo do promto | aux = o ultimo
        desempilha(p, &aux);//passa a pilha e o auxiliar por referencia
        desempilha(p, &que_sai); //desempilhou o que sai da pilha 
        empilha(p, aux); //empilha novamente o ultimo, ja que tirou o que estava abaixo
        return que_sai;
    }
} 
int valor_topo(t_pilha *p){
    //considerando que: quem fez a chamada testou pilha vazia
    return p->dados[p->topo -1]; //p->topo -1 = para ver o elemento que esta no topo (o ultimo elemento)
}
void amassa_topo(t_pilha *p, int i){ //retira se o i for maior que o seu anterior e assim vai..
    if(!esta_vazio(p) && valor_topo(p) >= i){ //se a pilha NAO estiver vazia E o valor do topo for maior igual a i
        int aux;
        desempilha(p, &aux);
    } 
    empilha(p, i); //so empilha 

}
