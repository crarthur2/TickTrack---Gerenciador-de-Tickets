#ifndef BANCO_USUARIO_H  
#define BANCO_USUARIO_H  

#include "usuario.h"
#include "manutencao.h"

typedef struct BancoUsuario BancoUsuario;

BancoUsuario *criaBancoUsuario();

void desalocaBancoUsuario(BancoUsuario *b);

void imprimeBancoUsuario(BancoUsuario *b);

void insereUsuarioBanco(BancoUsuario *b, Usuario *u);

void imprimeRankingUsuario(BancoUsuario *b);

void ordenaBancoUsuario(BancoUsuario *b);

int verificaUsuarioJaCadastrado(BancoUsuario *b, char *cpf);

void atualizaUsuarioBanco(BancoUsuario *b, char *cpfUser);

char *retornaSetorUsuarioBanco(BancoUsuario *b, char *cpf);

int retornaQtdUsuarios(BancoUsuario *b);

int calculaMediaIdadesUsuarios(BancoUsuario *b);

Usuario *retornaUsuarioPorIdx(BancoUsuario *b, int idx);

#endif
