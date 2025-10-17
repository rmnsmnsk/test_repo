#include <stdio.h>
#include <stdlib.h>

int sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    return 1;
}

void monkey(int arr[], int n) {
    while (!sorted(arr, n)) {
        int i = rand() % n;
        int j = rand() % n;
        int back = arr[i];
        arr[i] = arr[j];
        arr[j] = back;
    }
}

int main(void) {
    int posl[100];
    int c = 0;
    char d;
    int i = 0;
    
    while ((scanf("%d", &c) == 1)) {
        posl[i] = c;
        ++i;
        if ((d = getchar()) == '\n') {
            break;
        }
    }
    
    monkey(posl, i);

    for (int j = 0; j < i; j++) {
        printf("%d ", posl[j]);
    }
    
    return 0;
}