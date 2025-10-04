#include<stdio.h>

int main(void){

    int m[100];
    int c, d, x = 0, n;

    printf("Put the count of numbers\n");
    scanf("%d", &n);

    while((scanf("%d", &c)) == 1){ //потому что scanf возвращает кол-во успешно прочитанных элементов, пока элементы числа, считывание продолжается

        m[x] = c;
        ++x;

        if ((c = getchar()) == '\n'){
        break;
        }
    }

    int count1 = sort(m, n);

    printf("%d", count1);

}
