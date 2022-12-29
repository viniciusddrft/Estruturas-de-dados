#include <stdio.h>
#include "list.h"

int main(){
    addFirst(2, 2);
    addFirst(5, 5);
    addFirst(8, 8);
    addLast(11, 11);
    addIndex(13, 13, 1);
    removeIndex(0);
    removeIndex(3);
    imprime();
    printf("\nNumero total te items -> %d \n", length());

    return 0;
}