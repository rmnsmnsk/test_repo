#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* list_new(void);
Node* list_append(Node* head, int value);
Node* list_reverse(Node* head);
void list_delete(Node** head);
void list_print(Node* head);
int is_symmetric(Node* head);  
Node* copy_list(Node* head);  
  
#endif