#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Pessoa *fila;

void add(int senha)
{
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = NULL;

    if (fila == NULL)
    {
        fila = p;
    }
    else
    {
        Pessoa *filaAux = fila;
        while (filaAux->prox != NULL)
        {
            filaAux = filaAux->prox;
        }
        filaAux->prox = p;
    }
}

void privateImprime(Pessoa *fila)
{
    if (fila != NULL)
    {
        printf("\nSenha da Pessoa: %d\n", fila->senha);
        privateImprime(fila->prox);
    }
}

void imprime()
{
    Pessoa *filaAux = fila;
    privateImprime(filaAux);
}

void removeFila()
{
    if (fila != NULL)
    {
        fila = fila->prox;
    }
}