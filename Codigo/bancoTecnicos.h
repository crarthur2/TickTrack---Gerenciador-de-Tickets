#ifndef BANCO_TECNICOS_H
#define BANCO_TECNICOS_H

#include "tecnico.h"

typedef struct BancoTecnicos BancoTecnicos;

BancoTecnicos *criaBancoTecnicos();

void desalocaBancoTecnicos(BancoTecnicos *b);

void imprimeBancoTecnicos(BancoTecnicos *b);

void insereTecnicoBanco(BancoTecnicos *b, Tecnico *t);

void imprimeRankingTecnicos(BancoTecnicos *b);

void ordenaBancoTecnicos(BancoTecnicos *b);

int verificaTecnicoJaCadastrado(BancoTecnicos *b, char *cpf);

int calculaMediaIdadeTecnicos(BancoTecnicos *b);

int retornaQtdTecnicos(BancoTecnicos *b);

int calculaMediaTrabalhoTecnicos(BancoTecnicos *b);

Tecnico *retornaTecnicoPorIdx(BancoTecnicos *b, int idx);

void imprimeRelatorioTecnicos(BancoTecnicos *b);

int mediaSalario(BancoTecnicos *b);

int mediaDisponibilidade(BancoTecnicos *b);

#endif
