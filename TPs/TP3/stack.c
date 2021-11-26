
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack * create_empty_stack() {
    Stack *s = malloc(sizeof(Stack));
    s->len = 0;
    s->first = NULL;
    return s;
}


void push(Stack * s, int val) {
    Element *old_first = s->first;
    Element *new = malloc(sizeof(Element));
    new->val = val;
    new->next = old_first;
    s->first = new;
    s->len += 1;
}


int pop(Stack *s) {
    Element *first = s->first;
    int val;
    if ( s->first == NULL ) fprintf(stderr, "Cannot pop from empty list: %d\n", -1);
    s->first = s->first->next;
    val = first->val;
    free(first);
    s->len -= 1;
    return val;
}


void print_stack(Stack *s) {
    Element *l = s->first;
    printf("len: %d\n", s->len);
    printf("[");
    while ( l != NULL ) {
        printf("%d, ", l->val);
        l = l->next;
    }
    printf("]\n");
}

void test_stack(){
    Stack *s = create_empty_stack();
    push(s,1);
    push(s,2);
    push(s,3);
    print_stack(s);
    printf("Popped element: %d\n", pop(s));
    print_stack(s);
}
