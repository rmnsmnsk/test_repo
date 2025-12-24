#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

int test_empty_list() {
    printf("Тест 1: Создание пустого списка\n");
    arr* list = new();
    if (list == NULL) {
        printf("пройдено\n");
        return 1;
    } else {
        printf("не пройдено\n");
        return 0;
    }
}

int test_add_one_element() {
    printf("Тест 2: Добавление одного элемента\n");
    arr* list = new();
    list = insert(list, 5);
    if (list != NULL && list->data == 5 && list->next == NULL) {
        printf("пройдено\n");
        delete(&list);
        return 1;
    } else {
        printf("не пройдено\n");
        delete(&list);
        return 0;
    }
}

int test_sorted_insert() {
    printf("Тест 3: Сортировка при вставке\n");
    arr* list = new();
    list = insert(list, 5);
    list = insert(list, 3);
    list = insert(list, 7);
    list = insert(list, 1);
    
    int result = (get(list, 0) == 1 && get(list, 1) == 3 && 
                  get(list, 2) == 5 && get(list, 3) == 7);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_negative_numbers() {
    printf("Тест 4: Отрицательные числа\n");
    arr* list = new();
    list = insert(list, -5);
    list = insert(list, 0);
    list = insert(list, -10);
    
    int result = (get(list, 0) == -10 && get(list, 1) == -5 && get(list, 2) == 0);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_duplicates() {
    printf("Тест 5: Дубликаты\n");
    arr* list = new();
    list = insert(list, 5);
    list = insert(list, 5);
    list = insert(list, 5);
    
    int result = (get(list, 0) == 5 && get(list, 1) == 5 && get(list, 2) == 5);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_remove_from_beginning() {
    printf("Тест 6: Удаление из начала\n");
    arr* list = new();
    list = insert(list, 5);
    list = insert(list, 3);
    list = insert(list, 7);
    list = insert(list, 1);
    
    list = removeElem(list, 0);
    int result = (get(list, 0) == 3 && get(list, 1) == 5 && get(list, 2) == 7);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_remove_from_middle() {
    printf("Тест 7: Удаление из середины\n");
    arr* list = new();
    list = insert(list, 5);
    list = insert(list, 3);
    list = insert(list, 7);
    list = insert(list, 1);
    
    list = removeElem(list, 1);
    int result = (get(list, 0) == 1 && get(list, 1) == 5 && get(list, 2) == 7);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_remove_from_end() {
    printf("Тест 8: Удаление из конца\n");
    arr* list = new();
    list = insert(list, 5);
    list = insert(list, 3);
    
    list = removeElem(list, 1);
    int result = (get(list, 0) == 3 && list->next == NULL);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_remove_from_empty() {
    printf("Тест 9: Удаление из пустого списка\n");
    arr* list = new();
    list = removeElem(list, 0);
    int result = (list == NULL);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_negative_index() {
    printf("Тест 10: Отрицательный индекс\n");
    arr* list = new();
    list = insert(list, 5);
    
    int result = (get(list, -1) == -1);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }

    delete(&list);
    return result;
}

int test_out_of_range_index() {
    printf("Тест 11: Индекс вне диапазона\n");
    arr* list = new();
    list = insert(list, 5);

    int result = (get(list, 5) == -1);

    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    delete(&list);
    return result;
}

int test_clear_list() {
    printf("Тест 12: Очистка списка\n");
    arr* list = new();
    list = insert(list, 5);
    list = insert(list, 3);
    
    delete(&list);
    int result = (list == NULL);
    
    if (result) {
        printf("пройдено\n");
    } else {
        printf("не пройдено\n");
    }
    
    return result;
}

void run_tests() {
    printf("Тесты\n");

    int all_passed = 1;

    if (!test_empty_list()) all_passed = 0;
    if (!test_add_one_element()) all_passed = 0;
    if (!test_sorted_insert()) all_passed = 0;
    if (!test_negative_numbers()) all_passed = 0;
    if (!test_duplicates()) all_passed = 0;
    if (!test_remove_from_beginning()) all_passed = 0;
    if (!test_remove_from_middle()) all_passed = 0;
    if (!test_remove_from_end()) all_passed = 0;
    if (!test_remove_from_empty()) all_passed = 0;
    if (!test_negative_index()) all_passed = 0;
    if (!test_out_of_range_index()) all_passed = 0;
    if (!test_clear_list()) all_passed = 0;

    if (all_passed) {
        printf("успешно\n");
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