#include "STR.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

Elem* stack_new(void) {
    return NULL;
}

Elem* push(Elem* top, char data) {
    Elem* pt = malloc(sizeof(Elem));
    if (pt == NULL) {
        return top;
    }
    pt->data = data;
    pt->next = top;
    return pt;
}

char pop(Elem** top) {
    if (*top == NULL) {
        return '\0';
    }
    char data = (*top)->data;
    Elem* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

char peek(Elem* top) {
    if (top == NULL) {
        return '\0';
    }
    return top->data;
}

void stack_delete(Elem** top) {
    while (*top != NULL) {
        Elem* next = (*top)->next;
        free(*top);
        *top = next;
    }
}

void print_top(Elem* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%c", top->data);
}

void delete_top(Elem** top) {
    if (*top == NULL) {
        return;
    }
    Elem* temp = *top;
    *top = (*top)->next;
    free(temp);
}