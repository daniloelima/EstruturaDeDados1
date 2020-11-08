#ifndef professor_h
#define professor_h

typedef struct professor tProfessor;

tProfessor* inicializaProfessor(int siape, char* nome, float salario);
void imprimeProfessor(tProfessor * professor);
int retornaSiape(tProfessor * professor);
char* retornaNome(tProfessor * professor);
float retornaSalario(tProfessor * professor);
void destroiProfessor(tProfessor * professor);

#endif