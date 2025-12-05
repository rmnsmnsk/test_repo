#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//список писал на основе того, какие функции пригодятся в задаче, не писал условный insert, get prepend 

Node* list_new(void) {
    return NULL;
}

Node* list_append(Node* head, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    
    if (head == NULL) {
        return new_node;
    }
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

Node* list_reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
} 

void list_delete(Node** head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void list_print(Node* head) { //использую для себя
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* copy_list(Node* head) {
    Node* new_list = NULL;
    Node* tail = NULL;
    
    while (head != NULL) {
        Node* new_node = malloc(sizeof(Node));
        new_node->data = head->data;
        new_node->next = NULL;
        
        if (new_list == NULL) {
            new_list = new_node;
        } else {
            tail->next = new_node;
        }
        tail = new_node;
        
        head = head->next;
    }
    
    return new_list;
}

int is_symmetric(Node* head) {
    Node* copy = copy_list(head);

    copy = list_reverse(copy);
    
    Node* p1 = head;
    Node* p2 = copy;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->data != p2->data) {
            list_delete(&copy);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    list_delete(&copy);
    return (p1 == NULL && p2 == NULL);
}