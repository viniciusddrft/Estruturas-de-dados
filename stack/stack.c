#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Dish *stack;

void add(char color){
    Dish *d = (Dish *)malloc(sizeof(Dish));
    d->color = color;
    d->next = stack;
    stack = d;
}

void privateShow(Dish *d){
    if (d != NULL){
        printf("\n color -> %c\n", d->color);
        privateShow(d->next);
    }
}

void show(){
    Dish *stackAux = stack;
    privateShow(stackAux);
}

void removeStack(){
    if(stack!= NULL){
        stack = stack->next;
    }
}
