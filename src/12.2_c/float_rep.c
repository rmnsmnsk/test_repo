#include "float_rep.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define DOUBLE_SIGN_SHIFT 63
#define DOUBLE_EXPONENT_SHIFT 52
#define DOUBLE_EXPONENT_MASK 2047
#define DOUBLE_MANTISSA_MASK ((1ULL << 52) - 1)
#define DOUBLE_EXPONENT_BIAS 1023
#define DOUBLE_EXPONENT_MAX 2047
#define DOUBLE_HIDDEN_BIT (1ULL << 52)
#define DOUBLE_SUBNORMAL_EXPONENT -1022

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
    int sign = (b >> DOUBLE_SIGN_SHIFT) & 1;
    int exponent = (b >> DOUBLE_EXPONENT_SHIFT) & DOUBLE_EXPONENT_MASK;
    uint64_t mantissa = b & DOUBLE_MANTISSA_MASK;

    if (exponent == DOUBLE_EXPONENT_MAX) {
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
            return "+0";
        } else {
            return "-0";
        }
    }

    int real_exp;
    if (exponent == 0) {
        real_exp = DOUBLE_SUBNORMAL_EXPONENT;
    } else {
        real_exp = exponent - DOUBLE_EXPONENT_BIAS;
        mantissa |= DOUBLE_HIDDEN_BIT;
    }

    double m = 0.0;
    double weight = 1.0;

    int start = 51;
    if (exponent != 0) {
        start = 52;
    }

    for (int i = start; i >= 0; i--) {
        if ((mantissa >> i) & 1) {
            m += weight;
        }
        weight /= 2.0;
    }

    if (sign == 0) {
        sprintf(output, "+%f*2^%d", m, real_exp);
    } else {
        sprintf(output, "-%f*2^%d", m, real_exp);
    }

    return output;
}