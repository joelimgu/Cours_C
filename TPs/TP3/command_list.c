

#include "stack.h"


int drop(Stack *s) {
    return pop(s);
}


int dup(Stack *s) {
    int last = pop(s);
    push(s, last);
    push(s, last);
    return 0;
}


int swap(Stack *s) {
    int last = pop(s);
    int ant = pop(s);
    push(s, last);
    push(s, ant);
    return 0;
}


int rot(Stack *s) {
    int first = pop(s);
    int second = pop(s);
    int third = pop(s);
    push(s,second);
    push(s,first);
    push(s, third);
    return 0;
}