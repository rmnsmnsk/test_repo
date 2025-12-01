#include <stdint.h>
#include <stdio.h>

typedef union Number {
    double value;
    uint64_t bits; // для 64 бит, в памяти double - (1 бит - знак, след 11 - экспонента, оставшиеся 52 - мантисса)
} Number;

int main()
{
    Number num;

    printf("Введите число double: ");
    scanf("%lf", &num.value);

    uint64_t b = num.bits;
    int s = (b >> 63) & 1; // знак
    int exp = (b >> 52) & 2047; // экспонента, 2047 - 11 единиц
    uint64_t mbits = b & 4503599627370495; // 4503599627370495 - 52 единицы

    if (exp == 0 && mbits == 0) {
        printf("Результат: +0.0*2^0\n");
        return 0;
    }

    int rexp = exp - 1023; // в памти хранятся со сдвигом

    mbits |= (1ULL << 52); // добавляю скрытую единицу, а 1ULL - просто 1 в 64 битах

    double m = 0.0;
    double w = 1.0;

    for (int i = 52; i >= 0; i--) {
        if ((mbits >> i) & 1) {
            m += w;
        }
        w /= 2.0;
    }

    if (s == 0) {
        printf("Результат: +%.19lf*2^%d\n", m, rexp);
    } else {
        printf("Результат: -%.19lf*2^%d\n", m, rexp);
    }

    return 0;
}
