#ifndef contribuicao_H_
#define contribuicao_H_

typedef struct contribuicao Contribuicao;
typedef struct celcontribuicao celulaContribuicao;
typedef struct listacontribuicao listaContribuicao;

listaContribuicao * inicializaListaContribuicao();
celulaContribuicao * inicializaCelulaContribuicao(char* nome, char* nomearq, char* nomeeditor);
Contribuicao* inicializaContribuicao(char* nome, char* nomearq, char* editor);

void insereCelulaListaContribuicao(listaContribuicao*, celulaContribuicao*);

void liberaListaContribuicao(listaContribuicao *);
void liberaCelulaContribuicao(celulaContribuicao *);
void liberaContribuicao(Contribuicao *);

#endif