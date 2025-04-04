#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct Data{
    int dia, mes, ano;
};

Data* leData(){
    Data *d = (Data*) malloc(sizeof(Data));

    scanf("%d/%d/%d\n", &d->dia, &d->mes, &d->ano);

    return d;
}

void imprimeData(Data *d){
    printf("- Data de Nascimento: %d/%d/%d\n", d->dia, d->mes, d->ano);
}

void liberaData(Data *d){
    if(d != NULL){
        free(d);
    }
}

int calculaIdade(Data *nascimento, Data *data){
    int diff = data->ano - nascimento->ano;

    if(nascimento->mes == data->mes && nascimento->dia > data->dia){
        diff--;
    }
    else if(nascimento->mes > data->mes){
        diff--;
    }

    return diff;
}

Data* setaData(int d, int m, int a){
    Data *data = (Data*) malloc(sizeof(Data));

    data->dia = d;
    data->mes = m;
    data->ano = a;

    return data;
}

Data *copiaData(Data *original){
    Data *copia = (Data*) malloc(sizeof(Data));

    copia->dia = original->dia;
    copia->mes = original->mes;
    copia->ano = original->ano;
    
    return copia;
}

void imprimeSoData(Data *d){
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}