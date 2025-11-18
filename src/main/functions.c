#include <stdio.h>
#include <stdlib.h>
#include "list.h"

arr* new() {
    return NULL;
}

arr* insert(arr* head, int value) {
    arr* new_node = (arr*)malloc(sizeof(arr));
    new_node->data = value;

    if (head == NULL || value < head->data) {
        new_node->next = head;
        return new_node;
    }

    arr* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

int get(arr *head, int index) {
    if (index < 0) {
        printf("Индекс не может быть отрицательным\n");
        return -1;
    }
    if (head == NULL) {
        printf("Список пуст\n");
        return -1;
    }

    arr* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
        if (current == NULL) {
            printf("Вне диапазона\n");
            return -1;
        }
    }
    return current->data;
}

arr* removeElem(arr* head, int index) {
    if (index < 0) {
        printf("Индекс не может быть отрицательным\n");
        return head;
    }

    if (head == NULL) {
        printf("Список пуст\n");
        return head;
    }

    if (index == 0) {
        arr *head1 = head->next;
        free(head);
        return head1;
    }

    arr* current = head;
    for (int i = 0; i < index - 1 && current != NULL; ++i) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Индекс вне диапазона\n");
        return head;
    }
    arr* elem = current->next;
    current->next = current->next->next;
    free(elem);
    return head;
}

void delete(arr** head) {
    if (*head == NULL) {
        printf("Список уже пуст\n");
        return;
    }

    while ((*head) != NULL) {
        arr* back = (*head)->next;
        free(*head);
        (*head) = back;
    }
}

void printList(arr *head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    arr* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}