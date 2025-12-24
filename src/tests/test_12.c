#include "../12.2_c/float_rep.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    const char* res;

    res = get_float_representation(0.0);
    if (strcmp(res, "+0.0*2^-1022") == 0) {
        printf("Тест 1 пройден: 0.0 -> %s\n", res);
    } else {
        printf("Тест 1 не пройден: ожидалось +0.0*2^-1022, получено %s\n", res);
    }

    res = get_float_representation(-0.0);
    if (strcmp(res, "-0.0*2^-1022") == 0) {
        printf("Тест 2 пройден: -0.0 -> %s\n", res);
    } else {
        printf("Тест 2 не пройден: ожидалось -0.0*2^-1022, получено %s\n", res);
    }

    res = get_float_representation(1.0);
    if (strcmp(res, "+1.0000000000000000000*2^0") == 0) {
        printf("Тест 3 пройден: 1.0 -> %s\n", res);
    } else {
        printf("Тест 3 не пройден: ожидалось +1.0000000000000000000*2^0, получено %s\n", res);
    }

    res = get_float_representation(2.0);
    if (strcmp(res, "+1.0000000000000000000*2^1") == 0) {
        printf("Тест 4 пройден: 2.0 -> %s\n", res);
    } else {
        printf("Тест 4 не пройден: ожидалось +1.0000000000000000000*2^1, получено %s\n", res);
    }

    res = get_float_representation(INFINITY);
    if (strcmp(res, "+Infinity") == 0) {
        printf("Тест 5 пройден: Infinity -> %s\n", res);
    } else {
        printf("Тест 5 не пройден: ожидалось +Infinity, получено %s\n", res);
    }

    res = get_float_representation(NAN);
    if (strcmp(res, "NaN") == 0) {
        printf("Тест 6 пройден: NaN -> %s\n", res);
    } else {
        printf("Тест 6 не пройден: ожидалось NaN, получено %s\n", res);
    }

    res = get_float_representation(-3.0);
    if (strcmp(res, "-1.5000000000000000000*2^1") == 0) {
        printf("Тест 7 пройден: -3.0 -> %s\n", res);
    } else {
        printf("Тест 7 не пройден: ожидалось -1.5000000000000000000*2^1, получено %s\n", res);
    }

    return 0;
}