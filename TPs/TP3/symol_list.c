
#include <stdlib.h>
#include <string.h>
#include "symol_list.h"
#include "joel_macros.h"

/*
Checklist:
 [x] creer table symboles
 [ ] ajouter une entree
 [ ] cherche pour un token dans la liste
 [ ] initialiser la liste avec une liste déjà existante ???? // todo ask for this
 */


SymbolList * empty_list() {
    return NULL;
}

enum bool add_entry(SymbolList ** mut l, char * t, Commande f) {
    if ( *l == NULL ) {
        *l = malloc(sizeof(SymbolList));
        strcpy((*l)->val.token, t);
        (*l)->val.func = f;
    }
}