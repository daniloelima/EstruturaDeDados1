#include "contribuicao.h"
#include "editor.h"
#include <stdio.h>

struct listacontribuicao{
    CelContribuicao * pricontri;
    CelContribuicao * ultcontri;
};

struct celcontribuicao{
    //contribuicao
    Contribuicao * cont;
    //ponteiro para prox contribuicao
    struct celcontribuicao * proxcont;
};

struct contribuicao{
    //string nome (arquivo)
    char * nome;
    //FILE texto 
    FILE* texto;
    //ponteiro para o editor
    Editor * edit;
    //indicador de uso 
    char ativo;
};