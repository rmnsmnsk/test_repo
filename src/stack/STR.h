#ifndef STACK_H
#define STACK_H

typedef struct obj{
    int data;
    struct obj* next;
}Elem;

Elem* new(void); //создаю голову, указатель указывает на NULL
Elem* push(Elem* top , char data); //добавляю на вершину стэка новый элемент, при этом функция возвращает указатель на самый верхний элемент
char pop(Elem** top); //удаляется верхний элемент, при этом возвращается его значение
void peek(Elem* top); //просто показывает самый верхний элемент
void delete(Elem** top);//очищает стэк

#endif