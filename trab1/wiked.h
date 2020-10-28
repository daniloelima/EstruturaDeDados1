#ifndef wiked_H_
#define wiked_H_

#include <stdio.h>

typedef struct wiked WikED;

WikED * inicializaWikED();
void leituraEntrada(FILE*, WikED*);
void leituraFuncao(FILE*, WikED*, char*);

#endif 