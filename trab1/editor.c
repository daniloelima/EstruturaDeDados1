#include "editor.h"

struct listaeditor{
    celulaEditor * priedit;
    celulaEditor * ultedit;
};

struct celeditor{
    Editor * edit; //editor
    celulaEditor * proxedit; //prox editor
}; 

struct editor{
    char * nome;
};

//funcoes de lista
listaEditor * inicializaListaEditor(){
    listaEditor * lista = (listaEditor*) malloc(sizeof(listaEditor));

    lista->priedit = NULL;
    lista->ultedit = NULL;

    return lista;
}

void insereEditorLista(listaEditor * listaeditor, celulaEditor * novoedit){
    if(listaeditor->priedit==NULL){
        listaeditor->priedit = novoedit;
        listaeditor->ultedit = novoedit;
    }else{
        listaeditor->ultedit->proxedit = novoedit;
        listaeditor->ultedit = novoedit;
    }
}

void imprimeListaEditor(listaEditor * listaedit){
    celulaEditor * paux;
    for(paux = listaedit->priedit; paux != NULL; paux = paux->proxedit){
        imprimeEditor(paux);
    }
}

void liberaListaEditor(listaEditor * listaedit){
    celulaEditor * paux;
    for(paux = listaedit->priedit->proxedit; paux != NULL; listaedit->priedit = paux){
        liberaCelulaEditor(listaedit->priedit);
    }

    free(listaedit->priedit);
    free(listaedit->ultedit);
    free(listaedit);
}

//funcoes de celula
celulaEditor * inicializaCelulaEditor(char * nome){
    celulaEditor * novacelula = (celulaEditor*) malloc(sizeof(celulaEditor));
    
    novacelula->edit = inicializaEditor(nome);
    novacelula->proxedit = NULL;

    return novacelula;
}

void liberaCelulaEditor(celulaEditor * celedit){
    liberaEditor(celedit->edit);
}

//funcoes de editor
Editor * inicializaEditor(char * nome){
    Editor * novoeditor = (Editor*) malloc(sizeof(Editor));
    novoeditor->nome = strdup(nome);

    return novoeditor;
}

char * retornaNomeEditor(Editor * edit){
    return edit->nome;
}

void imprimeEditor(Editor * edit){
    printf("Nome: %s", edit->nome);
}

void liberaEditor(Editor * edit){
    free(edit->nome);
    free(edit);
}

Editor * inicializaEditor(char * nome){
    Editor * novoedit = (Editor*) malloc(sizeof(Editor));
    novoedit->nome = nome;

    return novoedit;
}