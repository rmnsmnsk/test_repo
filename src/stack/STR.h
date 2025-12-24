#pragma once

typedef struct Elem {
    char data;
    struct Elem* next;
} Elem;

Elem* stack_new(void);
Elem* push(Elem* top, char data);
char pop(Elem** top);
char peek(Elem* top);
void stack_delete(Elem** top);
void print_top(Elem* top);
void delete_top(Elem** top);