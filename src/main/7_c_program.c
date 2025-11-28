#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

void run_tests() {
    printf("Тесты\n");
    int passed = 0;
    int total = 0;
    
    printf("Тест %d: Создание пустого списка\n", ++total);
    arr* list = new();
    if (list == NULL) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Добавление одного элемента\n", ++total);
    list = insert(list, 5);
    if (list != NULL && list->data == 5 && list->next == NULL) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Сортировка при вставке\n", ++total);
    list = insert(list, 3);
    list = insert(list, 7);
    list = insert(list, 1);
    if (get(list, 0) == 1 && get(list, 1) == 3 && 
        get(list, 2) == 5 && get(list, 3) == 7) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Отрицательные числа\n", ++total);
    arr* list2 = new();
    list2 = insert(list2, -5);
    list2 = insert(list2, 0);
    list2 = insert(list2, -10);
    if (get(list2, 0) == -10 && get(list2, 1) == -5 && get(list2, 2) == 0) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    delete(&list2);
    
    printf("Тест %d: Дубликаты\n", ++total);
    arr* list3 = new();
    list3 = insert(list3, 5);
    list3 = insert(list3, 5);
    list3 = insert(list3, 5);
    if (get(list3, 0) == 5 && get(list3, 1) == 5 && get(list3, 2) == 5) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    delete(&list3);
    
    printf("Тест %d: Удаление из начала\n", ++total);
    list = removeElem(list, 0);
    if (get(list, 0) == 3 && get(list, 1) == 5 && get(list, 2) == 7) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Удаление из середины\n", ++total);
    list = removeElem(list, 1);
    if (get(list, 0) == 3 && get(list, 1) == 7) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Удаление из конца\n", ++total);
    list = removeElem(list, 1);
    if (get(list, 0) == 3 && list->next == NULL) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Удаление из пустого списка\n", ++total);
    arr* empty_list = new();
    empty_list = removeElem(empty_list, 0);
    if (empty_list == NULL) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Отрицательный индекс\n", ++total);
    if (get(list, -1) == -1) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Индекс вне диапазона\n", ++total);
    if (get(list, 5) == -1) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("Тест %d: Очистка списка\n", ++total);
    delete(&list);
    if (list == NULL) {
        printf("пройдено\n");
        passed++;
    } else {
        printf("не пройдено\n");
    }
    
    printf("пройдено: %d/%d тестов\n", passed, total);
    
    if (passed == total) {
        printf("умпешно\n");
    } else {
        printf("есть ошибки\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        run_tests();
        return 0;
    }

    arr* list = new();
    int choice, value, index;

    printf("Программа для работы с сортированным списком\n");

    while (1) {
        printf("\nДоступные операции:\n");
        printf("0 - выйти\n");
        printf("1 - добавить значение в сортированный список\n");
        printf("2 - удалить значение из списка\n");
        printf("3 - распечатать список\n");
        printf("4 - получить значение по индексу\n");

        printf("Выберите операцию (0-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Выход из программы\n");
                delete(&list);
                return 0;
            case 1:
                printf("Введите значение для добавления: ");
                scanf("%d", &value);
                list = insert(list, value);
                break;
            case 2:
                printf("Введите индекс для удаления: ");
                scanf("%d", &index);
                list = removeElem(list, index);
                break;
            case 3:
                printf("Содержимое списка: ");
                printList(list);
                break;
            case 4:
                printf("Введите индекс для получения: ");
                scanf("%d", &index);
                value = get(list, index);
                if (value != -1) {
                    printf("Значение по индексу %d: %d\n", index, value);
                }
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}