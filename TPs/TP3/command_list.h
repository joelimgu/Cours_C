
#ifndef COMMAND_H
#define COMMAND_H

#include "stack.h"

int drop(Etat * mut e);

int dup(Etat * mut e);

int swap(Etat * mut e);

int rot(Etat * mut e);

int sum(Etat * mut e);

int subtract(Etat * mut e);

int multiply(Etat * mut e);

int pop_and_print(Etat * e);

int print_stack_from_etat(Etat *e);


#endif