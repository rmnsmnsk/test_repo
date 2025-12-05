#include "cyclic.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Введите количество бит: ");
    scanf("%d", &n);

    bool* bits = malloc(n * sizeof(bool));
    printf("Введите биты:\n");
    for (int i = 0; i < n; i++) {
        int bit;
        scanf("%d", &bit);
        bits[i] = (bit == 1);
    }

    int result = find_max(bits, n);
    printf("%d\n", result);

    free(bits);

    return 0;
}