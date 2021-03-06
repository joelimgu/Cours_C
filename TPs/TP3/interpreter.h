
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

#include "joel_macros.h"
#define ASCII_MOINS 45
#define ASCII_SOMME 43
#define ASCII_MULT 42


enum bool compare_string(char *s1, char *s2);

typedef struct Programme {
    char **tokens;
    int taille;
} Programme;

typedef struct Etats Etat;

// pointer to a callable integer (func) that takes Etat as argument
typedef int (*Commande)(Etat*);

#include "symbol_list.h" // bc it needs Commande to be defined

enum Mode {Execution, Printing};

typedef struct Etats {
    Stack s;
    Programme p;
    enum Mode mode;
    void * symbols; // pointer to SymbolList it errors if we define the type
} Etat;

int numberOfDelimiters(char* string);

Programme* lexer(char* chaine);

void print_tokens(Programme * p);

Value executer(Etat *etat);

void test_forth();

#endif