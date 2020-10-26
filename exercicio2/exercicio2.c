//Codigo feito por Danilo Erler Lima
//ultima atualização: 23/09/2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char* nome; 
    int matricula; 
    float p1, p2, p3; 
}Aluno;


Aluno** inicializaTurma(int);
Aluno* inicializaAluno();
void leAlunos(int, Aluno**);
float media_turma (int, Aluno**);
void imprime_aprovados (int, Aluno**);
void imprime_aluno(Aluno**, int);
void libera(int, Aluno**);

int main(){
    int nalunos;

    printf("Digite o numero de alunos da turma:");
    scanf("%d", &nalunos);

    Aluno ** turma =  inicializaTurma(nalunos);
    leAlunos(nalunos, turma);

    printf("\nA média da turma foi: %.2f\n", media_turma(nalunos, turma));

    printf("A lista de aprovados foi: \n");
    imprime_aprovados(nalunos, turma);

    libera(nalunos, turma);
    return 0;
}

Aluno** inicializaTurma(int n){
    Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));

    for(int i=0; i<n; i++){
        turma[i] = inicializaAluno();
    }

    return turma;
}

Aluno* inicializaAluno(){
    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

    return aluno;
}

void leAlunos(int n, Aluno** turma){
    char aux[40];
    
    for(int i=0; i<n; i++){
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]", aux);
        
        turma[i]->nome = strdup(aux);

        printf("Digite a matricula do aluno: ");
        scanf("%d", &turma[i]->matricula);
        printf("Digite as 3 notas do aluno: ");
        scanf("%f%f%f", &turma[i]->p1, &turma[i]->p2, &turma[i]->p3);
    }
}

float media_turma (int n , Aluno** turma){
    float media = 0;

    for(int i=0; i<n; i++){
        media += turma[i]->p1 + turma[i]->p2 + turma[i]->p3;
    }

    return media/(3*n);
}

void imprime_aprovados(int n, Aluno** turma){
    for(int i=0; i<n; i++){
        float mediaaluno = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3.0;
        
        if(mediaaluno>5){
            imprime_aluno(turma, i);
        }
    }
}

void imprime_aluno(Aluno** turma, int pos){
    printf("Nome: %s\n", turma[pos]->nome);
    printf("Matricula: %d\n", turma[pos]->matricula);
    printf("Notas: %.2f, %.2f, %.2f\n\n", turma[pos]->p1, turma[pos]->p2, turma[pos]->p3);
}

void libera(int n, Aluno** turma){
    for(int i=0; i<n; i++){
        free(turma[i]->nome);
        free(turma[i]);
    }

    free(turma);
}