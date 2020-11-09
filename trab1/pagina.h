#ifndef pagina_H_
#define pagina_H_

#include <stdio.h>
#include "contribuicao.h"
#include "link.h"

typedef struct pagina Pagina;
typedef struct celpagina celulaPagina;
typedef struct listapagina listaPagina;

listaPagina * inicializaListaPagina();
void imprimeListaPagina(listaPagina*);
void liberaListaPagina(listaPagina*);

celulaPagina* inicializaCelulaPagina(char*);
void liberaCelulaPagina(celulaPagina*);

Pagina* inicializaPagina(char *, char*); 
void imprimePagina(Pagina*); 
void liberaPagina(Pagina*);

char* retornaNomePagina(Pagina*);
char* retornaNomeArquivo(Pagina*);


#endif