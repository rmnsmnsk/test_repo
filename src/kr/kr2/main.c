#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    Node* list = list_new();
    int value;
    
    printf("Введите числа через пробел (любой не-числовой символ для завершения):\n");
    
    while (scanf("%d", &value) == 1) {
        list = list_append(list, value);
    }
    
    printf("Список: ");
    list_print(list);
    
    if (is_symmetric(list)) {
        printf("Список симметричен\n");
    } else {
        printf("Список не симметричен\n");
    }
    
    list_delete(&list);
    
    return 0;
}