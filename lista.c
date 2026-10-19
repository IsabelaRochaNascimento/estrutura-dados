#include "lista.h"

//struct lista tem o tamanho e o ponteiro 
//para acessar o tamanho, tem que acessar lista e o mesmo para saber a posicao 
//lista -> tamanho = 0
//lista -> primeiro = NULL;
void inicia_lista(t_lista *lista){
    lista -> primeiro = NULL;
    lista -> tamanho = 0;
}

int lista_vazia (t_lista *lista){
    return lista -> tamanho == 0; //testa, faz a mesma coisa qeu o if 
    //if(lista-> tamanho == 0){ //teste para verificar se a lista esta vazia 
    //    return 1;
    //} else{
    //    return 0;
    //} 
}
void insere_inicio(int i, t_lista *lista){
    struct no * novo = controi_no(i);//criar um no

    if(!lista_vazia(lista)){ //se a lista nao for vazia
        novo -> prox = lista -> primeiro;
    }
    lista -> primeiro = novo;
    lista -> tamanho ++;
} 
void exibe_lista(t_lista *lista){
    if(lista_vazia(lista)){ //ja faz a verificacao se esta vazia 
         printf("lista esta vazia\n");
    }else{
        struct no * percorre = lista -> primeiro; //percorre recebe o endereco do primeiro no
        while(percorre != NULL){ //enquanto o ponteiro percorre for diferente de null, ele exibe o dado 
            printf("%d -> ", percorre -> info);
            percorre = percorre ->prox; //agora o percorre aponta paraa a proxima caixinha
        } 
        printf("//\n");     
    }
}
int remove_inicio(t_lista *lista){
    int aux_info = lista -> primeiro -> info; 
    struct no * aux_primeiro = lista -> primeiro ; //guardar o endereco de no do primeiro
    lista -> primeiro = lista -> primeiro -> prox; // na estrutura uwe lista aponta e vai modificar o endereco do primeiro
    free(aux_primeiro); //liberou a regiao que o endereco aponta 
    lista->tamanho --; //diminui 
    return aux_info; //e depois retorna 
}
void insere_fim(int i, t_lista *lista){
    struct no * novo = cronstroi_no(i); //criar caixinha para adiocanr valor 
    if(lista_vazia(lista)){
        lista -> primeiro = novo;
    }else{    
        struct no * percorre = lista ->primeiro;
    while(percorre -> prox != NULL){ //enqunato o percorre proximo for diferente de null, para saber o ultimo, ou seja, o laco le ate o ultimo
        percorre = percorre -> prox; 
    } 
    percorre -> prox = novo; //atualizou o valor do proximo
    }
    lista ->tamanho++;
}     
int remove_fim(t_lista *lista){
    int aux;
    if(lista -> tamanho == 1){ //testando pr aver se tem um só
        aux = lista -> primeiro -> info; //pega a informacao do primeiro da lista 
        free(lista -> primeiro); //libera o primeiro 
        lista -> primeiro = NULL; //atualiza para NULL
    }else{
        struct no * percorre = lista -> primeiro;
        while(percorre -> prox -> prox != NULL){ //olhar dois para frente, esta no pnultimo saindo do laço
          percorre = percorre -> prox;
    }
    aux = percorre -> prox -> info;
    free(percorre -> prox); //libera o da frente
    percorre -> prox = NULL; //atualiza o ponteiro
    }
    lista -> tamanho --; //tira um
    return aux;
}