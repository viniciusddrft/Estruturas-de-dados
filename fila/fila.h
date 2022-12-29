#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct pessoa{
    int senha;
    struct pessoa *prox;
};

typedef struct pessoa Pessoa;

void removeFila();
void imprime();
void add(int senha);

#endif
