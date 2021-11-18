#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "eleves.h"

int main() {
    struct eleve *el = init_eleve("Joel", 56);
    affiche_eleve(el);
    return 0;
}