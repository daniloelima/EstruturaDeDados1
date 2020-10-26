#include "editor.h"
#include "contribuicao.h"

struct celeditor{
    //editor
    Editor edi;
    //prox editor
    struct celeditor * proxedi;
};

struct editor{
    //nome
    char * nome;
    //ponteiro pra primeira celcontribuicao
    CelContribuicao * con;
};
