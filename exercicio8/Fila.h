#ifndef Fila_h
#define Fila_h

#include <stdio.h>

typedef struct fila Fila;

Fila* inicializaFila();
void insereFila(Fila* f, char letra);
char retiraFila(Fila* f);
void imprimeFila(Fila* f);
void destroiFila(Fila* f);

#endif