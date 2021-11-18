
#include <stdio.h>
#include "eleves.h"
#include <stdlib.h>
#include "constantes.h"
#include <string.h>

struct eleve * init_eleve(char * nom, int promo) {
    struct eleve *e = malloc(sizeof(struct eleve));
    strcpy(e->nom,nom);
    e->promo = promo;
    return e;
}

void affiche_eleve(struct eleve * e) {
    printf("Nom: %s ; Promo: %d\n", e->nom, e->promo);
}