#ifndef STACK_H
#define STACK_H

typedef struct obj{
    int data;
    struct obj* next;
}Elem;

Elem* new(void);
Elem* push(Elem* top , char data);
char pop(Elem** top);
void peek(Elem* top);
void delete(Elem** top);

#endif
