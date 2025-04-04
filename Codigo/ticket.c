#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket{
    void *dado;
    func_ptr_notifica notifica;
    func_ptr_desaloca desaloca;
    func_ptr_tempoEstimado tempo_estimado;
    func_ptr_tipo tipo;
    char cpf[MAX_TAM_CPF];
    char id[MAX_TAM_ID];
    char status;
};

/**
 * @brief Aloca uma estrutura Ticket na memória e inicializa os parâmetro necessários
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido
 * @param notifica  Função de callback de notificação  (impressãode um ticket
 * @param desaloca  Função de callback que irá desalocar  um ticket da memória
 * @return  Uma estrutura Ticket inicializada.
 */
Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                   func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
                        Ticket *t = (Ticket*) malloc(sizeof(Ticket));

                        if(t == NULL){
                            printf("Erro ao criar ticket\n");
                            exit(1);
                        }

                        t->dado = dado;
                        strcpy(t->cpf, cpfSol);
                        t->tempo_estimado = getTempo;
                        t->desaloca = desaloca;
                        t->notifica = notifica;
                        t->tipo = getTipo;
                        t->status = 'A';

                        return t;
                   }

/**
 * @brief Atribui um ID a um ticket
 * @param d Ticket inicializado
 * @param id ID a ser atribuido ao ticket
 */
void setIDTicket(Ticket *d, char *id){
    if(d != NULL){
        strcpy(d->id, id);
    }
}

/**
 * @brief Finaliza um ticket
 * @param t Ticket inicializado
 */
void finalizaTicket(Ticket *t){
    t->status = 'F';
}

/**
 * @brief Recupera o CPF de quem solicitou a abertura do ticket
 * @param t Ticket inicializado
 * @return CPF de quem solicitou a abertura do ticket
 */
char *getCPFSolicitanteTicket(Ticket *t){
    if(t != NULL){
        return t->cpf;
    }
}

/**
 * @brief Recupera o tempo estimado para resolver um ticket
 * @param t Ticket inicializado
 * @return tempo estimado para resolver um ticket
 */
int getTempoEstimadoTicket(Ticket *t){
    if(t != NULL){
        return t->tempo_estimado(t->dado);
    }
}

/**
 * @brief Recupera o tipo de um ticket
 * @param t Ticket inicializado
 * @return tipo do Ticket
 */
char getTipoTicket(Ticket *t){
    if(t != NULL){
        return t->tipo();
    }
}

/**
 * @brief Recupera o status de um ticket
 * @param t Ticket inicializado
 * @return status do Ticket
 */
char getStatusTicket(Ticket *t){
    return t->status;
}

/**
 * @brief  Desaloca um ticket da memória
 * @param doc estrutura do tipo Ticket que deve ser liberada da memória
 */
void desalocaTicket(Ticket *doc){
    if(doc != NULL){
        doc->desaloca(doc->dado);
        free(doc);
    }
}

/**
 * @brief  Notifica (imprime) um ticket
 * @param doc Ticket a ser notificado
 */
void notificaTicket(Ticket *doc){
    if(doc != NULL){
        char status = getStatusTicket(doc);
        printf("---------TICKET-----------\n");
        printf("- ID: %s\n", doc->id);
        printf("- Usuario solicitante: %s\n", doc->cpf);
        doc->notifica(doc->dado);
        if(status == 'A'){
            printf("- Status: Aberto\n");    
        }
        else{
            printf("- Status: Finalizado\n");
        }
        printf("-------------------------\n\n");
    }
}
