#include "software.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Software{
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    int impacto;
    char motivo[MAX_TAM_MOTIVO];
    int tempo_estimado;
};

/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){
    Software *s = (Software*) malloc(sizeof(Software));

    if(s == NULL){
        printf("Erro ao criar software\n");
        exit(1);
    } 

    strcpy(s->nome, nome);
    strcpy(s->categoria, categoria);
    s->impacto = impacto;
    strcpy(s->motivo, motivo);

    return s;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware(){
    Software *s = (Software*) malloc(sizeof(Software));

    scanf("%[^\n]\n", s->nome);
    scanf("%[^\n]\n", s->categoria);
    scanf("%d\n", &s->impacto);
    scanf("%[^\n]\n", s->motivo);

    return s;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s){
    if(strcmp(s->categoria, "BUG") == 0){
        s->tempo_estimado = 3 + s->impacto;
    }
    else if(strcmp(s->categoria, "OUTROS") == 0){
        s->tempo_estimado = 2 + s->impacto;
    }
    else if(strcmp(s->categoria, "DUVIDA") == 0){
        s->tempo_estimado = 1 + s->impacto;
    }
    else{
        s->tempo_estimado = s->impacto;
    }
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado){
    Software *s = (Software*) dado;
    return s->tempo_estimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware(){
    char tipo = 'S';
    return tipo;
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s){
    free(s);
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado){
    Software *s = (Software*) dado;
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", s->nome);
    printf("- Categoria: %s\n", s->categoria);
    printf("- Nível do impacto: %d\n", s->impacto);
    printf("- Motivo: %s\n", s->motivo);
    printf("- Tempo estimado: %dh\n", getTempoEstimadoSoftware(dado));
}
