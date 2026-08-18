#include <stdio.h>
#include <stdlib.h>

#define FRACASSO 0
#define SUCESSO 1
#define CAPACIDADE_MINIMA 10

//anotacao: casting -> muda o tipo
typedef struct{  //definir as diretrizws 
    int *v; //refeencia de vetor (v -> ponteiro de estrutura)
    int ocupacao; //(ocupacao(diz quantos elementos tem) -> inteiro)
    int capacidade;
} t_vetor; //tipo vetor 

//void : nn tem retorno, ela inicia 
void inicia_vetor (t_vetor *, int); //recebe como parametro o tipo vetor e a capacidade
int esta_cheio (t_vetor *);
int esta_vazio (t_vetor *);
void insere (int, t_vetor *);
void exibe_vetor (t_vetor *, char *);
int remove_elemento (t_vetor *, int *); //o retorno é sucesso ou fracasso, o elemneto qeu sai, vem pro parametro referencia
void limpa_vetor (t_vetor *); 
int busque_elemento(t_vetor *p_vetor, int elemento);

//funcao pricipal
int main (){
    // tem dois atributos : ocupacao e v
    t_vetor  vetor; //minha variavel vetor, e do tipo vetor
    printf("digite a capacidade do vetor: ");
    int capacidade; //para armazenar o valor do usuario
    printf("endereco da estrutura: %p\n", &vetor);
    scanf("%d", &capacidade);
    inicia_vetor (&vetor, capacidade); // &:referencia 
    //if (insere(10, &vetor)) { //se for verdadeiro
      //  printf("10 inserido com sucesso!\n");
    //}else{
       // printf("Nao foi possivel realizar a insercao\n");
    //}
    //insere (20,&vetor);
    //exibe_vetor (&vetor);
    //t_vetor outro;
    //exibe_veetor (&outro, "outro vetor");
    // inicia (&outro, 5);
    for(int i= 1; i <= 100; i++){
        insere (i,&vetor);
        exibe_vetor(&vetor, "");
    }
    int elemento_removido;
    if(remove_elemento (&vetor, &elemento_removido)){
        printf("%d foi removido", elemento_removido);
        exibe_vetor (&vetor, "");
    } else{
        printf("vetor vazio, nao ha o que remover\n");
    }
    //while (!esta_vazio(&vetor)){
        //remove_elemento (&vetor, &elemento_removido);
       // printf("%d foi removido", elemento_removido);
     //   exibe_vetor (&vetor, "");
    //} 
    limpa_vetor (&vetor);
    exibe_vetor (&vetor, "vetor depois do limpa_vetor");
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
    //if (p_vetor -> capacidade == p_vetor -> ocupacao)
      //  return 1;
    //else
      //  return 0;
      return p_vetor -> capacidade ==p_vetor -> ocupacao;
}
int esta_vazio (t_vetor *p_vetor){
    //if(p_vetor -> ocupacao == 0)
      //return 1;
       // return 0;
    return p_vetor -> ocupacao == 0;
}

//int insere (int, t_vetor *p_vetor){
    //if (esta_cheio(p_vetor)){
      //  return FRACASSO
    //} else{
        //p_vetor -> v[p_vetor-> ocupacao] = i;
      //  p_vetor -> ocupacao++;
    //    return SUCESSO
  //  }
//}
//void dobra(t_vetor *p_vetor){ //quando a funçao nn é publica, ela nn é declarda la em cima (no .h)
    //int *temp = (int *) malloc (sizeof(int) * p_vetor-> capacidade * 2);// para ser 1:1 (um para um)
    //for (int i=0; i < p_vetor-> ocupacao; i++)//laço para copiar os valores que ja estavam, para os novos espaços
      //  temp[i] = p_vetor -> v[i]; //temp recebe posicao 0 do v, posicao 1 do v... e assim vai
    //free (p_vetor -> v); //para liberar (apagar oq o v aponta)
    //p_vetor -> v = temp; //atualizando o endereço, ja que apagamos o v
  //  p_vetor -> capacidade = p_vetor-> capacidade * 2; //mudando a capacidade (se cabiam 4 agora cabe 8)
//}  
//void reduz_a_metade (t_vetor *p_vetor){
    //int *temp = (int *) malloc (sizeof(int) * p_vetor -> capacidade / 2); //para reduzir faça a divisao, ja que dobrar fazemos a multi
    //for(int i =0; i <p_vetor -> ocupacao ; i++)
      //  temp[i] = p_vetor -> v[i];
    //free (p_vetor -> v); //liberar o vetor apontado por v
    //p_vetor -> v = temp; //recebe a copia do endereco temporario qeu vai morrer
  //  p_vetor -> capacidade = p_vetor -> / 2; //atualiznado a capacidade 
//}

//JUNÇAO DO DOBRA E REDUZ_A_CAPACIDADE
void redimensiona (t_vetor *p_vetor , int novaCapacidade){
    int *temp = (int *) malloc (sizeof(int) *novaCapacidade);
    for(int i =0; i <p_vetor -> ocupacao ; i++){
        temp[i] = p_vetor -> v[i];
    free (p_vetor -> v);
    p_vetor -> v = temp;
    p_vetor -> capacidade = novaCapacidade;
    }
}

void insere(int i, t_vetor *p_vetor){
    if(esta_cheio(p_vetor)){
        redimensiona(p_vetor, p_vetor -> capacidade * 2);//agora vai ser redimensiona pq é o novo, a JUNCAO
        //dobra(p_vetor);// se estiver cheio vai dobrar, se nn ingonra e preenche se n estiver ocupado
    }
    p_vetor -> v[p_vetor-> ocupacao] = i;
    p_vetor -> ocupacao++; 
}

void exibe_vetor (t_vetor *p_vetor, char * msg){
    printf("\n%s\n", msg);
    printf("ocupacao = %d\n", p_vetor-> ocupacao);
    printf("capacidade = %d\n", p_vetor-> capacidade);
    printf("o vetor: ");
    for(int i=0; i < p_vetor->ocupacao; i++)
        printf("%d ",p_vetor->v[1]);
    //for(int i=p_vetor->ocupacao; i< p_vetor->capacidade; i++)
    //   printf("__ ");
    printf("\n");
}
int remove_elemento (t_vetor *p_vetor, int * p_quem_sai) {
    if(esta_vazio(p_vetor)) return FRACASSO;
    p_vetor ->ocupacao--; //BAIXAR a ocupacao
    //um operador de referencia * (conceito = ao contrario &)
    *p_quem_sai = p_vetor -> v[p_vetor -> ocupacao]; //voltou para a ocupacao, voltou uma casa 
    if (p_vetor -> capacidade >= CAPACIDADE_MINIMA* 2) //capacidade_minima * 2, pq tem que garanetir wue vai ate 20
    if (p_vetor -> ocupacao <= p_vetor -> capacidade / 4) //se a ocupaçcao for menor que 1/4
        redimensiona(p_vetor, p_vetor -> capacidade / 2); 
    return SUCESSO;
}
void limpa_vetor (t_vetor *p_vetor){
        p_vetor -> ocupacao = 0; //declarando ocupacao = 0, ele tecnicamente limpa o vetor
}
int busque_elemento (t_vetor *p_vetor, int elemento){
    for(int i = 0; i < p_vetor ->ocupacao; i++){
        if(elemento == p_vetor -> v[i]) //se no vetor tiver o elemento , SUCESSO 
            return 1;
    }
        return 0; 
}
