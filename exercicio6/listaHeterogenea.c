#include "listaHeterogenea.h"
#include "aluno.h"
#include "professor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROF 'P'
#define ALUN 'A'

typedef struct cel{
    struct cel * prox;
    void* item; //tProfessor ou tAluno
    char tipo;
}tCelula;

struct listaheterogenea{
    tCelula* Pri;
    tCelula* Ult;
};

ListaHet* InicializaLista(void){
    ListaHet* lista = (ListaHet*) malloc(sizeof(ListaHet));

    lista->Pri = NULL;
    lista->Ult = NULL;

    return lista;
}

void InsereAluno(ListaHet* lista, tAluno* aluno){
    tCelula* novoaluno = (tCelula*) malloc(sizeof(tCelula));
    novoaluno->tipo = ALUN;
    novoaluno->item = aluno;
    novoaluno->prox = lista->Pri;

    lista->Pri = novoaluno;
    
    if(lista->Ult == NULL){
        lista->Ult = novoaluno;
    }
}

void InsereProfessor(ListaHet* lista, tProfessor* professor){
    tCelula* novoprofessor = (tCelula*) malloc(sizeof(tCelula));
    novoprofessor->tipo = PROF;
    novoprofessor->item = professor;
    novoprofessor->prox = lista->Pri;

    lista->Pri = novoprofessor;
    
    if(lista->Ult == NULL){
        lista->Ult = novoprofessor;
    }
}

void ImprimeLista(ListaHet* lista){
    tCelula * paux;

    for(paux = lista->Pri; paux != NULL; paux = paux->prox){
        if(paux->tipo == ALUN){
            printf("\nAluno: ");
            imprimeAluno(paux->item);
        }
        else if(paux->tipo == PROF){
            printf("\nProfessor: ");
            imprimeProfessor(paux->item);
        }
        else{
            printf("Erro na Imprime Lista");
            exit(1);
        }
    }
}
float ValorChurrasco(ListaHet* lista){
    float precofinal = 0;
    tCelula* paux = lista->Pri;

    while(paux != NULL){
        if(paux->tipo == PROF){
            precofinal += 50;
        }
        else if(paux->tipo == ALUN){
            precofinal += 30;
        }

        paux = paux->prox;
    }

    return precofinal;
}
void DestroiLista(ListaHet* lista){
    tCelula* paux = lista->Pri;
    tCelula* taux;

    while(paux != NULL){
        taux = paux->prox;
        free(paux);
        paux = taux;
    }

    free(lista);
}