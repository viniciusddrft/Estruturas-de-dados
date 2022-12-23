#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos;

void add(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
}

int length()
{
    Ponto *auxLista = listaPontos;
    int count = 0;

    while (auxLista != NULL)
    {
        auxLista = auxLista->prox;
        count++;
    }
    return count;
}

void imprime()
{
    Ponto *auxLista = listaPontos;

    while (auxLista != NULL)
    {
        printf("\nPonto -> (%2f, %2f)", auxLista->x, auxLista->y);
        auxLista = auxLista->prox;
    }
}

int main()
{
    add(2, 2);
    add(5, 5);
    add(8, 8);

    imprime();

    printf("\nNumero total te items -> %d \n", length());

    return 0;
}