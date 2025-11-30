#include <math.h>
#include <stdbool.h> //т.к int будет слишком избыточен для хранения 1 и 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BITS 8

// дополнительный код для положительных чисел = обычному
// будут брать 8 бИт, для большего количечства вс1 тоже самое, просто в malloc меняется цифра

// ФУНКЦИИ
bool* summ(bool* i, bool* j)
{

    bool* bits = (bool*)malloc(sizeof(bool) * BITS);

    for (int j = 0; j < BITS; j++) {
        bits[j] = false;
    }

    bool flag = false;

    for (int k = BITS - 1; k >= 0; --k) {
        bool number = (i[k] + j[k] + flag) % 2; // т.к 1 + 1 = 2, 1 + 1 + 1 = 3
        bits[k] = number;
        flag = ((i[k] + j[k] + flag) >= 2);
    }

    return bits;
}

bool* binary(int i)
{

    bool* bits = (bool*)malloc(sizeof(bool) * BITS);

    for (int j = 0; j < BITS; j++) {
        bits[j] = false;
    }

    int j = BITS - 1;

    if (i >= 0) {
        while (i > 0 && j >= 0) {
            bits[j] = (i % 2 == 1);
            i /= 2;
            j -= 1;
        }
    }

    else {

        i *= -1;

        while (i > 0) {
            bits[j] = (i % 2);
            i /= 2;
            j -= 1;
        }

        for (int k = 0; k < BITS; ++k) { // инвертирую
            bits[k] = !bits[k];
        }

        bool* one = (bool*)malloc(sizeof(bool) * BITS); // задаю единицу

        for (int r = 0; r < BITS; r++) {
            one[r] = false;
        }

        one[BITS - 1] = true;

        bool* temp = summ(bits, one); // если бы я присвоил сразу указателю bits, то память бы утекла, т.к есть ещё просто bits
        free(bits);
        bits = temp;
        free(one);
    }
    return bits;
}

// ТЕСТЫ
void run_tests()
{
    printf("Тест 1: Положительное число 5\n");
    bool* result1 = binary(5);
    bool expected1[8] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    bool test1_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (result1[i] != expected1[i]) {
            test1_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test1_passed);
    free(result1);

    printf("Тест 2: Отрицательное число -5\n");
    bool* result2 = binary(-5);
    bool expected2[8] = { 1, 1, 1, 1, 1, 0, 1, 1 };
    bool test2_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (result2[i] != expected2[i]) {
            test2_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test2_passed);
    free(result2);

    printf("Тест 3: Ноль\n");
    bool* result3 = binary(0);
    bool expected3[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    bool test3_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (result3[i] != expected3[i]) {
            test3_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test3_passed);
    free(result3);

    printf("Тест 4: Сложение 5 + (-3)\n");
    bool* bin5 = binary(5);
    bool* binMinus3 = binary(-3);
    bool* sum_result = summ(bin5, binMinus3);
    bool expected4[8] = { 0, 0, 0, 0, 0, 0, 1, 0 };
    bool test4_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (sum_result[i] != expected4[i]) {
            test4_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test4_passed);
    free(bin5);
    free(binMinus3);
    free(sum_result);

    printf("Тест 5: Сложение -5 + 3\n");
    bool* binMinus5 = binary(-5);
    bool* bin3 = binary(3);
    bool* sum_result2 = summ(binMinus5, bin3);
    bool expected5[8] = { 1, 1, 1, 1, 1, 1, 1, 0 };
    bool test5_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (sum_result2[i] != expected5[i]) {
            test5_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test5_passed);
    free(binMinus5);
    free(bin3);
    free(sum_result2);

    printf("Тест 6: Максимальное положительное 127\n");
    bool* result6 = binary(127);
    bool expected6[8] = { 0, 1, 1, 1, 1, 1, 1, 1 };
    bool test6_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (result6[i] != expected6[i]) {
            test6_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test6_passed);
    free(result6);

    printf("Тест 7: Минимальное отрицательное -128\n");
    bool* result7 = binary(-128);
    bool expected7[8] = { 1, 0, 0, 0, 0, 0, 0, 0 };
    bool test7_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (result7[i] != expected7[i]) {
            test7_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test7_passed);
    free(result7);

    printf("Тест 8: Сложение -5 + (-3)\n");
    bool* binMinus5_2 = binary(-5);
    bool* binMinus3_2 = binary(-3);
    bool* sum_result3 = summ(binMinus5_2, binMinus3_2);
    bool expected8[8] = { 1, 1, 1, 1, 1, 0, 0, 0 };
    bool test8_passed = true;
    for (int i = 0; i < BITS; i++) {
        if (sum_result3[i] != expected8[i]) {
            test8_passed = false;
            break;
        }
    }
    printf("тест пройден %d\n", test8_passed);
    free(binMinus5_2);
    free(binMinus3_2);
    free(sum_result3);
}

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        run_tests();
        return 0;
    }

    printf("Введите два числа в пределе %d бит ", BITS);

    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    bool* resulta = binary(a);
    bool* resultb = binary(b);
    bool* result = summ(resulta, resultb);

    printf("Представление суммы в двоичном представлении: ");

    for (int n = 0; n < BITS; ++n) {
        printf("%d", result[n]);
    }
    printf("\n");

    printf("Представление суммы в десятитчном представлении: ");

    int h = 0;

    for (int n = BITS - 1; n >= 0; --n) {

        h += result[n] * (1 << (BITS - 1 - n)); // библиотека math требует линковки
    }

    if (result[0] == 1) {
        h = h - 256;
    }

    printf("%d\n", h);

    free(result);
    free(resulta);
    free(resultb);
    return 0;
}
