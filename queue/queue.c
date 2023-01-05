#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Person *queue;

void add(int password){
    Person *p = (Person *)malloc(sizeof(Person));
    p->password = password;
    p->next = NULL;

    if (queue == NULL){
        queue = p;
    }
    else{
        Person *queueAssistant = queue;
        while (queueAssistant->next != NULL){
            queueAssistant = queueAssistant->next;
        }
        queueAssistant->next = p;
    }
}

void privateShow(Person *queue){
    if (queue != NULL){
        printf("\nsenha da Person: %d\n", queue->password);
        privateShow(queue->next);
    }
}

void show(){
    Person *queueAssistant = queue;
    privateShow(queueAssistant);
}

void removeQueue(){
    if (queue != NULL){
        queue = queue->next;
    }
}