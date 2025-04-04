#ifndef SISTEMA_H
#define SISTEMA_H

#include "bancoTecnicos.h"
#include "bancoUsuario.h"
#include "fila.h"
#include "software.h"
#include "manutencao.h"
#include "outros.h"
#include "hardware.h"
#include "bancoEmpresas.h"

typedef struct Sistema Sistema;

Sistema *criaSistema();

void rodaSistema(Sistema *s);

void desalocaSistema(Sistema *s);

void geraRelatorio(Sistema *s);

void distribuiTickets(Sistema *s);

#endif