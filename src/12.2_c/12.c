#include "float_rep.h"
#include <stdio.h>

int main()
{
    double value;

    printf("Введите число double: ");
    scanf("%lf", &value);

    const char* result = get_float_representation(value);
    printf("%s\n", result);

    return 0;
}