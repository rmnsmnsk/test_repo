#include<stdio.h>
#include<stdlib.h>

typedef struct Warrior{
    int place;
    struct Warrior* next;
}Warrior;

Warrior* create(int place){
    Warrior* new = (Warrior*)malloc(sizeof(Warrior));
    new -> place = place;
    new -> next = NULL;
    return new;
}

int chet(int n, int m){

    Warrior* head = create(1);
    Warrior* current = head;

    for (int i = 2; i <= n; ++i){
        Warrior* new = create(i);
        current -> next = new;
        current = new;
    }

    current -> next = head; //замкнул список
    current = head;
    Warrior *pred = current;
    
    while (current -> next != current){

        for (int j = 1; j <= m-1; ++j){
            pred = current;
            current = current -> next;
        }

        pred -> next = current -> next;
        Warrior* quit = current;
        current = current -> next;
        free(quit);

    }
    int last = current -> place;
    free(current);
    return last;
}

int main(void){
    
    int n, m;
    printf("Введите количество войнов - целое, неотрицательное число\n");
    scanf("%d", &n);
    printf("Введите через сколько человек убивают - целое, неотрицательное число\n");
    scanf("%d", &m);

    int laststand = chet(n, m);
    printf("Последний оставшийся - под номером %d\n", laststand);
    return 0;
}
