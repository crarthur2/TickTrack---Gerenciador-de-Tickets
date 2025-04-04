#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

struct Empresa{
    char nome[MAX_NOME_EMPRESA];
    char cnpj[CNPJ];
    Data *dataInicio;
    char pais[PAIS];
    char ramo[RAMO];
    char email[EMAIL];
};

Empresa *leEmpresa(){
    Empresa *e = (Empresa*) malloc(sizeof(Empresa));

    scanf("%[^\n]\n", e->nome);
    scanf("%[^\n]\n", e->cnpj);
    e->dataInicio = leData();
    scanf("%[^\n]\n", e->pais);
    scanf("%[^\n]\n", e->ramo);
    scanf("%[^\n]\n", e->email);

    return e;
}

void desalocaEmpresa(Empresa *e){
    liberaData(e->dataInicio);
    free(e);
}

void imprimeEmpresa(Empresa *e){
    printf("- Nome: %s\n", e->nome);
    printf("- CNPJ: %s\n", e->cnpj);
    printf("- Inicio da Parceria: ");
    imprimeSoData(e->dataInicio);
    printf("- Pais de Origem: %s\n", e->pais);
    printf("- Ramo de Atuacao: %s\n", e->ramo);
    printf("- Email: %s\n", e->email);
}

char* retornaCnpj(Empresa *e){
    return e->cnpj;
}