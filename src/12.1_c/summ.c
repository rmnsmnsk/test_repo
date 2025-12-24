#include <stdbool.h>
#include <stdlib.h>

#define BITS 8

bool* summ(bool* i, bool* j)
{
    bool* bits = (bool*)calloc(BITS, sizeof(bool));

    if (bits == NULL) {
        return NULL;
    }

    bool carry = false;

    for (int k = BITS - 1; k >= 0; --k) {
        bool number = (i[k] + j[k] + carry) % 2;
        bits[k] = number;
        carry = ((i[k] + j[k] + carry) >= 2);
    }

    return bits;
}