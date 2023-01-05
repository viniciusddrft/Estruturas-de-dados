#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct point{
    float x;
    float y;
    struct point *next;
};

typedef struct point Point;

void addFirst(float x, float y);
void addLast(float x, float y);
int length();
void addIndex(float x, float y, int index);
void show();
void removeIndex(unsigned int index);

#endif
