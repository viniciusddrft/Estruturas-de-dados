#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

int privateLength(Ponto *p, unsigned int count);

Ponto *listaPontos;

void add(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
}

int length(Ponto *p)
{
    return privateLength(p, 0);
}

int privateLength(Ponto *p, unsigned int count)
{
    if (p != NULL)
    {
        privateLength(p->prox, ++count);
    }
    else
    {
        return count;
    }
}

void imprime(Ponto *p)
{
    if (p != NULL)
    {
        printf("\nPonto -> (%2f, %2f)", p->x, p->y);
        imprime(p->prox);
    }
}

int main()
{
    add(2, 2);
    add(5, 5);
    add(8, 8);

    Ponto *auxLista = listaPontos;
    imprime(auxLista);

    printf("\nNumero total te items -> %d \n", length(auxLista));

    return 0;
}