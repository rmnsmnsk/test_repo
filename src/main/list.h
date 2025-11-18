#pragma once

typedef struct arr {
    int data;
    struct arr* next;
} arr;

arr* new();
arr* insert(arr* head, int value);
int get(arr *head, int index);
arr* removeElem(arr* head, int index);
void delete(arr** head);
void printList(arr *head);
