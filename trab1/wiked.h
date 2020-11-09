#ifndef wiked_H_
#define wiked_H_

#include <stdio.h>
#include "editor.h"
#include "pagina.h"

typedef struct wiked WikED;

WikED * inicializaWikED();
void liberaWiki(WikED *);
void leituraEntrada(FILE*, WikED*);
void leituraFuncao(FILE*, WikED*, char*);

#endif 