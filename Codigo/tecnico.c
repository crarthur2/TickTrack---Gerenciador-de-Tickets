#include "tecnico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tecnico{
    Pessoa *p;
    char area[MAX_TAM_AREA];
    int dispTempo;
    float salario;
    int idade;
    int tempoTrabalhado;
};

Tecnico *leTecnico(){
    Tecnico *t = (Tecnico*) malloc(sizeof(Tecnico));

    t->p = lePessoa();
    scanf("%[^\n]\n", t->area);
    scanf("%d\n", &t->dispTempo);
    scanf("%f\n", &t->salario);
    
    Data *temp = setaData(18,2,2025);
    t->idade = calculaIdade(retornaNascimento(t->p), temp);
    liberaData(temp);
    t->tempoTrabalhado = 0;

    return t;
}

char *retornaAreaTecnico(Tecnico *t){
    return t->area;
}

float retornaSalarioTecnico(Tecnico *t){
    return t->salario;
}

int retornaDisponibilidadeTecnico(Tecnico *t){
    return t->dispTempo;
}

void imprimeTecnico(Tecnico *t){
    imprimePessoa(t->p);
    printf("- Area de Atuacao: %s\n", retornaAreaTecnico(t));
    printf("- Salario: %.2f\n", retornaSalarioTecnico(t));
    printf("- Disponibilidade: %dh\n", retornaDisponibilidadeTecnico(t));
    printf("- Tempo Trabalhado: %dh\n", retornaTempoTrabalhado(t));
}

void desalocaTecnico(Tecnico *t){
    if(t != NULL){
        if(t->p != NULL){
            liberaPessoa(t->p);
        }
        free(t);
    }
}

void atualizaTecnico(Tecnico *t, int tempo){
    t->dispTempo -= tempo;
    t->tempoTrabalhado += tempo;
}

int retornaTempoTrabalhado(Tecnico *t){
    return t->tempoTrabalhado;
}

char retornaTipoTecnico(){
    char tipo = 'T';
    return tipo;
}

int comparaTecnico(const void *t1, const void *t2){
    Tecnico *tec1 = *(Tecnico**) t1;
    Tecnico *tec2 = *(Tecnico**) t2;

    if(tec2->tempoTrabalhado > tec1->tempoTrabalhado){
        return 1;
    }
    else if(tec1->tempoTrabalhado == tec2->tempoTrabalhado){
        return strcmp(retornaNomeTecnico(tec1), retornaNomeTecnico(tec2));
    }
    else{
        return 0;
    }
}

char *retornaNomeTecnico(Tecnico *t){
    return retornaNomePessoa(t->p);
}

int verificaCpfTecnico(Tecnico *t, char *cpf){
    if(strcmp(retornaCpfPessoa(t->p), cpf) == 0){
        return 1;
    }
    return 0;
}

char *retornaCpfTecnico(Tecnico *t){
    return retornaCpfPessoa(t->p);
}

int retornaIdadeTecnico(Tecnico *t){
    return t->idade;
}

Tecnico *copiaTecnico(Tecnico *original){
    Tecnico *copia = (Tecnico*) malloc(sizeof(Tecnico));

    strcpy(copia->area, original->area);
    copia->dispTempo = original->dispTempo;
    copia->idade = original->idade;
    copia->salario = original->salario;
    copia->tempoTrabalhado = original->tempoTrabalhado;
    copia->p = copiaPessoa(original->p);    

    return copia;
}