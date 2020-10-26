#ifndef listaMAT_H_
#define listaMAT_H_

typedef struct matriz Matriz;
typedef struct cel Celula;
typedef struct lista Lista;


Matriz* inicializaMatriz (int nlinhas, int ncolunas);
void modificaElemento (Matriz* mat, int linha, int coluna, int elem);
int recuperaElemento(Matriz* mat, int linha, int coluna);
int recuperaNColunas (Matriz* mat);
int recuperaNLinhas (Matriz* mat);
Matriz* transposta (Matriz* mat);
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2);
void imprimeMatriz(Matriz* mat);
void destroiMatriz(Matriz* mat);


Lista* iniciaLista();
void insereLista(Lista* lista, Matriz* mat);
void imprimeLista(Lista* lista);
Matriz* RetiraLista(Lista* lista, int indice);
void DestroiLista(Lista* lista);
#endif 
