#include "contribuicao.h"
#include "editor.h"

struct celcontribuicao{
    //contribuicao
    Contribuicao cont;
    //ponteiro para prox contribuicao
    struct celcontribuicao * proxcont;
};

struct contribuicao{
    //string nome (arquivo)
    char * nome;
    //string texto 
    char * texto;
    //ponteiro para o editor
    Editor * edit;
    //indicador de uso 
    char ativo;
};