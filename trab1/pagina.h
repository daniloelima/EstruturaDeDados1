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

void insereCelulaPaginaLista(listaPagina*, celulaPagina*);
void retiraCelulaPaginaLista(FILE*, listaPagina*, char*);


Pagina * procuraPaginaLista(listaPagina * lista, char* nomepagina);


celulaPagina* inicializaCelulaPagina(char*, char*);
void liberaCelulaPagina(celulaPagina*);

Pagina* inicializaPagina(char *, char*); 
void imprimePagina(Pagina* pagina); 
void liberaPagina(Pagina* pagina);

listaContribuicao* retornaListaContribuicaoPagina(Pagina* pagina);
char* retornaNomePagina(Pagina* pagina);
FILE* retornaArquivoPagina(Pagina* pagina);


#endif