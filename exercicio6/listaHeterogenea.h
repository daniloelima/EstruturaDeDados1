#ifndef listaHeterogenea_h
#define listaHeterogenea_h

#include <stdio.h>
#include "aluno.h"
#include "professor.h"

typedef struct listaheterogenea ListaHet;

ListaHet* InicializaLista(void);
void InsereAluno(ListaHet* lista, tAluno* aluno);
void InsereProfessor(ListaHet* lista, tProfessor* professor);
void ImprimeLista(ListaHet* lista);
float ValorChurrasco(ListaHet* lista);
void DestroiLista(ListaHet* lista);

#endif