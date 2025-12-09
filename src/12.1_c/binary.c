#include "summ.h"
#include <stdbool.h>
#include <stdlib.h>

#define BITS 8

bool* binary(int i)
{
    bool* bits = (bool*)malloc(sizeof(bool) * BITS);

    for (int j = 0; j < BITS; j++) {
        bits[j] = false;
    }

    int j = BITS - 1;

    if (i >= 0) {
        while (i > 0 && j >= 0) {
            bits[j] = (i % 2);
            i /= 2;
            j -= 1;
        }
    } else {
        i *= -1;

        while (i > 0) {
            bits[j] = (i % 2);
            i /= 2;
            j -= 1;
        }

        for (int k = 0; k < BITS; ++k) {
            bits[k] = !bits[k];
        }

        bool* one = (bool*)malloc(sizeof(bool) * BITS);

        for (int r = 0; r < BITS; r++) {
            one[r] = false;
        }

        one[BITS - 1] = true;

        bool* temp = summ(bits, one);
        free(bits);
        bits = temp;
        free(one);
    }
    return bits;
}