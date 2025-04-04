#ifndef _OUTROS_H
#define _OUTROS_H

typedef struct Outros Outros;

#define MAX_DESC 500
#define MAX_LOCAL_OUTROS 100

Outros* criaOutros(char *desc, char *loc, int nivel);

Outros* leOutros();

void setTempoEstimadoOutros(Outros *o);

int getTempoEstimadoOutros(void *dado);

char getTipoOutros();

void desalocaOutros(void *dado);

void notificaOutros(void *dado);    //Funcao de impressao


#endif