#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Point *pointList;

void addFirst(float x, float y){
    Point *p = (Point *)malloc(sizeof(Point));

    p->x = x;
    p->y = y;
    p->next = pointList;
    pointList = p;
}

void addLast(float x, float y){
    Point *p = (Point *)malloc(sizeof(Point));

    p->x = x;
    p->y = y;
    p->next = NULL;
    if (pointList == NULL){
        pointList = p;
    }
    else{
        Point *listAssistant = pointList;
        while (listAssistant->next != NULL){
            listAssistant = listAssistant->next;
        }
        listAssistant->next = p;
    }
}

int privateLength(Point *p, unsigned int count){
    if (p != NULL){
        privateLength(p->next, ++count);
    }
    else{
        return count;
    }
}

int length(){
    Point *listAssistant = pointList;
    return privateLength(listAssistant, 0);
}

void addIndex(float x, float y, int index){
    Point *p = (Point *)malloc(sizeof(Point));

    p->x = x;
    p->y = y;

    if (index <= length(pointList)){
        if (index == 0){
            addFirst(x, y);
        }
        else{
            Point *listAssistant = pointList;
            for (int i = 0; i != index - 1; i++){
                listAssistant = listAssistant->next;
            }
            p->next = listAssistant->next;
            listAssistant->next = p;
        }
    }
}

void privateShow(Point *p){
    if (p != NULL){
        printf("\nPoint -> (%2f, %2f)", p->x, p->y);
        privateShow(p->next);
    }
}

void show(){
    Point *listAssistant = pointList;
    privateShow(listAssistant);
}

void removeIndex(unsigned int index){
    if (index < length(pointList) && length(pointList) != 0){
        if (index == 0){
            pointList = pointList->next;
        }
        else{
            Point *listAssistant = pointList;
            for (int i = 0; i != index - 1; i++){
                listAssistant = listAssistant->next;
            }
            listAssistant->next = listAssistant->next->next;
        }
    }
}