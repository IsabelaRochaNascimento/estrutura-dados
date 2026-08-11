#include <stdio.h>
#include <stdlib.h>

#define FRACASSO 0
#define SUCESSO 1

//anotacao: casting -> muda o tipo
typedef struct{  //definir as diretrizws 
    int *v; //refeencia de vetor (v -> ponteiro de estrutura)
    int ocupacao; //(ocupacao -> inteiro)
    int capacidade;
} t_vetor; //tipo vetor 

//void : nn tem retorno, ela inicia 
void inicia_vetor (t_vetor *, int); //recebe como parametro o tipo vetor e a capacidade
int esta_cheio (t_vetor *);
int esta_vazio (t_vetor *);
int insere (t_vetor *, int);
void exibe_vetor (t_vetor *, char *);
int remove_elemento (t_vetor *, int *); //o retorno é sucesso ou fracasso, o elemneto qeu sai, vem pro parametro referencia

//funcao pricipal
int main (){
    // tem dois atributos : ocupacao e v
    t_vetor  vetor; //minha variavel vetor, e do tipo vetor
    printf("digite a capacidade do vetor: ");
    int capacidade; //para armazenar o valor do usuario
    printf("endereco da estrutura: %p\n", &vetor);
    scanf("%d", &capacidade);
    inicia_vetor (&vetor, capacidade); // &:referencia 
    if (insere(&vetor, 10)) { //se for verdadeiro
        printf("10 inserido com sucesso!\n");
    }else{
        printf("Nao foi possivel realizar a insercao\n");
    }
    insere (&vetor, 20);
    exibe_vetor (&vetor, "meu vetor");
    t_vetor outro;
    inicia_vetor (&outro, 5);
    exibe_vetor (&outro, "outro vetor");
    
    return 0;
}

//funcao auxiliares
void inicia_vetor (t_vetor *p_vetor, int capacidade) { //p_vetor -> ponteiro tipo vetor
    p_vetor -> v = (int *) malloc (capacidade * sizeof(int)); //queremos que seja um ponteiro de inteiros, saltando de 4 em 4
    printf("endereco do vetor dentro da estrutura: %p\n", p_vetor -> v);
    p_vetor -> ocupacao = 0;
    p_vetor -> capacidade = capacidade;
}
int esta_cheio (t_vetor *p_vetor){
    if (p_vetor -> capacidade == p_vetor -> ocupacao)
        return 1;
    else
        return 0;
}
int esta_vazio (t_vetor *p_vetor){
    //if(p_vetor -> ocupacao == 0)
      //return 1;
        //return 0;
    return p_vetor -> ocupacao == 0;
}


int insere (t_vetor *p_vetor, int valor){
    if (esta_cheio(p_vetor)){
        return FRACASSO;
    } else{
        p_vetor -> v[p_vetor-> ocupacao] = valor;
        p_vetor -> ocupacao++;
        return SUCESSO;
    }
}
void exibe_vetor (t_vetor *p_vetor, char * msg){
    printf("\n%s\n", msg);
    printf("ocupacao = %d\n", p_vetor-> ocupacao);
    printf("capacidade = %d\n", p_vetor-> capacidade);
    printf("o vetor: ");
    for(int i=0; i < p_vetor->ocupacao; i++)
        printf("%d ",p_vetor->v[1]);
    for(int i=p_vetor->ocupacao; i< p_vetor->capacidade; i++)
        printf("__ ");
    printf("\n");
}
