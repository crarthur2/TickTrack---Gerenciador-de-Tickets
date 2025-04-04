#ifndef EMPRESA_H
#define EMPRESA_H

#define MAX_NOME_EMPRESA 81
#define CNPJ 19
#define PAIS 31
#define RAMO 31
#define EMAIL 51 

#include "data.h"

typedef struct Empresa Empresa;

Empresa *leEmpresa();

void desalocaEmpresa(Empresa *e);

void imprimeEmpresa(Empresa *e);

char* retornaCnpj(Empresa *e);

#endif