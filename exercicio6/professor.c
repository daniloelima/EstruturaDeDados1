#include "professor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor{
    int siape;
    char* nome;
    float salario;
};

tProfessor* inicializaProfessor(int siape, char* nome, float salario){
    tProfessor * novoprofessor =  (tProfessor*) malloc(sizeof(tProfessor));

    novoprofessor->siape = siape;

    strcpy(novoprofessor->nome, nome);
    novoprofessor->salario = salario;

    return novoprofessor;
}

