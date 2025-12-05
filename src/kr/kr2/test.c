#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int passed = 0;

void test1()
{
    Node* list = list_new();
    if (list == NULL) {
        passed++;
        printf("1 ok\n");
    }
}

void test2()
{
    Node* list = list_new();
    list = list_append(list, 1);
    if (list->data == 1 && list->next == NULL) {
        passed++;
        printf("2 ok\n");
    }
    list_delete(&list);
}

void test3()
{
    Node* list = list_new();
    list = list_append(list, 1);
    list = list_append(list, 2);
    list = list_append(list, 3);

    if (list->data == 1 && list->next->data == 2 && list->next->next->data == 3) {
        passed++;
        printf("3 ok\n");
    }
    list_delete(&list);
}

void test4()
{
    Node* list = list_new();
    list = list_append(list, 1);
    list = list_append(list, 2);
    list = list_append(list, 3);

    list = list_reverse(list);

    if (list->data == 3 && list->next->data == 2 && list->next->next->data == 1) {
        passed++;
        printf("4 ok\n");
    }

    list_delete(&list);
}

void test5()
{
    Node* list = list_new();
    list = list_append(list, 10);
    list = list_append(list, 20);
    list = list_append(list, 30);
    list = list_append(list, 20);
    list = list_append(list, 10);

    if (is_symmetric(list)) {
        passed++;
        printf("5 ok\n");
    }

    list_delete(&list);
}

void test6()
{
    Node* list = list_new();
    list = list_append(list, 10);
    list = list_append(list, 20);
    list = list_append(list, 30);
    list = list_append(list, 40);
    list = list_append(list, 20);
    list = list_append(list, 10);

    if (!is_symmetric(list)) {
        passed++;
        printf("6 ok\n");
    }

    list_delete(&list);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    printf("%d/6\n", passed);

    return 0;
}