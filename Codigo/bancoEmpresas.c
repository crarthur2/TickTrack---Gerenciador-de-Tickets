#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bancoEmpresas.h"

struct bancoEmpresas{
    Empresa **empresas;
    int qtd_empresas;
    int alocada;
};

bancoEmpresas *criaBancoEmpresas(){
    bancoEmpresas *b = (bancoEmpresas*) malloc(sizeof(bancoEmpresas));

    b->qtd_empresas = 0;
    b->alocada = 5;

    b->empresas = (Empresa**) malloc(sizeof(Empresa*) * b->alocada);

    return b;
}

void desalocaBancoEmpresas(bancoEmpresas *b){
    if(b != NULL){
        if(b->empresas != NULL){
            for(int i = 0; i < b->qtd_empresas; i++){
                desalocaEmpresa(b->empresas[i]);
            }
            free(b->empresas);
        }
        free(b);
    }
}

void imprimeBancoEmpresas(bancoEmpresas *b){
    printf("----- EMPRESAS FORNECEDORAS -----\n");
    for(int i = 0; i < b->qtd_empresas; i++){
        printf("--------------------\n");
        imprimeEmpresa(b->empresas[i]);
    }
    printf("----------------------------\n\n");
}

void insereEmpresaNoBanco(bancoEmpresas *b, Empresa *e){
    if(b->qtd_empresas == b->alocada){
        b->alocada += 5;
        b->empresas = realloc(b->empresas, sizeof(Empresa*) * b->alocada);
    }

    b->empresas[b->qtd_empresas] = e;
    b->qtd_empresas++;
}

int verificaEmpresaJaCadastrada(bancoEmpresas *e, char *cnpj){
    for(int i = 0; i < e->qtd_empresas; i++){
        if(strcmp(retornaCnpj(e->empresas[i]), cnpj) == 0){
            return 1;
        }
    }
    return 0;
}