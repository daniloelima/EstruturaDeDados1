#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char* nome;
    int matricula;
    float CR;
};

tAluno * inicializaAluno(int matricula, char* nome, float CR){
    tAluno * novoaluno = (tAluno*) malloc(sizeof(tAluno));
    novoaluno->matricula = matricula;
    novoaluno->nome = strdup(nome);
    novoaluno->CR = CR;

    return novoaluno;
}
void imprimeAluno(tAluno * aluno){
    printf("nome: %s, matricula: %d, CR: %.2f\n", aluno->nome, aluno->matricula, aluno->CR);
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
    free(aluno->nome);
    free(aluno);
}