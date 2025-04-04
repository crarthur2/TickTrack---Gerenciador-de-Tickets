#include "bancoUsuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BancoUsuario{
    Usuario **usuarios;
    int qtd_usuarios;
    int espaco_alocado;
};

BancoUsuario *criaBancoUsuario(){
    BancoUsuario *b = (BancoUsuario*) malloc(sizeof(BancoUsuario));

    b->espaco_alocado = 5;
    b->qtd_usuarios = 0;

    b->usuarios = (Usuario**) malloc(sizeof(Usuario*) * b->espaco_alocado);

    return b;
}

void desalocaBancoUsuario(BancoUsuario *b){
    if(b != NULL){
        if(b->usuarios != NULL){
            for(int i = 0; i < b->qtd_usuarios; i++){
                if(b->usuarios[i] != NULL){
                    desalocaUsuario(b->usuarios[i]);    
                }
            }
            free(b->usuarios);
        }
        free(b);
    }
}

void imprimeBancoUsuario(BancoUsuario *b){
    printf("----- BANCO DE USUARIOS -----\n");
    for(int i = 0; i < b->qtd_usuarios; i++){
        printf("--------------------\n");
        imprimeUsuario(b->usuarios[i]);
    }
    printf("----------------------------\n\n");

}

void insereUsuarioBanco(BancoUsuario *b, Usuario *u){
    if(b->qtd_usuarios == b->espaco_alocado){
        b->espaco_alocado += 5;
        b->usuarios = realloc(b->usuarios, sizeof(Usuario*) * b->espaco_alocado);
    }

    b->usuarios[b->qtd_usuarios] = u;
    b->qtd_usuarios++;
}

void imprimeRankingUsuario(BancoUsuario *b){
    BancoUsuario *tempBanco = (BancoUsuario*) malloc(sizeof(BancoUsuario));

    tempBanco->qtd_usuarios = retornaQtdUsuarios(b);
    tempBanco->usuarios = (Usuario**) malloc(sizeof(Usuario*) * tempBanco->qtd_usuarios);

    for(int i = 0; i < tempBanco->qtd_usuarios; i++){
        Usuario *original = retornaUsuarioPorIdx(b, i);
        tempBanco->usuarios[i] = copiaUsuario(original);
    }

    ordenaBancoUsuario(tempBanco);

    printf("----- RANKING DE USUARIOS -----\n");
    for(int i = 0; i < tempBanco->qtd_usuarios; i++){
        printf("--------------------\n");
        imprimeUsuario(tempBanco->usuarios[i]);
    }
    printf("-------------------------------\n\n");

    desalocaBancoUsuario(tempBanco);
}

/*
    Essa funcao ordena o banco de usuarios na ordem decrescente quanto
ao numero de tickets abertos
*/

void ordenaBancoUsuario(BancoUsuario *b){
    qsort(b->usuarios, b->qtd_usuarios, sizeof(Usuario*), comparaUsuarios);
}

int verificaUsuarioJaCadastrado(BancoUsuario *b, char *cpf){
    for(int i = 0; i < b->qtd_usuarios; i++){
        if(verificaCpfUsuario(b->usuarios[i], cpf) == 1){
            return 1;
        }
    }
    return 0;
}

void atualizaUsuarioBanco(BancoUsuario *b, char *cpfUser){
    for(int i = 0; i < b->qtd_usuarios; i++){
        if(strcmp(retornaCpfUsuario(b->usuarios[i]), cpfUser) == 0){
            atualizaQtdTicketsUsuario(b->usuarios[i]);
        }
    }
}

char *retornaSetorUsuarioBanco(BancoUsuario *b, char *cpf){
    for(int i = 0; i < b->qtd_usuarios; i++){
        if(strcmp(retornaCpfUsuario(b->usuarios[i]), cpf) == 0){
            return retornaSetorUsuario(b->usuarios[i]);
        }
    }
}

int retornaQtdUsuarios(BancoUsuario *b){
    return b->qtd_usuarios;
}

int calculaMediaIdadesUsuarios(BancoUsuario *b){
    int media, soma = 0;

    for(int i = 0; i < b->qtd_usuarios; i++){
        soma += retornaIdadeUsuario(b->usuarios[i]);
    }

    media = soma / b->qtd_usuarios;
    return media;
}

Usuario *retornaUsuarioPorIdx(BancoUsuario *b, int idx){
    if(idx >= 0 && idx < b->qtd_usuarios){
        return b->usuarios[idx];
    }
}
