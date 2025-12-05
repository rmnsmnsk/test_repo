#include <stdbool.h>
int find_max(bool* bits, int n)
{
    int max = 0;
    for (int s = 0; s < n; s++) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (bits[(s + i) % n])
                num = (num << 1) | 1;
            else
                num = num << 1;
        }
        if (num > max)
            max = num;
    }
    return max;
}