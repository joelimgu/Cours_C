
#ifndef SYMBOL_LIST_H
#define SYMBOL_LIST_H
#include "joel_macros.h"
#include "interpreter.h"

// pointer to a callable integer (func) that takes Etat as argument
typedef int (*Commande)(Etat*);

typedef struct Symbols {
    char * token;
    Commande func;
} Symbol;

typedef struct Cells {
    Symbol val;
    struct Cells *next;
} SymbolList;

SymbolList * empty_list();

enum bool add_entry(SymbolList ** mut l, char * t, Commande f);

#endif