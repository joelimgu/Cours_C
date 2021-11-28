
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/// evaluates to nothing.
/// Just signifies that the reference on which it is applied will modify its value
# define mut

/// signifies that the value will bre dropped inside the function so it shouldn't be used after that call
#define owned

/// creates an empty stack <=> a stack of len 0 and null elements
Stack * create_empty_stack() {
    Stack *s = malloc(sizeof(Stack));
    s->len = 0;
    s->first = NULL;
    return s;
}

/// takes a mut ref of Stack and adds an element on top
void push(Stack * mut s, int val) {
    Element *old_first = s->first;
    Element *new = malloc(sizeof(Element));
    new->val = val;
    new->next = old_first;
    s->first = new;
    s->len += 1;
}

/// takes a mut ref of a Stack and removes and returns the top element
int pop(Stack * mut s) {
    Element *first = s->first;
    int val;
    if ( s->first == NULL ) fprintf(stderr, "Cannot pop from empty list: %d\n", -1);
    s->first = s->first->next;
    val = first->val;
    free(first);
    s->len -= 1;
    return val;
}

/// takes a ref of Stack and prints it in stdout
void print_stack(Stack * mut s) {
    Element *l = s->first;
    printf("len: %d\n", s->len);
    printf("[");
    while ( l != NULL ) {
        printf("%d, ", l->val);
        l = l->next;
    }
    printf("]\n");
}

/// runs functions to test if code works
void test_stack() {
    Stack *s = create_empty_stack();
    push(s,1);
    push(s,2);
    push(s,3);
    print_stack(s);
    printf("Popped element: %d\n", pop(s));
    print_stack(s);
}
