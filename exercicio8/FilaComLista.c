#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>
#define TAM 10

typedef struct celula{
    char letra;
    struct celula * prox;
}Celula;

typedef struct lista{
    Celula * pri;
    Celula * ult;
}Lista;


struct fila{
    Lista* lista;
};


//funcoes lista

Lista* inicializaLista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->pri = NULL;
    l->ult = NULL;

    return l;
}

void insereListaUlt(Lista * l, char letra){
    Celula * nova = (Celula*) malloc(sizeof(Celula));
    nova->letra = letra;
    nova->prox = NULL;

    if(l->ult == NULL){
        l->pri = l->ult = nova;
        return;
    }
    l->ult->prox = nova;
    l->ult = nova;

}

void imprimeLista(Lista * l){
    Celula * paux = l->pri;

    while(paux != NULL){
        printf("%c ", paux->letra);
        paux = paux->prox;
    }
}

char retiraListaPosicao(Lista* l, int pos){
    Celula * paux = l->pri;
    Celula * t;
    if(pos == 0){
        l->pri = paux->prox;
        // free(paux);
        return paux->letra;
    }else{
        for(int i = 0; i < pos; i++){
            t = paux;
            paux = paux->prox;
        }
        t->prox = paux->prox;
        // free(paux);
        return paux->letra;
    }
}

void destroiLista(Lista* l){
    Celula * paux = l->pri;
    Celula * t;

    while(paux != NULL){
        t = paux->prox;
        free(paux);
        paux = t;
    }

    free(l);
}

Fila* inicializaFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->lista = inicializaLista();

    return f;
}
void insereFila(Fila* f, char letra){
    insereListaUlt(f->lista, letra);
}
char retiraFila(Fila* f){
    return retiraListaPosicao(f->lista, 0);
}
void imprimeFila(Fila* f){
    imprimeLista(f->lista);
}
void destroiFila(Fila* f){
    destroiLista(f->lista);
    free(f);
}
