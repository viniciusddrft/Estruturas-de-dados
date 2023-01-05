#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct dish{
    char color;
    struct dish *next;
};

typedef struct dish Dish;

void add(char cor);
void show();
void removeStack();

#endif
