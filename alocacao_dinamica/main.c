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
    // ela é alocada em tempo de execução
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = 1;
    p->y = 49;
    p->z = 20;

    printf("\nPonto = (%2f,%2f,%2f)\n", p->x, p->y, p->z);

    // libera memoria alocada
    free(p);

    return 0;
}