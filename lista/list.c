#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Ponto *listaPontos;

void addFirst(float x, float y){
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;
    p->prox = listaPontos;
    listaPontos = p;
}

void addLast(float x, float y){
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;
    p->prox = NULL;
    if (listaPontos == NULL){
        listaPontos = p;
    }
    else{
        Ponto *auxLista = listaPontos;
        while (auxLista->prox != NULL){
            auxLista = auxLista->prox;
        }
        auxLista->prox = p;
    }
}

int privateLength(Ponto *p, unsigned int count){
    if (p != NULL){
        privateLength(p->prox, ++count);
    }
    else{
        return count;
    }
}

int length(){
    Ponto *auxLista = listaPontos;
    return privateLength(auxLista, 0);
}

void addIndex(float x, float y, int index){
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    p->x = x;
    p->y = y;

    if (index <= length(listaPontos)){
        if (index == 0){
            addFirst(x, y);
        }
        else{
            Ponto *auxLista = listaPontos;
            for (int i = 0; i != index - 1; i++){
                auxLista = auxLista->prox;
            }
            p->prox = auxLista->prox;
            auxLista->prox = p;
        }
    }
}

void privateImprime(Ponto *p){
    if (p != NULL){
        printf("\nPonto -> (%2f, %2f)", p->x, p->y);
        privateImprime(p->prox);
    }
}

void imprime(){
    Ponto *auxLista = listaPontos;
    privateImprime(auxLista);
}

void removeIndex(unsigned int index){
    if (index < length(listaPontos) && length(listaPontos) != 0){
        if (index == 0){
            listaPontos = listaPontos->prox;
        }
        else{
            Ponto *auxLista = listaPontos;
            for (int i = 0; i != index - 1; i++){
                auxLista = auxLista->prox;
            }
            auxLista->prox = auxLista->prox->prox;
        }
    }
}