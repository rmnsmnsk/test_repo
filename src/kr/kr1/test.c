#include <stdio.h>
#include <stdbool.h>

int find_max(bool* bits, int n);

int main() {
    int p = 0;
    
    {
        bool b[] = {1,0,1,1};
        int r = find_max(b, 4);
        if (r == 14) { 
            printf("1 ok\n"); p++; }
        else {
            printf("1 fail: %d\n", r);
        }
    }
    
    {
        bool b[] = {1,1,1};
        int r = find_max(b, 3);
        if (r == 7) { 
            printf("2 ok\n"); p++; 
        }
        else printf("2 fail: %d\n", r);
    }
    
    {
        bool b[] = {0,0,0};
        int r = find_max(b, 3);
        if (r == 0) { 
            printf("3 ok\n"); p++; 
        }
        else printf("3 fail: %d\n", r);
    }
    
    {
        bool b[] = {1,0,0,1};
        int r = find_max(b, 4);
        if (r == 12) { 
            printf("4 ok\n"); p++; 
        }
        else {
            printf("4 fail: %d\n", r);
        }
    }
    
    printf("%d/4\n", p);
    return 0;
}