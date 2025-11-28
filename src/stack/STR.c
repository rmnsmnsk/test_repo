#include "STR.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

Elem* new(void){
    return NULL;
}

Elem* push(Elem* top , char data){

    Elem* pt = malloc(sizeof(Elem));
    pt -> data = data;
    pt -> next = top;
    return pt;

}

char pop(Elem** top){ //т.к нужно взять последний элемент, то top нужно будет перезаписать, а для этого сам top нужно будет изменить

    if (*top == NULL){
        printf("Stack is empty\n");
        return '\0';
    }
    char data = (*top) -> data;
    Elem* now = (*top);
    *top = now -> next;
    free(now);
    return data;

}

void peek(Elem *top){

    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    char symbol = top -> data;
    printf("%c", symbol);
}

void delete(Elem** top){ //аналогично с pop я должен менять не копию, а оригинал

    while (*top != NULL){
        Elem* back = (*top) -> next;
        free(*top);
        *top = back;
    }

}
