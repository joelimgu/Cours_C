#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#define ASCII_MOINS 45
#define ASCII_SOMME 43
#define ASCII_MULT 42
#include "interpreter.h"
#include "command_list.h"

// todo union type
// maybe create a struct to keep track of the type and the union macro_rules!();
union Test {
    int ValEntier;
    float ValReel;
};


enum bool compare_string(char * s1, char * s2) {
    int len1 = 0;
    int len2 = 0;
    while ( s1[len1] != '\0' ) len1++;
    while ( s2[len2] != '\0' ) len2++;

    if ( len1 != len2) return false;
    for ( int i = 0; i < len1; i++ ) {
        if ( s1[i] != s2[i] ) return false;
    }
    return true;
}


int numberOfDelimiters(char* string) {
    int count = 0;
    for (int i=0;i<strlen(string);i++) {
        if (string[i] == ' ') count++;
    }
    return count;
}


Programme* lexer(char* chaine) {
    char *token,*str;
    str = strdup(chaine);
    int i=0;
    int arraySize = (numberOfDelimiters(str)+1);
    char** programme = (char**)malloc(sizeof(char*)*arraySize);
    while ( (token = strsep(&str, " ")) ) {
        programme[i] = token;
        i++;
    }
    Programme *retour = (Programme*)malloc(sizeof(Programme));
    retour->tokens = programme;
    retour->taille = i;
    return retour;
}


void print_tokens(Programme * p) {
    char ** tokens = p->tokens;
    for (int i = 0; i< p->taille; i++) {
        printf("TOKEN : %s\n", tokens[i]);
    }
}


int executer(Etat *etat) {
    Programme p = etat->p;
    Stack *s = &etat->s;
    int a,b;
    for (int i = 1; i<=p.taille; i++) {
        char * token = p.tokens[i-1];

        if ( compare_string("+", token) ) { // sum
            sum(etat);
        } else if (compare_string("-", token)) { // substraction
            subtract(etat);
        } else if (compare_string("*", token) ) { // multiplication
            multiply(etat);
        } else {
            push(s, atoi(p.tokens[i-1])); // we have a value
        }

//        switch ((int)p.tokens[i-1][0]) {
//            case ASCII_SOMME:
////                print_stack(&s);
//                b = pop(&s);
//                a = pop(&s);
//                push(&s, a + b);
////                printf("%d + %d = %d\n", a , b, a+b );
//                continue;
//            case ASCII_MULT:
////                print_stack(&s);
//                b = pop(&s);
//                a = pop(&s);
//                push(&s, a * b);
////                printf("%d * %d = %d\n", a , b, a*b );
//                continue;
//            case ASCII_MOINS:
////                print_stack(&s);
//                b = pop(&s);
//                a = pop(&s);
//                push(&s, a - b);
////                printf("%d - %d = %d\n", a , b, a-b );
//                continue;
//            default: // we have a value
//                push(&s, atoi(p.tokens[i-1]));
//        }
    }
    int res = pop(s);
    return res;
}