#ifndef BANCO_EMPRESAS_H
#define BANCO_EMPRESAS_H

#include "empresa.h"

typedef struct bancoEmpresas bancoEmpresas;

bancoEmpresas *criaBancoEmpresas();

void desalocaBancoEmpresas(bancoEmpresas *b);

void imprimeBancoEmpresas(bancoEmpresas *b);

void insereEmpresaNoBanco(bancoEmpresas *b, Empresa *e);

int verificaEmpresaJaCadastrada(bancoEmpresas *e, char *cnpj);


#endif