#include <stdio.h>
#include <stdlib.h>

//anotacao: casting -> muda o tipo
typedef struct{  //definir as diretrizws 
    int *v; //refeencia de vetor (v -> ponteiro de estrutura)
    int ocupacao; //(ocupacao -> inteiro)
    int capacidade;
} t_vetor; //tipo vetor 

//void : nn tem retorno, ela inicia 
void inicia_vetor (t_vetor *, int); //recebe como parametro o tipo vetor e a capacidade
int esta_cheio (t_vetor *);

//funcao pricipal
int man (){
    // tem dois atributos : ocupacao e v
    t_vetor  vetor; //minha variavel vetor, e do tipo vetor
    printf("digite a capacidade do vetor: ");
    int capacidade; //para armazenar o valor do usuario
    printf("endereco da estrutura: %p\n", &vetor);
    scanf("%d", &capacidade);
    inicia_vetor (&vetor, capacidade); // &:referencia 
    return 0;
}

//funcao auxiliares
void inicia_vetor (t_vetor *p_vetor, int capacidade) {
    p_vetor -> v = (int *) malloc (capacidae * sizeof(int)); //queremos que seja um ponteiro de inteiros, saltando de 4 em 4
    printf("endereco do vetor dentro da estrutura: %p", p_vetor -> v);
    p_vetor -> ocupacao = 0;
    p_vetor -> capacidade = capacidade;
}
int esta_cheio (t_vetor *p_vetor){
    if (p_vetor -> capacidade == p_vetor -> ocupacao)
        return 1;
    else
        return 0;
}