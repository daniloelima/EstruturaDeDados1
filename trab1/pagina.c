#include "pagina.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct listapagina{
    celulaPagina * pripagi;
    celulaPagina * ultpagi;
};

struct celpagina{
    Pagina pagi; //pagina
    celulaPagina * proxPag; //ponteiro pra proxima pagina
};

struct pagina{
    char * nomePagina; //string nome
    FILE * pagina;
    listaContribuicao * listaContribuicao; //ponteiro pra primeira celulaContribuicao
    CelLink * listaLinks; //ponteiro pra primeira celulaLinks
};

listaPagina * inicializaListaPagina(){
    listaPagina * lista = (listaPagina*) malloc(sizeof(listaPagina));

    lista->pripagi = NULL;
    lista->ultpagi = NULL;

    return lista;
}

void imprimeListaPagina(listaPagina* lista){

}

void liberaListaPagina(listaPagina* lista){

}

celulaPagina* inicializaCelulaPagina(char*);
void liberaCelulaPagina(celulaPagina*);

Pagina* inicializaPagina(char * nomepagina, char * nomearquivo){
    Pagina * novapagina = (Pagina*) malloc(sizeof(Pagina));

    novapagina->nomePagina = strdup(nomepagina);
    novapagina->pagina = fopen(nomepagina, "w");
    //novapagina->listaContribuicao =  inicializaListaContribuicao();
    //novapagina->listaLinks = inicializaListaLink();

    return novapagina;
}

void imprimePagina(Pagina*);
void liberaPagina(Pagina*);

char* retornaNomePagina(Pagina*);
char* retornaNomeArquivo(Pagina*);