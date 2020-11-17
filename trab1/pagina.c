#include "pagina.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define MAX_TAM 20

struct listapagina{
    celulaPagina * pripagi;
    celulaPagina * ultpagi;
};

struct celpagina{
    Pagina * pagi; //pagina
    celulaPagina * proxPag; //ponteiro pra proxima pagina
};

struct pagina{
    char * nomePagina; //string nome
    FILE * arqpagina;
    listaContribuicao * listaContribuicao; //ponteiro pra primeira celulaContribuicao
    celLink * listaLinks; //ponteiro pra primeira celulaLinks
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

void insereCelulaListaPagina(listaPagina* lista, celulaPagina* novacelula){
    if(lista->pripagi == NULL){
        lista->pripagi = novacelula;
        lista->ultpagi = novacelula;
    }else{
        lista->ultpagi->proxPag = novacelula;
        lista->ultpagi = novacelula;
    }
}

void retiraCelulaPaginaLista(FILE* log, listaPagina* lista, char* nomepagina){
    celulaPagina * aux = lista->pripagi;
    celulaPagina * anterior = NULL;

    while(aux != NULL){
        if(nomepagina == retornaNomePagina(aux->pagi)){
            if(lista->pripagi == aux){
                lista->pripagi = aux->proxPag;
                return;
            }else{
                anterior->proxPag = aux->proxPag;
                return;
            }
        }

        anterior = aux;
        aux = aux->proxPag;
    }

    fprintf(log, "ERRO: não existe a pagina %s", nomepagina);
}

celulaPagina* inicializaCelulaPagina(char* nomepagina, char* arquivopagina){
    celulaPagina * novacelula = (celulaPagina*) malloc (sizeof(celulaPagina));
    novacelula->pagi = inicializaPagina(nomepagina, arquivopagina);
    novacelula->proxPag = NULL;

    return novacelula;
}

void liberaCelulaPagina(celulaPagina* celpagina){
    free(celpagina);
}

Pagina* inicializaPagina(char * nomepagina, char * nomearquivo){
    Pagina * novapagina = (Pagina*) malloc(sizeof(Pagina));

    novapagina->nomePagina = strdup(nomepagina);
    novapagina->arqpagina = fopen(nomepagina, "w");
    //novapagina->listaContribuicao =  inicializaListaContribuicao();
    //novapagina->listaLinks = inicializaListaLink();

    return novapagina;
}

void imprimePagina(Pagina* pagina){
    // fprintf(pagina->arqpagina, "%s");
}

void liberaPagina(Pagina* pagina){
    free(pagina->nomePagina);
    free(pagina->listaContribuicao);
    free(pagina->listaLinks);
    fclose(pagina->arqpagina);

    free(pagina);
}

char* retornaNomePagina(Pagina*);
char* retornaNomeArquivo(Pagina*);