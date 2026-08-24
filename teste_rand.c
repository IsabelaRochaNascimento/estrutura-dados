#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); //parametro fixo
    int a = rand() % 10; //ate 9
    int b = rand() % 100; //ate 99
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    //printf("RAND_MAX = %d\n", RAND_MAX);
    return 0;
}
