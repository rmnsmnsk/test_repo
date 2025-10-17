#include<stdio.h>

int main(void) {
    int n = 0;

    printf("Введите число: ");
    scanf("%d", &n);
    int flag = 1;

    for (int j = 1; j <= n; ++j) {
        for (int b = j + 1; b <= n; ++b) {
            flag = 1;
            int char1[100];
            int char2[100];
            int l = 0;
            int h = 0;

            int tempj = j;
            int tempb = b;

            while (tempj > 0) {
                char1[l] = (tempj % 2);
                ++l;
                tempj /= 2;
            }

            while (tempb > 0) {
                char2[h] = (tempb % 2);
                ++h;
                tempb /= 2;
            }

            if (l == h) {
                for (int d = 0; d < l; ++d) {
                    if (char1[d] != char2[l - 1 - d]) { 
                        flag = 0;
                        break;
                    }
                }
            } 
            else {
                flag = 0;
            }
            
            if (flag == 1) {
                printf("%d %d\n", j, b); 
            }
        }
    }
    
    return 0;
}