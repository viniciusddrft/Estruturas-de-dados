#include <stdio.h>
#include "list.h"

int main()
{
    addFirst(2, 2);
    addFirst(5, 5);
    addFirst(8, 8);

    show();
    printf("\nNumero total te items -> %d \n", length());

    return 0;
}