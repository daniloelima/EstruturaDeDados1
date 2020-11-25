#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>
#define TAM 10

struct fila{
    int inicio;
    int qtd;
    char letras[TAM];
};

Fila* inicializaFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = 0;
    f->qtd = 0;

    return f;
}

void insereFila(Fila* f, char letra){
    if(!f || f->qtd >= TAM){
        printf("\nPilha Invalida ou Cheia!\n");
    }

    int pos = (f->inicio + f->qtd) % TAM;

    f->letras[pos] = letra;

    f->qtd++;
}

char retiraFila(Fila* f){
    if(!f || f->qtd == 0){
        printf("\nPilha invalida ou vazia!\n");
        exit(1);
    }

    char letra = f->letras[f->inicio];

    f->inicio = (f->inicio + 1) % TAM;

    f->qtd--;

    return letra;
}

void imprimeFila(Fila* f){
    int i;
    int pos = 0;

    if(!f){
        return;
    }

    for(int i=0; i<f->qtd; i++){
        pos = (f->inicio + i) % TAM;
        printf("%c ", f->letras[pos]);
    }
    printf("\n");
}

void destroiFila(Fila* f){
    if(!f){
        return;
    }
    free(f);
}
