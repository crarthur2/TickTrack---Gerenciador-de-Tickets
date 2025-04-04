#include "outros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Outros{
    char tipo;
    char desc[MAX_DESC];
    char loc[MAX_LOCAL_OUTROS];
    int dificuldade;
    int tempo_estimado;
};

Outros* criaOutros(char *desc, char *loc, int nivel){
    Outros *o = (Outros*) malloc(sizeof(Outros));

    strcpy(o->desc, desc);
    strcpy(o->loc, loc);
    o->dificuldade = nivel;

    return o;
}

Outros* leOutros(){
    Outros *o = (Outros*) malloc(sizeof(Outros));

    scanf("%[^\n]\n", o->desc);
    scanf("%[^\n]\n", o->loc);
    scanf("%d\n", &o->dificuldade);
    
    return o;
}

void setTempoEstimadoOutros(Outros *o){
    o->tempo_estimado = o->dificuldade;
}

int getTempoEstimadoOutros(void *dado){
    Outros *o = (Outros*) dado;
    return o->tempo_estimado;
}

char getTipoOutros(){
    char tipo = 'O';
    return tipo;
}

void desalocaOutros(void *dado){
    free(dado);
}

void notificaOutros(void *dado){
    Outros *o = (Outros*) dado;
    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", o->desc);
    printf("- Local: %s\n", o->loc);
    printf("- Nivel de Dificuldade: %d\n", o->dificuldade);
    printf("- Tempo Estimado: %dh\n", o->tempo_estimado);
}   
