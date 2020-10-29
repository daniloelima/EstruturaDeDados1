#ifndef editor_H_
#define editor_H_

#include <stdio.h>

typedef struct editor Editor;
typedef struct celeditor celulaEditor;
typedef struct listaeditor listaEditor;

listaEditor * inicializaListaEditor();
void imprimeListaEditor(listaEditor*);
void liberaListaEditor(listaEditor*);

void liberaCelulaEditor(celulaEditor*);
celulaEditor* inicializaCelulaEditor(char*);

char* retornaNomeEditor(Editor*);
void imprimeEditor(Editor*); //a fazer
void liberaEditor(Editor*);
Editor* inicializaEditor(char *);

#endif