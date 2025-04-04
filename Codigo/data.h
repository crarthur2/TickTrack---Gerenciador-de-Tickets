#ifndef _DATA_H
#define _DATA_H

typedef struct Data Data;

Data* leData();

void imprimeData(Data *d);

void liberaData(Data *d);

int calculaIdade(Data *nascimento, Data *data);

Data* setaData(int d, int m, int a); 

Data *copiaData(Data *original);

void imprimeSoData(Data *d);

#endif
