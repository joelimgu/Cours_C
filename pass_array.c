//
// Created by joel on 20/9/21.
//

#include <stdio.h>

void aff(int tab[], int taille) {
    int i;
//    printf("%d", sizeof(tab)); // dosent work
    for (i=0; i<taille; i++){
        printf("%d", tab[i]);
    }
    printf("\n");
}

int main(){
int tab[5] = {1,2,3,4,5};
aff(tab,5);
aff(tab,sizeof(tab)/sizeof(int)); // on peut juste savoir la taille du tableau si c'est un tableau statique declare dans le même scope
}