
#include <stdlib.h>
#include <string.h>
#include "symbol_list.h"
#include "joel_macros.h"

/*
Checklist:
 [x] creer table symboles
 [x] ajouter une entree
 [x] cherche pour un token dans la liste
 [ ] initialiser la liste avec une liste déjà existante ???? // todo ask for this
*/


/// returns the index of the token
int search_token(SymbolList *l, char *token) {
    SymbolList *aux = l;
    int index = 0;
    if ( aux == NULL ) return -1;
    while ( aux->next != NULL ) {
        if ( compare_string(aux->val.token, token) ) return index;
        aux = aux->next;
        index++;
    }
    if ( compare_string(aux->val.token, token) ) return index;
    return -1;
}

/// returns the pointer to the corresponding function or NULL if not found
Commande search_token_function_pointer(SymbolList *l, char *token) {
    SymbolList *aux = l;
    int index = 0;
    if ( aux == NULL ) return NULL;
    while ( aux->next != NULL ) {
        if ( compare_string(aux->val.token, token) ) return aux->val.func;
        aux = aux->next;
        index++;
    }
    if ( compare_string(aux->val.token, token) ) return aux->val.func;
    return NULL;
}

SymbolList * empty_list() {
    return NULL;
}

enum bool add_entry(SymbolList ** mut l, char * t, Commande f) {
    if ( *l == NULL ) {
        int i = 0;
        while ( t[i] != '\0' ) i++; // get the length of the str
        *l = malloc(sizeof(SymbolList));
        (*l)->next = NULL;
        (*l)->val.token = malloc(sizeof(char)*i);
        strcpy((*l)->val.token, t);
        (*l)->val.func = f;
    } else {
        int i = 0;
        while ( t[i] != '\0' ) i++; // get the length of the str
        SymbolList * aux = *l;
        while ( aux->next != NULL ) aux = aux->next;

        aux->next = malloc(sizeof(SymbolList));
        aux->next->next = NULL;
        aux->next->val.token = malloc(sizeof(char)*i);
        strcpy(aux->next->val.token, t);
        aux->next->val.func = f;
    }
    return true;
}


SymbolList * init_symbol_list(char noms[][10], Commande * command, int len_commands) {
    SymbolList * s = empty_list();
    for ( int i = 0; i < len_commands; i++ ) {
        add_entry(&s, noms[i], command[i]);
    }
    return s;
}