
#ifndef STACK_H
#define STACK_H

#include "joel_macros.h"


// maybe create a struct to keep track of the type and the union macro_rules!();
typedef union {
    int Int;
    float Float;
    char * str;
} ForthValues;

enum Types {Int, Float, str};

struct Value {
    ForthValues val;
    enum Types type;
};

// todo change type to Value
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