#include <stdio.h>
    void f1(){
        f1();
        int a = 2, b = 3, c = a+b;
    }
    int main(){
    f1();
    printf("foi!");
    return 0;
}