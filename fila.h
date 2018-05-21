
typedef struct{
    int identificacao;
    int tempo_chegada;
    int tempo_atend;
}Cliente;

typedef struct no{
    Cliente c;
    struct no *prox;
}tno;

typedef struct{
    tno *inicio;
    tno *final;
}tfila;

void criar_fila(tfila *f);

int fila_vazia(tfila f);

int tamamho(tfila f);

int inserirClienteNaFila(tfila *f, Cliente c);

int removerClienteDaFila(tfila *f, Cliente *c);

void exibirFila(tfila f);
