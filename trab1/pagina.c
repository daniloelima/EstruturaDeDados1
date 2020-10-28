#include "pagina.h"
#include "contribuicao.h"
#include "link.h"

struct listapagina{
    Pagina pagi; //pagina
    struct celPagina * proxPag; //ponteiro pra proxima pagina
};

struct pagina{
    char * nomePagina; //string nome
    char * nomeArquivoPagina;
    CelContribuicao * listaContribuicao; //ponteiro pra primeira celulaContribuicao
    CelLink * listaLinks; //ponteiro pra primeira celulaLinks
};