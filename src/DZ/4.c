#include "sort.h"
#include <stdio.h>

int main() {
  int m[100];
  int n = 0;

  while (scanf("%d", &m[n]) == 1 && n < 100) {
    n++;
  }

  int count1 = sort(m, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", m[i]);
  }
  printf("\n");

  return count1;
}