#include<stdio.h>

int chisl(int x){
    if (x < 0){
        x = -x;
    }
    int sum = 0;
    while (x > 0){
        sum += (x % 10);
        x /= 10;
    }
    return sum;

}


int main(void){
    int posl[100];
    int i = 0;
    int c = 0;
    char d;
    int ma = 0;
    int y = 0;
    int posl1[100];
    int s = 0;
    while ((scanf("%d", &c) == 1)){
        posl[i] = c;
        ++i;
        if ((d = getchar()) == '\n'){
            break;
        }
    }

    for (int j = 0; j < i; ++j){
        y = chisl(posl[j]);
        if (y > ma){
            ma = y;
        }
    }

    for (int j = 0; j < i; ++j){
        if (chisl(posl[j]) == ma){
            posl1[s] = posl[j];
            ++s;
        }
    }
    printf("Все числа с макс суммой\n");
    for (int b = 0; b < s; ++b){
        printf("%d ", posl1[b]);
    }
    return 0;

}