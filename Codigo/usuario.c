#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuario{
    Pessoa *p;
    char setor[MAX_TAM_SETOR];
    int idade;
    int qtd_tickets;
};

char* retornaSetorUsuario(Usuario *u){
    if(u != NULL){
        return u->setor;
    }
}

Usuario* leUsuario(){
    Usuario *u = (Usuario*) malloc(sizeof(Usuario));

    u->p = lePessoa();
    scanf("%[^\n]\n", u->setor);
    
    Data *temp = setaData(18,2,2025);
    u->idade = calculaIdade(retornaNascimento(u->p), temp);
    liberaData(temp);
    u->qtd_tickets = 0;

    return u;
}

void imprimeUsuario(Usuario *u){
    imprimePessoa(u->p);
    printf("- Setor: %s\n", retornaSetorUsuario(u));
    printf("- Tickets solicitados: %d\n", retornaQtdTicketsUsuario(u));
}

void desalocaUsuario(Usuario *u){
    if(u != NULL){
        if(u->p != NULL){
            liberaPessoa(u->p);
        }
        free(u);
    }
}

char *retornaCpfUsuario(Usuario *u){
    return retornaCpfPessoa(u->p);
}

char retornaTipoUsuario(){
    char tipo = 'U';
    return tipo;
}

int retornaQtdTicketsUsuario(Usuario *u){
    return u->qtd_tickets;
}

void atualizaQtdTicketsUsuario(Usuario *u){
    u->qtd_tickets++;
}

int comparaUsuarios(const void *u1, const void *u2){
    Usuario *user1 = *(Usuario**)u1;
    Usuario *user2 = *(Usuario**)u2;

    if(user2->qtd_tickets > user1->qtd_tickets){
        return 1;
    }
    else if(user1->qtd_tickets == user2->qtd_tickets){
        return strcmp(retornaNomeUsuario(user1), retornaNomeUsuario(user2));
    }
    else{
        return 0;
    }
}

char *retornaNomeUsuario(Usuario *u){
    return retornaNomePessoa(u->p);
}

int verificaCpfUsuario(Usuario *u, char *cpf){
    if(strcmp(retornaCpfUsuario(u), cpf) == 0){
        return 1;
    }
    return 0;
}

int retornaIdadeUsuario(Usuario *u){
    return u->idade;
}

Usuario *copiaUsuario(Usuario *original){
    Usuario *copia = (Usuario*) malloc(sizeof(Usuario));

    copia->p = copiaPessoa(original->p);
    copia->idade = original->idade;
    copia->qtd_tickets = original->qtd_tickets;
    strcpy(copia->setor, original->setor);

    return copia;
}