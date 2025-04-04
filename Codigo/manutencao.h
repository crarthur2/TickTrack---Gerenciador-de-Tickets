#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

typedef struct Manutencao Manutencao;

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_ESTADO 8
#define MAX_LOCAL 100

Manutencao *criaManutencao(char *nome, char *estado, char *localizacao);

Manutencao *leManutencao();

void desalocaManutencao(void *dado);

void setTempoEstimadoManutencao(Manutencao *m, char *setor);

int getTempoEstimadoManutencao(void *dado);

char* getEstado(Manutencao *m);

char getTipoManutencao();

void notificaManutencao(void *dado); //funcao de impressao


#endif
