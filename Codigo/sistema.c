#include "sistema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sistema{
    BancoTecnicos *bTec;
    BancoUsuario *bUser;
    Fila *fila_tickets;
    bancoEmpresas *bEmpresa;
};

Sistema *criaSistema(){
    Sistema *s = (Sistema*) malloc(sizeof(Sistema));

    s->bTec = criaBancoTecnicos();
    s->bUser = criaBancoUsuario();
    s->fila_tickets = criaFila();
    s->bEmpresa = criaBancoEmpresas();

    return s;
}

void rodaSistema(Sistema *s){
    while(1){
        char op;
        scanf("%c\n", &op);
        if(op == 'F'){
            break;
        }
        else if(op == 'T'){
            Tecnico *tempTec = leTecnico();
            char tempCpf[15];
            strcpy(tempCpf, retornaCpfTecnico(tempTec));
            if(verificaTecnicoJaCadastrado(s->bTec, tempCpf) == 0){
                insereTecnicoBanco(s->bTec, tempTec);
            }
            else{
                desalocaTecnico(tempTec);
            }
        }
        else if(op == 'U'){
            Usuario *tempUser = leUsuario();
            char tempCpf[15];
            strcpy(tempCpf, retornaCpfUsuario(tempUser));
            if(verificaUsuarioJaCadastrado(s->bUser, tempCpf) == 0){
                insereUsuarioBanco(s->bUser, tempUser);
            }
            else{
                desalocaUsuario(tempUser);
            }
        }
        else if(op == 'A'){
            char tempCpf[15];
            scanf("%[^\n]\n", tempCpf);
            if(verificaUsuarioJaCadastrado(s->bUser, tempCpf) == 1){
                char tipoTicket[MAX_TAM_ID];
                scanf("%[^\n]\n", tipoTicket);
                if(strcmp(tipoTicket, "OUTROS") == 0){
                    Outros *tempOutros = leOutros();
                    setTempoEstimadoOutros(tempOutros);
                    insereTicketFila(s->fila_tickets, tempCpf, (void*)tempOutros, getTempoEstimadoOutros, getTipoOutros, notificaOutros, desalocaOutros);
                    atualizaUsuarioBanco(s->bUser, tempCpf);
                }
                else if(strcmp(tipoTicket, "MANUTENCAO") == 0){
                    Manutencao *tempManu = leManutencao();
                    char tempSetorUser[10];
                    strcpy(tempSetorUser, retornaSetorUsuarioBanco(s->bUser, tempCpf));
                    setTempoEstimadoManutencao(tempManu, tempSetorUser);
                    insereTicketFila(s->fila_tickets, tempCpf, (void*)tempManu, getTempoEstimadoManutencao, getTipoManutencao, notificaManutencao, desalocaManutencao);
                    atualizaUsuarioBanco(s->bUser, tempCpf);
                }
                else if(strcmp(tipoTicket, "SOFTWARE") == 0){
                    Software *tempSoftware = lerSoftware();
                    setTempoEstimadoSoftware(tempSoftware);
                    insereTicketFila(s->fila_tickets, tempCpf, (void*)tempSoftware, getTempoEstimadoSoftware, getTipoSoftware, notificaSoftware, desalocaSoftware);
                    atualizaUsuarioBanco(s->bUser, tempCpf);
                }
                else if(strcmp(tipoTicket, "HARDWARE") == 0){
                    Hardware *tempHard = leHardware();
                    setaTempoEstimadoHardware(tempHard);
                    insereTicketFila(s->fila_tickets, tempCpf, (void*)tempHard, getTempoEstimado, getTipoHard, notificaHardware, desalocaHardware);
                    atualizaUsuarioBanco(s->bUser, tempCpf);
                }   
            }
            else{
                char tipoTicket[MAX_TAM_ID];
                scanf("%[^\n]\n", tipoTicket);
                if(strcmp(tipoTicket,"OUTROS") == 0){
                    Outros *tempOutros = leOutros();
                    desalocaOutros((void*)tempOutros);
                }
                else if(strcmp(tipoTicket, "MANUTENCAO") == 0){
                    Manutencao *tempManu = leManutencao();
                    desalocaManutencao((void*)tempManu);
                }
                else if(strcmp(tipoTicket, "SOFTWARE") == 0){
                    Software *tempSoftware = lerSoftware();
                    desalocaSoftware((void*)tempSoftware);
                }
                else if(strcmp(tipoTicket, "HARDWARE") == 0){
                    Hardware *tempHard = leHardware();
                    desalocaHardware((void*) tempHard);
                }
            }
        }
        else if(op == 'E'){
            char acao[35];
            scanf("%[^\n]\n", acao);
            if(strcmp(acao, "NOTIFICA") == 0){
                printf("----- FILA DE TICKETS -----\n");
                notificaFila(s->fila_tickets);
                printf("---------------------------\n\n");
            }
            else if(strcmp(acao, "USUARIOS") == 0){
                imprimeBancoUsuario(s->bUser);
            }
            else if(strcmp(acao, "TECNICOS") == 0){
                imprimeBancoTecnicos(s->bTec);
            }
            else if(strcmp(acao, "RANKING TECNICOS") == 0){
                imprimeRankingTecnicos(s->bTec);
            }
            else if(strcmp(acao, "RANKING USUARIOS") == 0){
                imprimeRankingUsuario(s->bUser);
            }
            else if(strcmp(acao, "RELATORIO") == 0){
                geraRelatorio(s);
            }
            else if(strcmp(acao, "DISTRIBUI") == 0){
                distribuiTickets(s);
            }
            else if(strcmp(acao, "RELATORIO TECNICOS") == 0){
                imprimeRelatorioTecnicos(s->bTec);
            }
            else if(strcmp(acao, "BUSCAR TICKETS") == 0){
                char tempCpf[15];
                scanf("%[^\n]\n", tempCpf);
                buscaTickets(s->fila_tickets, tempCpf);
            }
            else if(strcmp(acao, "EMPRESAS FORNECEDORAS") == 0){
                imprimeBancoEmpresas(s->bEmpresa);
            }
        }
        else if(op == 'P'){
            Empresa *tempEmpresa = leEmpresa();
            char tempCnpj[19];

            strcpy(tempCnpj, retornaCnpj(tempEmpresa));

            if(verificaEmpresaJaCadastrada(s->bEmpresa, tempCnpj) == 0){
                insereEmpresaNoBanco(s->bEmpresa, tempEmpresa);
            }
            else{
                desalocaEmpresa(tempEmpresa);
            }
        }
    }
}

