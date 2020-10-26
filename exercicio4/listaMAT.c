#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaMAT.h"

struct matriz{
    int** matr;
    int nlin, ncol;
};

struct cel{
    Matriz* mat;
    Celula* prox;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

//Funções referentes a struct lista

Lista* iniciaLista(){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
}

void insereLista(Lista* lista, Matriz* mat){
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->mat = mat;

    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){
        lista->ult = nova;
    }
}

void imprimeLista(Lista* lista){
    Celula* paux;

    for(paux = lista->prim; paux != NULL; paux = paux->prox){
        imprimeMatriz(paux->mat);
        printf("\n");
    }
}

Matriz* RetiraLista(Lista* lista, int indice){
    Celula* paux = lista->prim;
    Celula* ant = NULL;
    Matriz* mataux;

    for(int i=0; i < indice; i++){
        ant = paux;
        paux = paux->prox;
        if(paux == NULL){
            printf("Indice invalido.");
            exit(1);
        }
    }

    mataux = paux->mat;

    if(paux == lista->prim && paux == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
    }else if(paux == lista->prim){
        lista->prim = NULL;
    }else if(paux == lista->ult){
        lista->ult = ant;
        lista->ult->prox = NULL;
    }else{
        ant->prox = paux->prox;
    }

    free(paux);

    return mataux;
}

void DestroiLista(Lista* lista){
    Celula* paux = lista->prim;
    Celula* pprox;

    while(paux!=NULL){
        pprox = paux->prox;
        destroiMatriz(paux->mat);
        free(paux);
        paux = pprox;
    }

    free(lista);
}

//Funções referentes a struct matriz
Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* mat = (Matriz*) malloc(sizeof(struct matriz));
    
    mat->nlin = nlinhas;
    mat->ncol = ncolunas;

    mat->matr = (int**) malloc(mat->nlin * sizeof(int*));

    for(int i=0; i < mat->nlin; i++){
        mat->matr[i] = (int*) malloc(mat->ncol * sizeof(int));
    }

    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->matr[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->matr[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->ncol;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nlin;
}

Matriz* transposta (Matriz* mat){
    Matriz* trp = inicializaMatriz(mat->ncol, mat->nlin);

    for(int i=0; i < mat->nlin; i++){
        for(int j=0; j < mat->ncol; j++){
            trp->matr[j][i] = mat->matr[i][j];
        }
    }

    return trp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1->ncol == mat2->nlin){
        Matriz* mlt = inicializaMatriz(mat1->nlin, mat2->ncol);

        for(int i = 0; i < mat1->nlin; i++){
            for(int j = 0; j < mat2->ncol; j++){
                mlt->matr[i][j] = 0;

                for(int k = 0; k < mat1->ncol; k++){
                    mlt->matr[i][j] += mat1->matr[i][k] * mat2->matr[k][j];
                }
            }
        }
        
        return mlt;
    }
    else{
        printf("Nao é possivel calcular a Matriz Multiplicacao.\n");
        exit(1);
    }
}

void imprimeMatriz(Matriz* mat){
    for(int i=0; i<mat->nlin; i++){
        for(int j=0; j<mat->ncol; j++){
            printf("%02d ", mat->matr[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    for(int i=0; i<mat->nlin; i++){
        free(mat->matr[i]);
    }
    free(mat->matr);
    free(mat);
}