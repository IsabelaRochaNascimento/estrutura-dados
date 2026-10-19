#include "no.h"

//definir tipo lista
typedef struct lista{
   struct no *primeiro;
   int tamanho;
} t_lista ;

//
void inicia_lista(t_lista * ); //tipo lista por referencia 
int lista_vazia (t_lista *); //teste da lista 
void insere_inicio(int, t_lista *); //primeira operacao de insercao de elementos, int para o elemento e t_lista para a lista 
void exibe_lista(t_lista *); //exibir a lista 
int remove_inicio(t_lista *); //remover o primeiro
void insere_fim(int, t_lista *); //insere com o ponteiro apontado para o final
int remove_fim(t_lista *); //remove o final 

