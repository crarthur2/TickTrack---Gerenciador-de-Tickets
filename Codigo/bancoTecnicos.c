#include "bancoTecnicos.h"
#include <stdio.h>
#include <stdlib.h>

struct BancoTecnicos{
    Tecnico **tecnicos;
    int qtd_tecnicos;
    int espaco_alocado;
};

BancoTecnicos *criaBancoTecnicos(){
    BancoTecnicos *b = (BancoTecnicos*) malloc(sizeof(BancoTecnicos));

    b->qtd_tecnicos = 0;
    b->espaco_alocado = 5;

    b->tecnicos = (Tecnico**) malloc(sizeof(Tecnico*) * b->espaco_alocado);

    return b;
}

void desalocaBancoTecnicos(BancoTecnicos *b){
    if(b != NULL){
        if(b->tecnicos != NULL){
            for(int i = 0; i < b->qtd_tecnicos; i++){
                if(b->tecnicos[i] != NULL){
                    desalocaTecnico(b->tecnicos[i]);
                }
            }
            free(b->tecnicos);
        }
        free(b);
    }
}

void imprimeBancoTecnicos(BancoTecnicos *b){
    printf("----- BANCO DE TECNICOS -----\n");
    for(int i = 0; i < b->qtd_tecnicos; i++){
        printf("--------------------\n");
        imprimeTecnico(b->tecnicos[i]);
    }
    printf("----------------------------\n\n");
}

void insereTecnicoBanco(BancoTecnicos *b, Tecnico *t){
    if(b->qtd_tecnicos == b->espaco_alocado){
        b->espaco_alocado += 5;
        b->tecnicos = realloc(b->tecnicos, sizeof(Tecnico*) * b->espaco_alocado);
    }
    b->tecnicos[b->qtd_tecnicos] = t;
    b->qtd_tecnicos++;
}

void imprimeRankingTecnicos(BancoTecnicos *b){
    BancoTecnicos *tempBanco = (BancoTecnicos*) malloc(sizeof(BancoTecnicos));

    tempBanco->qtd_tecnicos = retornaQtdTecnicos(b);
    tempBanco->tecnicos = (Tecnico**) malloc(sizeof(Tecnico*) * tempBanco->qtd_tecnicos);
    
    for(int i = 0; i < tempBanco->qtd_tecnicos; i++){
        Tecnico *original = retornaTecnicoPorIdx(b, i);
        tempBanco->tecnicos[i] = copiaTecnico(original);
    }

    ordenaBancoTecnicos(tempBanco);

    printf("----- RANKING DE TECNICOS -----\n");
    for(int i = 0; i < tempBanco->qtd_tecnicos; i++){
        printf("--------------------\n");
        imprimeTecnico(tempBanco->tecnicos[i]);
    }
    printf("-------------------------------\n\n");

    desalocaBancoTecnicos(tempBanco);
}

void ordenaBancoTecnicos(BancoTecnicos *b){
    qsort(b->tecnicos, b->qtd_tecnicos, sizeof(Tecnico*), comparaTecnico);
}

int verificaTecnicoJaCadastrado(BancoTecnicos *b, char *cpf){
    for(int i = 0; i < b->qtd_tecnicos; i++){
        if(verificaCpfTecnico(b->tecnicos[i], cpf) == 1){
            return 1;
        }
    }
    return 0;
}

int calculaMediaIdadeTecnicos(BancoTecnicos *b){
    int media, soma = 0;
    
    for(int i = 0; i < b->qtd_tecnicos; i++){
        soma += retornaIdadeTecnico(b->tecnicos[i]);
    }
    media = soma / b->qtd_tecnicos;
    return media;
}

int retornaQtdTecnicos(BancoTecnicos *b){
    return b->qtd_tecnicos;
}

int calculaMediaTrabalhoTecnicos(BancoTecnicos *b){
    int media, soma = 0;

    for(int i = 0; i < b->qtd_tecnicos; i++){
        soma += retornaTempoTrabalhado(b->tecnicos[i]);
    }
    media = soma / b->qtd_tecnicos;
    return media;
}

Tecnico *retornaTecnicoPorIdx(BancoTecnicos *b, int idx){
    if(idx >= 0 && idx < b->qtd_tecnicos){
        return b->tecnicos[idx];
    }
}

void imprimeRelatorioTecnicos(BancoTecnicos *b){
    int media_idade = calculaMediaIdadeTecnicos(b);
    int media_trabalhado = calculaMediaTrabalhoTecnicos(b);
    int qtd_tecnicos = retornaQtdTecnicos(b);
    int media_disp = mediaDisponibilidade(b);
    int media_salario = mediaSalario(b);

    printf("----- RELATORIO TECNICOS -----\n");
    printf("- Qtd tecnicos: %d\n", qtd_tecnicos);
    printf("- Md idade tecnicos: %d\n", media_idade);
    printf("- Md trabalho tecnicos: %d\n", media_trabalhado);
    printf("- Md disponibilidade tecnicos: %d\n", media_disp);
    printf("- Md salario tecnicos: %d\n", media_salario);
    printf("-------------------------------\n\n");

}

int mediaSalario(BancoTecnicos *b){
    int media, soma = 0;

    for(int i = 0; i < b->qtd_tecnicos; i++){
        soma += (int) retornaSalarioTecnico(b->tecnicos[i]);
    }
    media = soma / b->qtd_tecnicos;
    return media;
}

int mediaDisponibilidade(BancoTecnicos *b){
    int media, soma = 0;

    for(int i = 0; i < b->qtd_tecnicos; i++){
        soma += retornaDisponibilidadeTecnico(b->tecnicos[i]);
    }

    media = soma / b->qtd_tecnicos;
    return media;
}


