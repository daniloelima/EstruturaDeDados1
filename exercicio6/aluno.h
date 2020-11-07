#ifndef aluno_h
#define aluno_h

typedef struct aluno tAluno;

tAluno * inicializaAluno(int matricula, char* nome, float CR);
void imprimeAluno(tAluno * aluno);
int RetornaMatricula(tAluno * aluno);
char* RetornaNome(tAluno * aluno);
float RetornaCR(tAluno * aluno);
void destroiAluno(tAluno * aluno);

#endif