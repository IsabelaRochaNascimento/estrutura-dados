#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p;
    while(1){ //1 é verdadeiro 
        p = (int *) malloc (2000000);
        printf("%p\n", p);
        free(p); //faz nn estourar 
    }
}
