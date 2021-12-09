

#include "stack.h"
#include "interpreter.h"
#include "joel_macros.h"

Value drop(Etat * mut e) {
    Stack *s = &(e->s);
    return pop(s);
}


int dup(Etat * mut e) {
    Stack *s = &(e->s);
    Value last = pop(s);
    push(s, last);
    push(s, last);
    return 0;
}


int swap(Etat * mut e) {
    Stack *s = &(e->s);
    Value last = pop(s);
    Value ant = pop(s);
    push(s, last);
    push(s, ant);
    return 0;
}


int rot(Etat * mut e) {
    Stack *s = &(e->s);
    Value first = pop(s);
    Value second = pop(s);
    Value third = pop(s);
    push(s,second);
    push(s,first);
    push(s, third);
    return 0;
}

void sum(Etat * mut e) {
    Stack *s = &e->s;
    Value a,b,c;
    b = pop(s);
    a = pop(s);
    if ( a.type == b.type ) {
        if ( a.type == Float) {
            c.type = Int;
            c.val.Float = a.val.Float + b.val.Float;
            push(s, c);
        } else if ( a.type == Int ) {
            c.type = Int;
            c.val.Int = a.val.Int + b.val.Int;
            push(s, c);
        }
    } else if ( a.type == Float && b.type == Int ) {
        c.type = Float;
        c.val.Float = a.val.Float + b.val.Int;
        push(s, c);

    } else if ( a.type == Int ) {
        c.type = Float;
        c.val.Float = a.val.Int + b.val.Float;
        push(s, c);
    }
}

int subtract(Etat * mut e) {
    Stack *s = &e->s;
    Value a,b,c;
    b = pop(s);
    a = pop(s);
    if ( a.type == b.type ) {
        if ( a.type == Float) {
            c.type = Int;
            c.val.Float = a.val.Float - b.val.Float;
            push(s, c);
        } else if ( a.type == Int ) {
            c.type = Int;
            c.val.Int = a.val.Int - b.val.Int;
            push(s, c);
        }
    } else if ( a.type == Float && b.type == Int ) {
        c.type = Float;
        c.val.Float = a.val.Float - b.val.Int;
        push(s, c);

    } else if ( a.type == Int ) {
        c.type = Float;
        c.val.Float = a.val.Int - b.val.Float;
        push(s, c);
    }
}

int multiply(Etat * mut e) {
    Stack *s = &e->s;
    Value a,b,c;
    b = pop(s);
    a = pop(s);
    if ( a.type == b.type ) {
        if ( a.type == Float) {
            c.type = Int;
            c.val.Float = a.val.Float * b.val.Float;
            push(s, c);
        } else if ( a.type == Int ) {
            c.type = Int;
            c.val.Int = a.val.Int * b.val.Int;
            push(s, c);
        }
    } else if ( a.type == Float && b.type == Int ) {
        c.type = Float;
        c.val.Float = a.val.Float * b.val.Int;
        push(s, c);

    } else if ( a.type == Int ) {
        c.type = Float;
        c.val.Float = a.val.Int * b.val.Float;
        push(s, c);
    }
}

void print_value(Value *v) {
    if ( v->type == Int ) {
        printf("%d", v->val.Int);
    } else if ( v->type == Float ) {
        printf("%f", v->val.Float);
    } else {
        printf("%s", v->val.str);
    }
    printf("\n");
}


int pop_and_print(Etat *e) {
    Stack *s = &e->s;
    Element *first = s->first;
    if ( s->first == NULL ) fprintf(stderr, "Cannot pop from empty list: %d\n", -1);
    s->first = s->first->next;
    print_value(&first->val);
    // if it contains a string we also free it's memory
    if ( first->val.type == str ) {
        free(first->val.val.str);
    }
    free(first);
    s->len -= 1;
    return 0;
}

int print_stack_from_etat(Etat *e) {
    print_stack(&e->s);
    return 0;
}