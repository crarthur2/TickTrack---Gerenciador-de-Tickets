#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Manutencao{
    char tipo;      //'M'
    char nome_item[MAX_TAM_NOME_MANUTENCAO];
    char estado_item[MAX_TAM_ESTADO];
    char localizacao[MAX_LOCAL];
    int tempo_estimado;
};

Manutencao *criaManutencao(char *nome, char *estado, char *localizacao){
    Manutencao *m = (Manutencao*) malloc(sizeof(Manutencao));

    strcpy(m->nome_item, nome);
    strcpy(m->estado_item, estado);
    strcpy(m->localizacao, localizacao);
    m->tipo = 'M';

    return m;
}

Manutencao *leManutencao(){
    Manutencao *m = (Manutencao*) malloc(sizeof(Manutencao));

    scanf("%[^\n]\n", m->nome_item);
    scanf("%[^\n]\n", m->estado_item);
    scanf("%[^\n]\n", m->localizacao);

    return m;
}

void desalocaManutencao(void *dado){
    free(dado);
}

char* getEstado(Manutencao *m){
    return m->estado_item;
}

void setTempoEstimadoManutencao(Manutencao *m, char *setor){

    if(strcmp(m->estado_item, "RUIM") == 0){
        if(strcmp(setor, "RH") == 0){
            m->tempo_estimado = 3 * 2;
        }
        else if(strcmp(setor, "FINANCEIRO") == 0){
            m->tempo_estimado = 3 * 3;
        }
        else if(strcmp(setor, "P&D") == 0){
            m->tempo_estimado = 3 * 1;
        }
        else if(strcmp(setor, "VENDAS") == 0){
            m->tempo_estimado = 3 * 1;
        }
        else if(strcmp(setor, "MARKETING") == 0){
            m->tempo_estimado = 3 * 1;
        }
    }
    else if(strcmp(m->estado_item, "REGULAR") == 0){
        if(strcmp(setor, "RH") == 0){
            m->tempo_estimado = 2 * 2;
        }
        else if(strcmp(setor, "FINANCEIRO") == 0){
            m->tempo_estimado = 2 * 3;
        }
        else if(strcmp(setor, "P&D") == 0){
            m->tempo_estimado = 2 * 1;
        }
        else if(strcmp(setor, "VENDAS") == 0){
            m->tempo_estimado = 2 * 1;
        }
        else if(strcmp(setor, "MARKETING") == 0){
            m->tempo_estimado = 2 * 1;
        }
    }
    else if(strcmp(m->estado_item, "BOM") == 0){
        if(strcmp(setor, "RH") == 0){
            m->tempo_estimado = 1 * 2;
        }
        else if(strcmp(setor, "FINANCEIRO") == 0){
            m->tempo_estimado = 1 * 3;
        }
        else if(strcmp(setor, "P&D") == 0){
            m->tempo_estimado = 1 * 1;
        }
        else if(strcmp(setor, "VENDAS") == 0){
            m->tempo_estimado = 1 * 1;
        }
        else if(strcmp(setor, "MARKETING") == 0){
            m->tempo_estimado = 1 * 1;
        }
    }
}

int getTempoEstimadoManutencao(void *dado){
    Manutencao *m = (Manutencao*) dado;
    return m->tempo_estimado;
}

char getTipoManutencao(){
    char tipo = 'M';
    return tipo;
}

void notificaManutencao(void *dado){
    Manutencao *m = (Manutencao*) dado;

    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", m->nome_item);
    printf("- Estado de conservacao: %s\n", m->estado_item);
    printf("- Local: %s\n", m->localizacao);
    printf("- Tempo estimado: %dh\n", m->tempo_estimado);

}
