#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

struct person{
    int password;
    struct person *next;
};

typedef struct person Person;

void removeQueue();
void show();
void add(int senha);

#endif
