//
// Created by joel on 23/9/21.
//

#include <stdio.h>

int main(){
    int i;
    static int j;

    i=3;
    j=4;
    printf("%p\n", &i); // dans la pile
    printf("%p\n", &j); // dans le tas car c'est statique
    return 0;
}