#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct ponto{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

void addFirst(float x, float y);
void addLast(float x, float y);
int length();
void addIndex(float x, float y, int index);
void imprime();
void removeIndex(unsigned int index);

#endif
