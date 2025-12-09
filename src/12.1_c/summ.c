#include <stdbool.h>
#include <stdlib.h>

#define BITS 8

bool* summ(bool* i, bool* j)
{
    bool* bits = (bool*)malloc(sizeof(bool) * BITS);

    for (int j = 0; j < BITS; j++) {
        bits[j] = false;
    }

    bool flag = false;

    for (int k = BITS - 1; k >= 0; --k) {
        bool number = (i[k] + j[k] + flag) % 2;
        bits[k] = number;
        flag = ((i[k] + j[k] + flag) >= 2);
    }

    return bits;
}