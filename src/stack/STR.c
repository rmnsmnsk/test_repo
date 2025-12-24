#include "STR.h"
#include <stddef.h>
#include <stdlib.h>

Elem *stack_new(void) { return NULL; }

Elem *push(Elem *top, char data) {
  Elem *new_elem = (Elem *)malloc(sizeof(Elem));
  if (new_elem == NULL) {
    return NULL;
  }
  new_elem->data = data;
  new_elem->next = top;
  return new_elem;
}

char pop(Elem **top) {
  if (*top == NULL) {
    return '\0';
  }
  Elem *temp = *top;
  char data = temp->data;
  *top = (*top)->next;
  free(temp);
  return data;
}