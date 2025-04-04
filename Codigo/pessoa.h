#ifndef _PESSOA_H
#define _PESSOA_H

typedef struct Pessoa Pessoa;

#include "data.h"

#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15
#define MAX_TAM_TELEFONE 15
#define MAX_TAM_GENERO 10

Pessoa *lePessoa();

void liberaPessoa(Pessoa *p);

void imprimePessoa(Pessoa *p);

int verificaCpf(Pessoa *p, char *cpf);

Data *retornaNascimento(Pessoa *p);

char *retornaCpfPessoa(Pessoa *p);

char *retornaNomePessoa(Pessoa *p);

Pessoa *copiaPessoa(Pessoa *original);

#endif
