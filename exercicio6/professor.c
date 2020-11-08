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
    novoprofessor->nome =  strdup(nome);
    novoprofessor->salario = salario;

    return novoprofessor;
}

void imprimeProfessor(tProfessor * professor){
    printf("nome: %s, siape: %d, salario: %.2f\n", professor->nome, professor->siape, professor->salario);
}

int retornaSiape(tProfessor * professor){
    return professor->siape;
}
char* retornaNome(tProfessor * professor){
    return professor->nome;
}
float retornaSalario(tProfessor * professor){
    return professor->salario;
}
void destroiProfessor(tProfessor * professor){
    free(professor->nome);
    free(professor);
}