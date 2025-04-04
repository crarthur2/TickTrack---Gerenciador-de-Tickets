#ifndef TECNICO_H
#define TECNICO_H

#include "pessoa.h"
#include "data.h"

#define MAX_TAM_AREA 50

typedef struct Tecnico Tecnico;

Tecnico *leTecnico();

char *retornaAreaTecnico(Tecnico *t);

float retornaSalarioTecnico(Tecnico *t);

int retornaDisponibilidadeTecnico(Tecnico *t);

void imprimeTecnico(Tecnico *t);

void desalocaTecnico(Tecnico *t);

void atualizaTecnico(Tecnico *t, int tempo);

int retornaTempoTrabalhado(Tecnico *t);

char retornaTipoTecnico();

int comparaTecnico(const void *t1, const void *t2);

char *retornaNomeTecnico(Tecnico *t);

int verificaCpfTecnico(Tecnico *t, char *cpf);

char *retornaCpfTecnico(Tecnico *t);

int retornaIdadeTecnico(Tecnico *t);

Tecnico *copiaTecnico(Tecnico *original);

#endif
