#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

ListNode* list_new() {
    return NULL;
}

ListNode* list_insert(ListNode* head, int value) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        printf("Ошибка выделения памяти\n");
        return head;
    }
    new_node->data = value;

    if (head == NULL || value < head->data) {
        new_node->next = head;
        return new_node;
    }
    
    ListNode* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return head;
}

int list_get(ListNode* head, int index) {
    if (index < 0) {
        printf("Индекс не может быть отрицательным\n");
        return -1;
    }
    if (head == NULL) {
        printf("Список пуст\n");
        return -1;
    }

    ListNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
        if (current == NULL) {
            printf("Вне диапазона\n");
            return -1;
        }
    }
    return current->data;
}

ListNode* list_remove(ListNode* head, int index) {
    if (index < 0) {
        printf("Индекс не может быть отрицательным\n");
        return head;
    }

    if (head == NULL) {
        printf("Список пуст\n");
        return head;
    }

    if (index == 0) {
        ListNode* new_head = head->next;
        free(head);
        return new_head;
    }

    ListNode* current = head;
    for (int i = 0; i < index - 1 && current != NULL; ++i) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Индекс вне диапазона\n");
        return head;
    }
    
    ListNode* elem = current->next;
    current->next = current->next->next;
    free(elem);
    return head;
}

void list_delete(ListNode** head) {
    if (*head == NULL) {
        printf("Список уже пуст\n");
        return;
    }

    while ((*head) != NULL) {
        ListNode* back = (*head)->next;
        free(*head);
        (*head) = back;
    }
}

void list_print(ListNode* head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    ListNode* list = list_new();
    int choice, value, index;

    printf("Программа для работы с сортированным списком\n");
    
    while (1) {
        printf("\nДоступные операции:\n");
        printf("0 - выйти\n");
        printf("1 - добавить значение в сортированный список\n");
        printf("2 - удалить значение из списка\n");
        printf("3 - распечатать список\n");

        printf("Выберите операцию (0-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Выход из программы\n");
                list_delete(&list);
                return 0;
                
            case 1:
                printf("Введите значение для добавления: ");
                scanf("%d", &value);
                list = list_insert(list, value);
                break;
                
            case 2:
                printf("Введите индекс для удаления: ");
                scanf("%d", &index);
                list = list_remove(list, index);
                break;
        
            case 3:
                printf("Содержимое списка: ");
                list_print(list);
                break;
        }
    }
    
    return 0;
}
