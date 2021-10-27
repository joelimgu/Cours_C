
#define TAILLE 10
#include <stdio.h>
#include <stdlib.h>
/*
int main(void){
    char * chaine;
    int * tab;
    int i;
    for (i=0;i<TAILLE-1;i++){
        tab[i] = i+1;
        chaine[i] = (char)(i+65);
    }
    chaine[TAILLE-1] = 0;
    return 0;
}
--> segmentation fault
*/

int main(void){
    char * chaine = malloc(TAILLE*sizeof(int));
    int * tab = malloc(TAILLE*sizeof(int));
    int i;
    for (i=0;i<TAILLE-1;i++){
        tab[i] = i+1;
        chaine[i] = (char)(i+65);
    }
    chaine[TAILLE-1] = 0;
    free(chaine);
    free(tab);
    return 0;
}