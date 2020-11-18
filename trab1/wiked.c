#include "wiked.h"
#include "pagina.h"
#include "editor.h"
#define MAX_TAM 20

//sentinela que indica as 2 listas (pagina e editores)
struct wiked{
    listaPagina * listapagi;
    listaEditor * listaedit;
};

WikED * inicializaWikED(){
    WikED * wiki = (WikED*) malloc (sizeof(struct wiked));
    
    wiki->listapagi = inicializaListaPagina();
    wiki->listaedit = inicializaListaEditor();

    return wiki;
}

void liberaWiki(WikED * wiki){
    liberaListaPagina(wiki->listapagi);
    liberaListaEditor(wiki->listaedit);
}


// void leituraEntrada(FILE * entrada, WikED * wiki){
//     char funcao[MAX_TAM];
//     while(fscanf(entrada, "%s ", funcao) == 1 && strcmp(funcao, "FIM")){
//         //chama a funcao "leituraFuncao" que identifica qual a funcao
//         leituraFuncao(entrada, wiki, funcao);
//     }
// }

void leituraFuncao(FILE * entrada, FILE* log, WikED * wiki, char * funcao){
    if(!strcmp(funcao, "INSEREPAGINA")){
        char nomepagina[MAX_TAM], arquivopagina[MAX_TAM];
        fscanf(entrada, " %s %s ", nomepagina, arquivopagina);

        if(procuraPaginaLista(wiki->listapagi, nomepagina)){
            fprintf(log, "Pagina %s ja adicionada.\n", nomepagina);
        }else{
            insereCelulaPaginaLista(wiki->listapagi, inicializaCelulaPagina(nomepagina, arquivopagina));
        }

    }

    else if(!strcmp(funcao, "RETIRAPAGINA")){
        char nomepagina[MAX_TAM];
        fscanf(entrada, " %s ", nomepagina);

        retiraCelulaPaginaLista(log, wiki->listapagi, nomepagina);
    }

    else if(!strcmp(funcao, "INSEREEDITOR")){
        char nomeeditor[MAX_TAM];
        fscanf(entrada, " %s ", nomeeditor);

        // celulaEditor * novacelula;
        // novacelula = inicializaCelulaEditor(nomeeditor);
        // insereEditorLista(wiki->listaedit, novacelula);
        if(procuraEditorLista(wiki->listaedit, nomeeditor)){
            fprintf(log, "Editor %s ja adicionado.\n", nomeeditor);
        }else{
            insereCelulaEditorLista(wiki->listaedit, inicializaCelulaEditor(nomeeditor));
        }
    }
    // else if(!strcmp(funcao, "RETIRAEDITOR")){
    //     char nomeeditor[MAX_TAM];
    //     fscanf(entrada, " %s ", nomeeditor);
    // }
    else if(!strcmp(funcao, "INSERECONTRIBUICAO")){
        char  nomepagina[MAX_TAM], nomeeditor[MAX_TAM], arquivocontribuicao[MAX_TAM];
        fscanf(entrada, " %s ", nomeeditor);
        
        Pagina * auxpagi = procuraPagina(wiki->listapagi ,nomepagina);
        if(auxpagi != NULL){
            insereCelulaListaContribuicao(retornaListaContribuicaoPagina(auxpagi),inicializaCelulaContribuicao(nomepagina, arquivocontribuicao, nomeeditor));
        }
    }
    else if(!strcmp(funcao, "RETIRACONTRIBUICAO")){
        char  nomepagina[MAX_TAM], nomeeditor[MAX_TAM], arquivocontribuicao[MAX_TAM];
        fscanf(entrada, " %s ", nomeeditor);

        fprintf(log, "Funcao --- nao suportada na versão da wiked");
    }
    else if(!strcmp(funcao, "INSERELINK")){
        char nomepaginaOrigem[MAX_TAM], nomepaginaDestino[MAX_TAM];
        fscanf(entrada, " %s %s ", nomepaginaOrigem, nomepaginaDestino);

        fprintf(log, "Funcao --- nao suportada na versão da wiked");
    }
    else if(!strcmp(funcao, "RETIRALINK")){
        char nomepaginaOrigem[MAX_TAM], nomepaginaDestino[MAX_TAM];
        fscanf(entrada, " %s %s ", nomepaginaOrigem, nomepaginaDestino);

        fprintf(log, "Funcao --- nao suportada na versão da wiked");
    }
    else if(!strcmp(funcao, "CAMINHO")){
        char nomepaginaOrigem[MAX_TAM], nomepaginaDestino[MAX_TAM];
        fscanf(entrada, " %s %s ", nomepaginaOrigem, nomepaginaDestino);

        fprintf(log, "Funcao --- nao suportada na versão da wiked");
    }
    
    else if(!strcmp(funcao, "IMPRIMEWIKED")){
        // imprime a lista
        fprintf(log, "Funcao --- nao suportada na versão da wiked");
    }
    else{
        fprintf(log, "função %s não encontrada! saindo do programa...\n", funcao);
        return;
    }
}