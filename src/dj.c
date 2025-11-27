#include<stdio.h>
#include"stack/STR.h"

int priority(char q){
    if (q == '+' || q == '-'){
        return 1;
    }
    else if (q == '*' || q == ':'){
        return 2;
    }
    return 0;
}

int isoperator(char s){
    return s == '+' || s == '-' || s == '*' || s == '/' || s == ')' || s == '('; //я понимаю, что () - не операторы, но я так сделал для удобства
}

int main(void){

    int posl[100];
    int i = 0;
    char c;
    char q;

    Elem* top = new();
    printf("Put the string\n");
    while ((c = getchar()) != '\n'){ //конец ввода отделяется пробелом
	if (c == ' '){
	     continue;
	}
        if (!isoperator(c)){
            posl[i] = c;
            ++i;

        }
        else{
            if (c == '('){
                top = push(top, c);
            }
            else if (c == ')'){
                while (see(top) != '('){
                    q = pop(&top);
                    posl[i] = q;
                    ++i;
                }
                pop(&top); //удаляю открывающую скобку

            }
            else if (isoperator(c)){
                while (priority(see(top)) >= priority(c) && top != NULL && see(top) != '('){
                    q = pop(&top);
                    posl[i] = q;
		    ++i;
                
                }
                top = push(top,c);

            }
        }
    }
    while (top != NULL){
        q = pop(&top);
        posl[i] = q;
	++i;
        
    }
    for (int j = 0; j < i; ++j){
        printf("%c ", posl[j]);
    }
    return 0;
}
