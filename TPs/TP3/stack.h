
#ifndef STACK_H
#define STACK_H

#include "joel_macros.h"

struct List {
    int val;
    struct List *next;
};
typedef struct List Element;


typedef struct {
    int len;
    Element * first;
} Stack;

Stack * create_empty_stack();

void push(Stack * mut s, int val);

int pop(Stack * owned s);

void print_stack(Stack *s);

void test_stack();

#endif