#include "pilha.h"
int main(){
    t_pilha pilha;

    constroi_pilha (5, &pilha); //int capacidade, t_pilha *p
    return 0;
    
    empilha(&pilha, 30);
    exibirDecimaPrabaixo(&pilha);
    int desempilhado;
    desempilha(&pilha, &desempilhado);
    exibirDecimaPrabaixo(&pilha);
    desempilhado = extrai_abaixo_do_topo(&pilha);
    printf("%d estava abaixo do topo\n", desempilhado);
    exibirDecimaPrabaixo(&pilha);
    empilha(&pilha, 15);
    empilha(&pilha, 5);
    exibirDecimaPrabaixo(&pilha);
    amassa_topo(&pilha, 10);
    exibirDecimaPrabaixo(&pilha);
    amassa_pilha(&pilha, 18);
    exibirDecimaPrabaixo(&pilha);
    return 0;
}
