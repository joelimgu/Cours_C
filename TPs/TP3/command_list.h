
#ifndef COMMAND_H
#define COMMAND_H

#include "stack.h"
typedef int (*Commande)(Etat*);


int drop(Stack *s);

int dup(Stack * s);

int swap(Stack *s);

int rot(Stack *s);
#endif