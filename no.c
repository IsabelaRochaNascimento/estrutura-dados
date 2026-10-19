#include "no.h"

struct no * constroi_no (int info) {
    struct no *novo = (struct no *) malloc (sizeof(struct no));
    if (novo != NULL) {
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}