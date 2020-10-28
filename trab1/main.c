#include <stdio.h>
#include "wiked.h"

int main(char * argv[], int argc){
    FILE * entrada = fopen(argv[1],"r");
    WikED * wiki = inicializaWikED();
    
    leituraEntrada(entrada, wiki);

    fclose(argv[1]);

    return 0;
}