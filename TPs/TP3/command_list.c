

#include "stack.h"
#include "interpreter.h"
#include "joel_macros.h"

int drop(Etat * mut e) {
    Stack *s = &(e->s);
    return pop(s);
}


int dup(Etat * mut e) {
    Stack *s = &(e->s);
    int last = pop(s);
    push(s, last);
    push(s, last);
    return 0;
}


int swap(Etat * mut e) {
    Stack *s = &(e->s);
    int last = pop(s);
    int ant = pop(s);
    push(s, last);
    push(s, ant);
    return 0;
}


int rot(Etat * mut e) {
    Stack *s = &(e->s);
    int first = pop(s);
    int second = pop(s);
    int third = pop(s);
    push(s,second);
    push(s,first);
    push(s, third);
    return 0;
}

int sum(Etat * mut e) {
    Stack *s = &e->s;
    int a,b;
    b = pop(s);
    a = pop(s);
    push(s, a + b);
}

int subtract(Etat * mut e) {
    Stack *s = &e->s;
    int a,b;
    b = pop(s);
    a = pop(s);
    push(s, a - b);

}

int multiply(Etat * mut e) {
    Stack *s = &e->s;
    int a,b;
    b = pop(s);
    a = pop(s);
    push(s, a * b);
}