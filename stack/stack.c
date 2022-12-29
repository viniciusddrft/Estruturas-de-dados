#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Prato *pilha;

void add(char cor){
    Prato *p = (Prato *)malloc(sizeof(Prato));
    p->cor = cor;
    p->prox = pilha;
    pilha = p;
}

void privateImprime(Prato *p){
    if (p != NULL){
        printf("\n cor -> %c\n", p->cor);
        privateImprime(p->prox);
    }
}

void imprime(Prato *p){
    Prato *pilhaAux = pilha;
    privateImprime(pilhaAux);
}

void removeStack(){
    if(pilha!= NULL){
        pilha = pilha->prox;
    }
}
