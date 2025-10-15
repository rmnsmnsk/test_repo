#include<stdio.h>
#include"stack/STR.h"

int main(void){

    char posl[100];
    printf("Put the string\n");
    scanf("%s", posl);

    Elem *top = new();

    for (int i = 0; posl[i] != '\0'; ++i){
        if (posl[i] == '(' || posl[i] == '{' || posl[i] == '[' ){
            top = push(top, posl[i]);
        }
        else if (posl[i] == ')' || posl[i] == '}' || posl[i] == ']' ){
            char symbol1 = posl[i];
            if (top == NULL){
                printf("The sring is incorrect\n");
                return 1;
            }
            char symbol = pop(&top);
            if ((symbol1 == ')' && symbol != '(') || (symbol1 == '}' && symbol != '{') || (symbol1 == ']' && symbol != '[')){
                printf("The string is incorrect\n");
		return 1;
            }
        }
    }

    if (top == NULL){
	printf("The string is correct\n");
	return 0;
    }
    else{
	printf("The string is incorrect\n");
	return 1;
    }
}