void desalocaSistema(Sistema *s){
    if(s != NULL){
        if(s->fila_tickets != NULL){
            desalocaFila(s->fila_tickets);
        }
        if(s->bTec != NULL){
            desalocaBancoTecnicos(s->bTec);
        }
        if(s->bUser != NULL){
            desalocaBancoUsuario(s->bUser);
        }
        if(s->bEmpresa != NULL){
            desalocaBancoEmpresas(s->bEmpresa);
        }
        free(s);
    }
}

void geraRelatorio(Sistema *s){
    printf("----- RELATORIO GERAL -----\n");
    printf("- Qtd tickets: %d\n", getQtdTicketsNaFila(s->fila_tickets));
    printf("- Qtd tickets (A): %d\n", getQtdTicketsPorStatusNaFila(s->fila_tickets, 'A'));
    printf("- Qtd tickets (F): %d\n", getQtdTicketsPorStatusNaFila(s->fila_tickets, 'F'));
    printf("- Qtd usuarios: %d\n", retornaQtdUsuarios(s->bUser));
    printf("- Md idade usuarios: %d\n", calculaMediaIdadesUsuarios(s->bUser));
    printf("- Qtd tecnicos: %d\n", retornaQtdTecnicos(s->bTec));
    printf("- Md idade tecnicos: %d\n", calculaMediaIdadeTecnicos(s->bTec));
    printf("- Md trabalho tecnicos: %d\n", calculaMediaTrabalhoTecnicos(s->bTec));
    printf("---------------------------\n\n");
}

void distribuiTickets(Sistema *s){
    int qtdTecnicos = retornaQtdTecnicos(s->bTec);

    if(qtdTecnicos > 0){
        int idxTecnicos = 0;
        int qtdTickets = getQtdTicketsNaFila(s->fila_tickets);

        for(int i = 0; i < qtdTickets; i++){
            Ticket *tempTicket = getTicketNaFila(s->fila_tickets, i);
            if(getStatusTicket(tempTicket) == 'A'){
                int distribuido = 0;
                for(int i = 0; i < qtdTecnicos; i++){
                    Tecnico *tempTec = retornaTecnicoPorIdx(s->bTec, idxTecnicos);
                    idxTecnicos = (idxTecnicos+1) % qtdTecnicos;

                    char tipoTicket = getTipoTicket(tempTicket);
                    char *areaTecnico = retornaAreaTecnico(tempTec);
                    int tempoEstimadoTicket = getTempoEstimadoTicket(tempTicket);
                    int tempoDisponivelTec = retornaDisponibilidadeTecnico(tempTec);
                    
                    if(tipoTicket == 'S' && strcmp(areaTecnico, "TI") != 0){
                        continue;
                    }
                    if(tipoTicket != 'S' && strcmp(areaTecnico, "TI") == 0){
                        continue;
                    }
                    if(tipoTicket == 'H' && strcmp(areaTecnico, "ENGENHEIRO") != 0){
                        continue;
                    }
                    if(tipoTicket != 'H' && strcmp(areaTecnico, "ENGENHEIRO") == 0){
                        continue;
                    }

                    if(tempoDisponivelTec >= tempoEstimadoTicket){
                        atualizaTecnico(tempTec, tempoEstimadoTicket);
                        finalizaTicket(tempTicket);
                        distribuido = 1;
                        break;
                    }
                }
            }
        }
    }
}

