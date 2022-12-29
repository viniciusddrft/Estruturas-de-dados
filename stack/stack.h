#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct prato{
    char cor;
    struct prato *prox;
};

typedef struct prato Prato;

void add(char cor);
void imprime();
void removeStack();

#endif
