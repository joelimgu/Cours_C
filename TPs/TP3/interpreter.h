
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#define ASCII_MOINS 45
#define ASCII_SOMME 43
#define ASCII_MULT 42


typedef struct Programme {
    char **tokens;
    int taille;
} Programme;

typedef struct {
    Stack s;
    Programme p;
} Etat;

int numberOfDelimiters(char* string);

Programme* lexer(char* chaine);

void print_tokens(Programme * p);

int executer(Etat *etat);

void test_forth();

#endif