#include "no.h"

int main () {
    struct no no1, no2;
    no1.info = 4;
    no2.info = 10;
    no1.prox = &no2;
    printf ("endereco de no2: %p\n", &no2);
    printf ("atributo info de no1: %d\n", no1.info);
    printf ("atributo prox de no1: %p\n", no1.prox);

    struct no * ponteiro_struct_no;
    ponteiro_struct_no = constroi_no(20);
    printf ("valor de ponteiro_struct_no: %p\n", ponteiro_struct_no);
    printf ("campo info da estrutura apontada por ponteiro_struct_no: %d\n", ponteiro_struct_no->info);
    printf ("campo prox da estrutura apontada por ponteiro_struct_no: %p\n", ponteiro_struct_no->prox);
    return 0;
}