#ifndef HARDWARE_H
#define HARDWARE_H

#define MAX_TAM_DESC 500
#define MAX_TAM_LOCAL 100

typedef struct Hardware Hardware;

Hardware *leHardware();

char getTipoHard();

int getTempoEstimado(void *dado);

void desalocaHardware(void *dado);

void notificaHardware(void *dado);

void setaTempoEstimadoHardware(Hardware *h);

#endif