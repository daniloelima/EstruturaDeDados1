#include "Fila.h"

int main(){
    Fila* f1 = inicializaFila();
    Fila* f2 = inicializaFila();

    insereFila(f1, 'c');
    insereFila(f1, 'w');
    insereFila(f1, 'k');
    insereFila(f1, 'm');

    printf("\nImprimindo Fila f1:\n");
    imprimeFila(f1);

    insereFila(f2, retiraFila(f1));

    printf("\nImprimindo Fila f1:\n");
    imprimeFila(f1);

    printf("\nImprimindo Fila f2:\n");
    imprimeFila(f2);

    insereFila(f2, retiraFila(f1));

    printf("\nImprimindo Fila f2:\n");
    imprimeFila(f2);

    destroiFila(f1);
    destroiFila(f2);

    return 0;
}