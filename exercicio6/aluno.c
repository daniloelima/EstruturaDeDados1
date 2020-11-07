#include "aluno.h"
#include <stdio.h>


struct aluno{
    char* nome;
    int matricula;
    float CR;
};

tAluno * inicializaAluno(int matricula, char* nome, float CR){
    tAluno * novoaluno = (tAluno*) malloc(sizeof(tAluno));
    novoaluno->matricula = matricula;
    strcpy(novoaluno->nome, nome);
    novoaluno->CR = CR;

    return novoaluno;
}
void imprimeAluno(tAluno * aluno){
    
}
int RetornaMatricula(tAluno * aluno){
    return aluno->matricula;
}
char* RetornaNome(tAluno * aluno){
    return aluno->nome;
}
float RetornaCR(tAluno * aluno){
    return aluno->CR;
}

void destroiAluno(tAluno * aluno){

}