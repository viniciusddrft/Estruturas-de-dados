#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    float z;
};

typedef struct ponto Ponto;

int main()
{
    // alocaçao de memoria dinamica
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = 1;
    p->y = 49;
    p->z = 20;

    printf("\nPonto = (%2f,%2f,%2f)", p->x, p->y, p->z);

    return 0;
}