#include <stdio.h>
#include "listaMAT.h"

void geraMatriz(Matriz* mat, int nl, int nc);

int main(){
    Matriz* teste1 = inicializaMatriz(1,2);
    geraMatriz(teste1,1,2);
    Matriz* teste2 = inicializaMatriz(3,3);
    geraMatriz(teste2,3,3);
    Matriz* teste3 = inicializaMatriz(2,4);
    geraMatriz(teste3,2,4);
    Matriz* teste4 = inicializaMatriz(2,1);
    geraMatriz(teste4,2,1);
    
    Lista* lista = iniciaLista();
    insereLista(lista, teste1);
    insereLista(lista, teste2);
    insereLista(lista, teste3);
    insereLista(lista, teste4);

    printf("\nImprimindo Lista:\n");
    imprimeLista(lista);

    RetiraLista(lista, 1);
    printf("\nImprimindo Nova Lista:\n");
    imprimeLista(lista);
    
    insereLista(lista, teste3);
    printf("\nImprimindo Ultima Lista:\n");
    imprimeLista(lista);
    DestroiLista(lista);

    return 0;
}

void geraMatriz(Matriz* mat, int nl, int nc){
    for(int i=0; i < nl; i++){
        for(int j=0; j < nc; j++){
            modificaElemento(mat, i, j,i+j);
        }
    }
}