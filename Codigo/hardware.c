#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"

struct Hardware{
    char nome[MAX_TAM_LOCAL];
    int tipo_maquina;
    int tipo_problema;
    char motivo[MAX_TAM_DESC];
    int tempo_estimado;
};

Hardware *leHardware(){
    Hardware *h = (Hardware*) malloc(sizeof(Hardware));

    scanf("%[^\n]\n", h->nome);
    scanf("%d\n", &h->tipo_maquina);
    scanf("%d\n", &h->tipo_problema);
    scanf("%[^\n]\n", h->motivo);

    return h;
}

char getTipoHard(){
    return 'H';
}

int getTempoEstimado(void *dado){
    Hardware *h = (Hardware*) dado;

    return h->tempo_estimado;
}

void desalocaHardware(void *dado){
    free(dado);
}

void notificaHardware(void *dado){
    Hardware *h = (Hardware*) dado;
    printf("- Tipo: Hardware\n");
    printf("- Nome do hardware: %s\n", h->nome);
    printf("- Tipo da maquina: %d\n", h->tipo_maquina);
    printf("- Tipo do problema: %d\n", h->tipo_problema);
    printf("- Motivo: %s\n", h->motivo);
    printf("- Tempo estimado: %dh\n", h->tempo_estimado);
}

void setaTempoEstimadoHardware(Hardware *h){
    h->tempo_estimado = h->tipo_maquina + h->tipo_problema;
}
