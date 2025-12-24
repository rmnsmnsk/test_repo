int sort(int *arr, int n) {
  int i = 0;
  int moved = 0;

  while (i < n) {
    int min_idx = i;
    int min_val = arr[i];
    int j = i + 1;

    while (j < n) {
      if (arr[j] < min_val) {
        min_idx = j;
        min_val = arr[j];
      }
      j++;
    }

    if (min_idx != i) {
      arr[min_idx] = arr[i];
      arr[i] = min_val;
      moved += 2;
    }

    i++;
  }

  return moved;
}