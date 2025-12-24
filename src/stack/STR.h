#ifndef STR_H
#define STR_H

typedef struct Elem {
  char data;
  struct Elem *next;
} Elem;

Elem *stack_new(void);
Elem *push(Elem *top, char data);
char pop(Elem **top);

#endif