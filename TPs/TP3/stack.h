
#ifndef STACK_H
#define STACK_H


enum bool {false, true};
typedef enum bool bool;

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

void push(Stack * s, int val);

int pop(Stack *s);

void print_stack(Stack *s);

void test_stack();

#endif