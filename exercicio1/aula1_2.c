//Codigo feito por Danilo Erler Lima
//ultima atualização: 15/09/2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159

void calc_esfera(float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2); 
int pares (int n, int* vet); 
void inverte (int n, int* vet);
double avalia (double* poli, int  grau, double x); 

/* //main calc esfera
int main(){
    float raio, area, volume;
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);

    printf("Uma esfera de raio %.2f tem area: %.2f e volume: %.2f", raio, area, volume);

    return 0;
}
*/


/* //main raizes
int main(){
    int numraizes;
    float a, b, c, x1, x2;

    scanf("%f%f%f", &a, &b, &c);

    numraizes=raizes(a, b, c, &x1, &x2);

    if(numraizes == 0){
        printf("Nao ha raizes!\n");
    }
    else if(numraizes == 1){
        printf("Há uma unica raiz: %.2f!\n", x1);
    }
    else{
        printf("As raizes são: %.2f e %.2f!\n", x1, x2);
    }

    return 0;
}
*/

/* main pares

int main(){
    int tam, numpares, * vetor;

    printf("digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int*) malloc(tam*sizeof(int));

    printf("digite os numeros do vetor: ");
    for(int i=0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    numpares = pares(tam, vetor);

    printf("há %d numeros pares no vetor\n", numpares);

    free(vetor);
    return 0;
}

*/

/* main inverte

int main(){
    int tam, numpares, * vetor;

    printf("digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int*) malloc(tam*sizeof(int));

    printf("digite os numeros do vetor: ");
    for(int i=0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    inverte(tam, vetor);

    printf("O vetor invertido é: ");
    for(int i=0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}

*/
/*main avalia polinomio
int main(){
    double x, resultado, * poli;
    int grau;

    printf("digite o grau do polinomio: ");
    scanf("%d", &grau);
    poli = (double*) malloc((grau+1)*sizeof(double));

    printf("digite os coeficientes: ");
    for(int i=0; i<=grau; i++){
        scanf("%lf", &poli[i]);
    }
    printf("digite o valor de ""x"" a ser analisado");
    scanf("%lf", &x);

    resultado = avalia(poli, grau, x);

    printf("O resultado do polinomio é: %.2lf", resultado);

    free(poli);
    return 0;
}
*/

double avalia (double* poli, int  grau, double x){
    double resultado = 0;
    for(int i=0; i<=grau; i++){
        resultado += poli[i] * pow(x, i);
    }

    return resultado;
}


void inverte (int n, int* vet){
    int aux;
    for(int i=0; i<n/2; i++){
        aux = vet[i];
        vet[i]=vet[n-i-1];
        vet[n-i-1]=aux;
    }
}

int pares (int n, int* vet){
    int numpares = 0;
    for(int i=0; i < n; i++){
        if(vet[i]%2 == 0){
            numpares++;
        }
    }

    return numpares;
}

void calc_esfera(float r, float* area, float* volume){
    *area = 4.0*PI*r*r;
    *volume = (4.0*PI*r*r*r)/3.0;
}

int raizes (float a, float b, float c, float* x1, float* x2){
    float delta;

    delta = (b*b) - 4*a*c;
    if(delta<0){
        return 0;
    }
    else if(delta==0){
        *x1 = (-b)/ 2*a;
        return 1;
    }
    else{
        *x1 = (sqrt(delta) - b)/ 2*a;
        *x2 = (-sqrt(delta) - b)/ 2*a;
        return 2;
    }
}