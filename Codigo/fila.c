#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    Ticket **elementos;
    int qtd_elementos;
    int elementos_alocados;
};

/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    if(f == NULL){
        printf("Erro ao criar fila\n");
        exit(1);
    }

    f->qtd_elementos = 0;
    f->elementos_alocados = 10;
    f->elementos = (Ticket**) malloc(f->elementos_alocados * sizeof(Ticket*));

    return f;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
void desalocaFila(Fila *f){
    if(f != NULL){
        if(f->elementos != NULL){
            for(int i = 0; i < f->qtd_elementos; i++){
               desalocaTicket(f->elementos[i]);
            }
            free(f->elementos);
        }
        free(f);
    }
}

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                      func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
                        if(f != NULL){
                            if(f->qtd_elementos == f->elementos_alocados){
                                int nova_alocacao = f->elementos_alocados * 2;
                                Ticket **temp_ticket = realloc(f->elementos, nova_alocacao * sizeof(Ticket*));

                                if(temp_ticket == NULL){
                                    printf("Erro ao inserir elemento na lista\n");
                                    exit(1);
                                }

                                f->elementos = temp_ticket;
                                f->elementos_alocados = nova_alocacao;
                            }

                            Ticket *temp_ticket2 = criaTicket(cpfSol, dado, getTempo, getTipo, notifica, desaloca);
                            char id[MAX_TAM_ID];
                            snprintf(id, sizeof(id), "Tick-%d", f->qtd_elementos+1);

                            setIDTicket(temp_ticket2, id);

                            f->elementos[f->qtd_elementos] = temp_ticket2;
                            f->qtd_elementos++;
                        }
                        
                      }

/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f){
    if(f != NULL){
        return f->qtd_elementos;
    }
}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status){
    int cont = 0;

    for(int i = 0; i < f->qtd_elementos; i++){
        char temp = getStatusTicket(f->elementos[i]);
        if(temp == status){
            cont++;
        }
    }

    return cont;
}

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i){
    if(f != NULL && f->qtd_elementos > i){
        return f->elementos[i];
    }
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f){
    if(f != NULL){
        for(int i = 0; i < f->qtd_elementos; i++){
            notificaTicket(f->elementos[i]);
        }
    }
}

void buscaTickets(Fila *f, char *cpf){
    printf("----- BUSCAR TICKETS -----\n");
    for(int i = 0; i < f->qtd_elementos; i++){
        if(strcmp(cpf, getCPFSolicitanteTicket(f->elementos[i])) == 0){
            notificaTicket(f->elementos[i]);
        }
    }
    printf("-------------------------------\n\n");

}