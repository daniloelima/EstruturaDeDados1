#ifndef editor_H_
#define editor_H_

#include <stdio.h>

typedef struct editor Editor;
typedef struct celeditor celulaEditor;
typedef struct listaeditor listaEditor;

listaEditor * inicializaListaEditor();
void imprimeListaEditor(listaEditor*);
void liberaListaEditor(listaEditor*);


void insereCelulaEditorLista(listaEditor*, celulaEditor*);

celulaEditor* inicializaCelulaEditor(char*);
void liberaCelulaEditor(celulaEditor*);

Editor * procuraEditorLista(listaEditor*, char*);
Editor* inicializaEditor(char *); 
char* retornaNomeEditor(Editor*);
void imprimeEditor(Editor*); 
void liberaEditor(Editor*);

#endif