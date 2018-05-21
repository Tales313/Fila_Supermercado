#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

void criar_fila(tfila *f)
{
    f->inicio = f->final = NULL;
}

int fila_vazia(tfila f)
{
    return ((f.inicio == NULL) && (f.final == NULL));
    ///Retorna 1 se a fila estiver vazia, e retorna 0 se não estiver vazia.
}

int tamanho(tfila f) ///Retorna um inteiro do tamanho da fila.
{
    int c = 0;
    while (f.inicio!=NULL){
        f.inicio = f.inicio->prox;
        c++;
    }
    return c;
}

int inserirClienteNaFila(tfila *f, Cliente c) ///Insere o Cliente c no FINAL da fila.
                                              ///Retorna 1 se foi possivel inserir e 0 se não foi.
{
    tno *aux;
    aux = (tno*)malloc(sizeof(tno));
    if(aux==NULL)
        return 0;
    aux->c = c;
    aux->prox = NULL;
    if(fila_vazia(*f))
        f->inicio = aux;
    else
        f->final->prox = aux;
    f->final = aux;
    return 1;
}

int removerClienteDaFila(tfila *f, Cliente *c) ///Remove o cliente do INICIO da fila e joga no 2º parametro.
                                               ///Retorna 1 se foi possivel remover e 0 se não foi.
{
    if(fila_vazia(*f))
        return 0;
    tno *aux;
    if(f->inicio == f->final)
        f->final = NULL;

    aux = f->inicio;
    *c = f->inicio->c;
    f->inicio = aux->prox;
    free(aux);
    return 1;
}

void exibirFila(tfila f)
{
    printf("\n\nFila Atual =>");
    if(fila_vazia(f))
        printf(" vazia");
    while (f.inicio !=NULL){
        printf("%d (%d, %d)) ",f.inicio->c.identificacao, f.inicio->c.tempo_chegada, f.inicio->c.tempo_atend);
        f.inicio = f.inicio->prox;
    }
}
