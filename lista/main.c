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

void addFirst(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
}

void addLast(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;
    p->prox = NULL;
    if (listaPontos == NULL)
    {
        listaPontos = p;
    }
    else
    {
        Ponto *auxLista = listaPontos;
        while (auxLista->prox != NULL)
        {
            auxLista = auxLista->prox;
        }
        auxLista->prox = p;
    }
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

int length(Ponto *p)
{
    return privateLength(p, 0);
}

void addIndex(float x, float y, int index)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;

    if (index <= length(listaPontos))
    {
        if (index == 0)
        {
            addFirst(x, y);
        }
        else
        {
            Ponto *auxLista = listaPontos;
            for (int i = 0; i != index - 1; i++)
            {
                auxLista = auxLista->prox;
            }
            p->prox = auxLista->prox;
            auxLista->prox = p;
        }
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
    addFirst(2, 2);
    addFirst(5, 5);
    addFirst(8, 8);
    addLast(11, 11);
    addIndex(13, 13, 2);

    Ponto *auxLista = listaPontos;
    imprime(auxLista);

    printf("\nNumero total te items -> %d \n", length(auxLista));

    return 0;
}