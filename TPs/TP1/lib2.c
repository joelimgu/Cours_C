
#include <stdio.h>
#include "lib2.h"
#include <stdlib.h>

void Affiche(char * s) {
    printf("%s\n",s);
}

int Fact(int num) {
    if (num == 0) return 1;

    return num*(Fact(num-1));
}

void Date() {
    system("/bin/date");
}