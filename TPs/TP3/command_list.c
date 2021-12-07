

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
//    Stack *s = &e->s;
//    Value a,b;
//    b = pop(s);
//    a = pop(s);
//    push(s, a - b);
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
//    Stack *s = &e->s;
//    Value a,b;
//    b = pop(s);
//    a = pop(s);
//    push(s, a * b);
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