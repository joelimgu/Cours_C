
#include <stdio.h>
#include <stdlib.h>

#define LIN 2
#define COL 3

struct Taille {
    int ln;
    int col;
};


enum bool {false, true};

int ** reserve(int col, int ln) {
    int ** tab = malloc(sizeof(int *)*ln);
    for (int i = 0; i<ln; i++) {
        tab[i] = malloc(sizeof(int)*col);
    }
    return tab;
}


enum bool Saisie(int **tab, int ln, int col) {
    for (int i = 0; i<ln; i++) {
        for (int j = 0; j<col; j++) {
            int n = 0;
            scanf("%d",&n);
            *(*(tab + i) + j) = n; // c'est des pointeurs il ne faut pas faire le calcul
            printf("rempli %p avec %d\n",*(tab + i) + j, n);
        }
    }
    return true;
}


void Affichep(int **tab, int ln, int col) {
    printf("[");
    for ( int i = 0; i<ln; i++) {
        if (i == 0) printf("[");
        else printf(" [");
        for ( int j = 0; j<col; j++) {
            printf("%p, ", *(tab + i) + j);
        }
        if ( i==ln-1 ) printf("]");
        else printf("]\n");
    }
    printf("]\n");
}


void Affiche(int **tab, int ln, int col) {
    printf("[");
    for ( int i = 0; i<ln; i++) {
        if (i == 0) printf("[");
        else printf(" [");
        for ( int j = 0; j<col; j++) {
            printf("%d, ", *(*(tab + i) + j));
        }
        if ( i==ln-1 ) printf("]");
        else printf("]\n");
    }
    printf("]\n");
}


struct Taille Init(int *** tab) {
    int ln = 0;
    int col = 0;
    printf("LN: ");
    scanf("%d", &ln);
    printf("\nCol: ");
    scanf("%d", &col);

    *tab = reserve(col, ln);
    struct Taille t = {ln: ln, col: col};
    return t;
}

int main(){
    int ** tab = reserve(COL,LIN);
    int ** tab2;

    Saisie(tab,LIN,COL);
    Affichep(tab,LIN,COL);
    Affiche(tab,LIN,COL);

    printf("---------------TAB2-------------------\n");
    struct Taille t = Init(&tab2);
    Saisie(tab2,t.ln, t.col);
    Affiche(tab2, t.ln, t.col);


    // free........ in your dreams
    return 0;
}