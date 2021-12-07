//
// Created by joel on 7/12/21.
//

#ifndef ETAT_H
#define ETAT_H

#include "symbol_list.h"

typedef struct Programme {
    char **tokens;
    int taille;
} Programme;

typedef struct Etats Etat;

// pointer to a callable integer (func) that takes Etat as argument
typedef int (*Commande)(Etat*);

#endif //TEST_ETAT_H
