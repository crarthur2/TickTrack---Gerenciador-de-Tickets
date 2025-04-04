#ifndef USUARIO_H    
#define USUARIO_H    

#include "pessoa.h"
#include "data.h"

#define MAX_TAM_SETOR 15

typedef struct Usuario Usuario;

char* retornaSetorUsuario(Usuario *u);

Usuario* leUsuario();

void imprimeUsuario(Usuario *u);

void desalocaUsuario(Usuario *u);

char *retornaCpfUsuario(Usuario *u);

char retornaTipoUsuario();

int retornaQtdTicketsUsuario(Usuario *u);

void atualizaQtdTicketsUsuario(Usuario *u);

int comparaUsuarios(const void *u1, const void *u2);

char *retornaNomeUsuario(Usuario *u);

int verificaCpfUsuario(Usuario *u, char *cpf);

int retornaIdadeUsuario(Usuario *u);

Usuario *copiaUsuario(Usuario *original);

#endif
