#include "float_rep.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static char output[256];

typedef union {
    double value;
    uint64_t bits;
} DoubleUnion;

const char* get_float_representation(double value)
{
    DoubleUnion num;
    num.value = value;

    uint64_t b = num.bits;
    int sign = (b >> 63) & 1;
    int exponent = (b >> 52) & 2047;
    uint64_t mantissa = b & ((1ULL << 52) - 1);

    if (exponent == 2047) {
        if (mantissa == 0) {
            if (sign == 0) {
                return "+Infinity";
            } else {
                return "-Infinity";
            }
        } else {
            return "NaN";
        }
    }

    if (exponent == 0 && mantissa == 0) {
        if (sign == 0) {
            return "+0.0*2^-1022";
        } else {
            return "-0.0*2^-1022";
        }
    }

    int real_exp;
    if (exponent == 0) {
        real_exp = -1022;
    } else {
        real_exp = exponent - 1023;
        mantissa |= (1ULL << 52);
    }

    double m = 0.0;
    double weight = 1.0;

    int start = (exponent == 0) ? 51 : 52;

    for (int i = start; i >= 0; i--) {
        if ((mantissa >> i) & 1) {
            m += weight;
        }
        weight /= 2.0;
    }

    if (sign == 0) {
        sprintf(output, "+%.19lf*2^%d", m, real_exp);
    } else {
        sprintf(output, "-%.19lf*2^%d", m, real_exp);
    }

    return output;
}