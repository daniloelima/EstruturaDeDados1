#include <stdio.h>
#include "listaHeterogenea.h"

int main(){
    ListaHet * lista =  InicializaLista();

    tAluno * joao = inicializaAluno(1001, "joao", 7.2);
    tAluno * vina = inicializaAluno(1020, "vina", 5);
    tAluno * luma = inicializaAluno(1300, "luma", 0.8);

    tProfessor * pc = inicializaProfessor(1372, "pc", 1800.32);
    tProfessor * cd = inicializaProfessor(1373, "cd", 950.05);

    InsereAluno(lista, joao);
    InsereProfessor(lista, pc);
    InsereAluno(lista, vina);
    InsereAluno(lista, luma);
    InsereProfessor(lista, cd);

    ImprimeLista(lista);

    printf("\nValor do churras: %.2f\n", ValorChurrasco(lista));
    
    DestroiLista(lista);

    destroiAluno(joao);
    destroiAluno(vina);
    destroiAluno(luma);

    destroiProfessor(pc);
    destroiProfessor(cd);

    return 0;
}