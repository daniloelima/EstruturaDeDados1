#include "contribuicao.h"
#include "editor.h"
#include <stdio.h>

struct listacontribuicao{
    celulaContribuicao * pricontri;
    celulaContribuicao * ultcontri;
};

struct celcontribuicao{
    Contribuicao * cont;
    struct celcontribuicao * proxcont;
};

struct contribuicao{
    char * nome;
    FILE* texto;
    char * nomeedit;
    char ativo;
};

listaContribuicao * inicializaListaContribuicao(){
    listaContribuicao * lista = (listaContribuicao*) malloc(sizeof(listaContribuicao));

    lista->pricontri = NULL;
    lista->ultcontri = NULL;

    return lista;
}
celulaContribuicao * inicializaCelulaContribuicao(char* nome, char* nomearq, char * nomeeditor){
    celulaContribuicao * novacelula = (celulaContribuicao*) malloc(sizeof(celulaContribuicao));
    novacelula->cont = inicializaContribuicao(nome, nomearq, nomeeditor);
    novacelula->proxcont = NULL;

    return novacelula;
}
Contribuicao* inicializaContribuicao(char* nome, char* nomearqtexto, char* editor){
    Contribuicao * novacontribuicao = (Contribuicao*) malloc(sizeof(Contribuicao));

    novacontribuicao->nome = strdup(nome);
    novacontribuicao->texto = fopen(nomearqtexto, 'w');
    novacontribuicao->nomeedit = strdup(editor);
    novacontribuicao->ativo = 'S';

    return novacontribuicao;
}

void insereCelulaListaContribuicao(listaContribuicao * lista, celulaContribuicao * novacelula){
    lista->ultcontri->proxcont = novacelula;
    lista->ultcontri = novacelula;
}

void liberaListaContribuicao(listaContribuicao * lista){
    celulaContribuicao * aux = lista->pricontri;
    celulaContribuicao * prox = lista->pricontri;
    while(aux != NULL){
        prox = aux->proxcont;
        liberaCelulaContribuicao(aux);
        aux = prox;
    }
    free(lista);
}
void liberaCelulaContribuicao(celulaContribuicao * celula){
    liberaContribuicao(celula->cont);
    free(celula);
}
void liberaContribuicao(Contribuicao * contribuicao){
    free(contribuicao->nome);
    free(contribuicao->nomeedit);
    fclose(contribuicao->texto);

    free(contribuicao);
}