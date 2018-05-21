#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define MINUTOS 720
#define MAX_ATEND 5
#define MAX_CHEGADA 5

/* Programa desenvolvido por:
        Tales Medeiros
        Marlon Fernando
        John Oliver
*/

void definirProxCliente(Cliente *c, int chegada) ///int chegada vai receber o tempo_simulacao do main
{
    c->identificacao++;
    c->tempo_chegada = chegada + (rand()%MAX_CHEGADA);
    c->tempo_atend = 1 + (rand()%MAX_ATEND); ///Variaveis definidas em fila.h
}

int main()
{
    int tempo_simulacao = 1;
    int caixa_livre = 1; ///1 para caixa livre e 0 para caixa ocupado.
    int tempo_max_espera = 0; ///Pra mostrar no final do programa.
    int prox_chegada = 1; ///Pra calcular quando o proximo cliente vai chegar.
    int tempo_atendi = 0; ///Pra calcular o tempo de atendimento do cliente atual.
    int tamanho_max_fila = 0; ///Pra mostrar no final do programa.
    Cliente cliente; ///Variavel cliente.
    Cliente cli_em_atendi; ///Variavel cliente em atendimento.
    tfila fila_caixa; ///Estrutura com os ponteiros para o final e o inicio da fila.
    int tempo_espera_do_cliente;/// é o tempo de espera do próximo cliente a ser atendido
    int tempo_espera = 0;///tempo de espera do cliente na fila


    //////////////////////Fim das declarações de váriavel/////////////////////////

    criar_fila(&fila_caixa); ///Criando uma fila vazia.
    srand(time(NULL)); ///Definindo a semente para gerar os numeros aleatorios.

    cliente.identificacao = 0;
    definirProxCliente(&cliente, tempo_simulacao); ///Definindo os dados do primeiro cliente.

    printf("Programa de Simulacao de Caixa de Supermercado\n\n");
    printf("Tempo total da simulacao: %i minutos\n", MINUTOS);
    printf("Tempo maximo de atendimento do cliente: %i\n", MAX_ATEND);
    printf("Tempo maximo de chegada do cliente: %i\n\n", MAX_CHEGADA);
    printf("Inicio da Simulacao\n\n");
    printf("Definido o cliente %i(cheg=%i, atend=%i)\n\n",
        cliente.identificacao, cliente.tempo_chegada, cliente.tempo_atend);
    printf("============================================================\n\n");

    while(tempo_simulacao <= MINUTOS){ ///MINUTOS é a constante declarada em fila.h
        printf("Tempo da simulacao => %i\n\n", tempo_simulacao);
        if(prox_chegada == cliente.tempo_chegada){ ///Se o cliente chegar...
            if(inserirClienteNaFila(&fila_caixa, cliente)){ ///Insere no final da fila.
                printf("O Cliente %i entrou na fila\n", cliente.identificacao);
                definirProxCliente(&cliente, tempo_simulacao+1);
                printf("Definido o cliente %i(cheg=%i, atend=%i)\n",
                    cliente.identificacao, cliente.tempo_chegada, cliente.tempo_atend);
                prox_chegada += 1;
            }
        }else
            prox_chegada++; ///Se o cliente ainda nao chegou.

        //if(tamanho(fila_caixa) > tamanho_max_fila)   deixa esse teste aqui se for considerar os clientes que
            //tamanho_max_fila = tamanho(fila_caixa);  entram na fila e ja saem no mesmo tempo de simulacao.

        if(caixa_livre){ ///Se o caixa estiver livre...
            printf("O caixa esta Livre\n");
            if(removerClienteDaFila(&fila_caixa, &cli_em_atendi)){ ///Se for possivel remover o cliente do inicio...
                tempo_espera = tempo_simulacao - cli_em_atendi.tempo_chegada;
                if(tempo_espera > tempo_max_espera)
                    tempo_max_espera = tempo_espera;
                caixa_livre = 0; ///O caixa fica ocupado.
                printf("O cliente %d saiu da fila e chega ao caixa\n", cli_em_atendi.identificacao);
                printf("a espera do cliente %d foi de  %d minutos\n", cli_em_atendi.identificacao ,tempo_espera);
                printf("O Cliente %i comecou a ser atendido\n", cli_em_atendi.identificacao);
                tempo_espera_do_cliente = cli_em_atendi.tempo_atend - tempo_atendi;
                printf("Falta(m) %i minuto(s) para concluir o atendimento atual\n\n", tempo_espera_do_cliente);
                tempo_atendi++; ///Atende o cliente.
            }
        }else{ ///Se o caixa estiver ocupado...
            if(tempo_espera_do_cliente == 0){
                tempo_espera_do_cliente = cli_em_atendi.tempo_atend - tempo_atendi;
                printf("O cliente %d saiu da fila e chega ao caixa\n", cli_em_atendi.identificacao);
                printf("Falta(m) %i minuto(s) para concluir o atendimento atual\n", tempo_espera_do_cliente);
                tempo_atendi++; ///Atende o cliente
            }else{
                tempo_espera_do_cliente = cli_em_atendi.tempo_atend - tempo_atendi;
                printf("Falta(m) %i minuto(s) para concluir o atendimento atual\n", tempo_espera_do_cliente);
                tempo_atendi++;
            }
        }

        if(tamanho(fila_caixa) > tamanho_max_fila)    // deixa esse teste aqui se NAO for considerar os clientes que
            tamanho_max_fila = tamanho(fila_caixa);   // entram na fila e ja saem no mesmo tempo de simulacao.

        exibirFila(fila_caixa);
        printf("\nCaixa atual => ");
        if(caixa_livre)
            printf("vazia");
        else
            printf("%i (%i, %i)", cli_em_atendi.identificacao, cli_em_atendi.tempo_chegada, cli_em_atendi.tempo_atend);

        printf("\nProximo cliente => ");
        printf("%d (%d, %d) ",cliente.identificacao, cliente.tempo_chegada, cliente.tempo_atend);

        if(tempo_atendi == cli_em_atendi.tempo_atend){
            caixa_livre = 1; ///Caixa fica livre.
            tempo_atendi = 0;
        }


        printf("\n============================================================\n\n");
        scanf("%*c");
        tempo_simulacao++;
    } ///Fim do while

    printf("Quantidade maxima de clientes na fila => %i\n\n", tamanho_max_fila);
    printf("Tempo maximo de espera na fila foi de => %i minutos\n", tempo_max_espera);
    return 0;
}
