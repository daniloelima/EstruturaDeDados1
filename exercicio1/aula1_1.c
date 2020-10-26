//Codigo feito por Danilo Erler Lima
//ultima atualização: 15/09/2020

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a=5, b=10, c=15, d=20;
    int *w, *x, *y, *z;

    w = &a;
    x = &b;
    y = &c;
    z = &d;

    printf("Valores iniciais: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    printf("digite quatro valores: ");
    scanf("%d%d%d%d", w, x, y, z);

    printf("Valores finais: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);
    
    return 0;
}
