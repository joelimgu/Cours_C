
#ifndef SYMBOL_LIST_H
#define SYMBOL_LIST_H
#include "joel_macros.h"
#include "interpreter.h"




typedef struct Symbols {
    char * token;
    Commande func;
} Symbol;

typedef struct Cells {
    Symbol val;
    struct Cells *next;
} SymbolList;

int search_token(SymbolList *l, char *token);

SymbolList * empty_list();

enum bool add_entry(SymbolList ** mut l, char * t, Commande f);

SymbolList * init_symbol_list(char noms[][10], Commande * command, int len_commands);

#endif