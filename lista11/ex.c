#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 5

typedef struct fila{
    int elementos[TAM_MAX];
    int cabecalho, fim;
}FILA;

void iniciar_fila(FILA *f){
    f -> cabecalho = fila -> fim = 0;
    f -> fim = 0;
}
