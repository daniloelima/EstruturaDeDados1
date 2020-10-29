#include "pagina.h"

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
    char * nomeArquivoPagina;
    listaContribuicao * listaContribuicao; //ponteiro pra primeira celulaContribuicao
    CelLink * listaLinks; //ponteiro pra primeira celulaLinks
};

listaPagina * inicializaListaPagina(){
    listaPagina * lista = (listaPagina*) malloc(sizeof(listaPagina));

    lista->pripagi = NULL;
    lista->ultpagi = NULL;

    return lista;
}