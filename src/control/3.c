#include<stdio.h>

int main(void) {
    int n = 0;

    printf("Введите число: ");
    scanf("%d", &n);

    for (int j = 1; j <= n; ++j) {
        int digits[100];
        int length = 0;
        
        int temp = j;
        while (temp > 0) {
            digits[length] = (temp % 2);
            ++length;
            temp /= 2;
        }
        
        int flag = 1;
        for (int i = 0; i < length / 2; ++i) {
            if (digits[i] != digits[length - 1 - i]) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            printf("%d\n", j);
        }
    }
    
    return 0;
}