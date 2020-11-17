#include <stdio.h>
#include "wiked.h"
#define MAX_TAM 20

int main(char * argv[], int argc){
    FILE * entrada = fopen(argv[1],"r");
    FILE * log = fopen("log.txt", "w");

    WikED * wiki = inicializaWikED();
    
    //leituraEntrada(entrada, wiki);
    char funcao[MAX_TAM];

    while(fscanf(entrada, "%s ", funcao) == 1 && strcmp(funcao, "FIM")){
        leituraFuncao(entrada, log, wiki, funcao);
    }

    liberaWiki(wiki);
    fclose(argv[1]);

    return 0;
}

/*
int main(char * argv[], int argc){
    listaEditor * listaeditor = inicializaListaEditor();

    return 0;
}
*/
