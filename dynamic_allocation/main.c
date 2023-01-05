#include <stdio.h>
#include <stdlib.h>

struct point{
    float x;
    float y;
    float z;
};

typedef struct point Point;

int main(){
    // alocaçao de memoria dinamica
    // ela é alocada em tempo de execução
    Point *p = (Point *)malloc(sizeof(Point));

    p->x = 1;
    p->y = 49;
    p->z = 20;

    printf("\nPoint = (%2f,%2f,%2f)\n", p->x, p->y, p->z);

    // libera memoria alocada
    free(p);

    return 0;
}