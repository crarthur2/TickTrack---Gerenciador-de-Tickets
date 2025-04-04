#include "pessoa.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char nome[MAX_TAM_NOME];
    char cpf[MAX_TAM_CPF];
    Data* nascimento;
    char telefone[MAX_TAM_TELEFONE];
    char genero[MAX_TAM_GENERO];
};

Pessoa *lePessoa(){
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));

    scanf("%[^\n]\n", p->nome);
    scanf("%[^\n]\n", p->cpf);
    p->nascimento = leData();
    scanf("%[^\n]\n", p->telefone);
    scanf("%[^\n]\n", p->genero);

    return p;
}

void liberaPessoa(Pessoa *p){
    if(p != NULL){
        liberaData(p->nascimento);
        free(p);
    }
}

void imprimePessoa(Pessoa *p){
    if(p != NULL){
        printf("- Nome: %s\n", p->nome);
        printf("- CPF: %s\n", p->cpf);
        imprimeData(p->nascimento);
        printf("- Telefone: %s\n", p->telefone);
        printf("- Genero: %s\n", p->genero);
    }
}

int verificaCpf(Pessoa *p, char *cpf){
    if(strcmp(p->cpf, cpf) == 0){
        return 1;
    }   
    return 0;
}

Data *retornaNascimento(Pessoa *p){
    return p->nascimento;
}

char *retornaCpfPessoa(Pessoa *p){
    return p->cpf;
}

char *retornaNomePessoa(Pessoa *p){
    return p->nome;
}

Pessoa *copiaPessoa(Pessoa *original){
    Pessoa *copia = (Pessoa*) malloc(sizeof(Pessoa));

    strcpy(copia->nome, original->nome);
    strcpy(copia->cpf, original->cpf);
    strcpy(copia->genero, original->genero);
    strcpy(copia->telefone, original->telefone);
    copia->nascimento = copiaData(original->nascimento);
    
    return copia;
}