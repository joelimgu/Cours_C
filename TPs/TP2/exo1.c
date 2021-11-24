
#include <stdio.h>

#define COL 2
#define LINES 3

enum bool {false, true};

enum bool Saisie(int tab[LINES][COL], int col, int ln) {
    for (int i = 0; i<col; i++) {
        for (int j = 0; j<ln; j++) {
            int n = 0;
            scanf("%d",&n);
            tab[i][j] = n;
        }
    }
    return true;
}


enum bool Saisiep(int * tab, int lin, int col) {
    for (int i = 0; i<lin; i++) {
        for (int j = 0; j<col; j++) {
            int n = 0;
            scanf("%d",&n);
            *(tab +i*col + j) = n;
        }
    }
    return true;
}


void Affiche(int tab[LINES][COL]) {
    printf("[");
    for (int i = 0; i<LINES; i++) {
        if (i==0) printf("[");
        else printf(" [");
        for (int j = 0; j<COL; j++) {
            printf("%d, ",tab[i][j]);
        }
        if (i==LINES-1) printf("]");
        else printf("]\n");
    }
    printf("]\n");
}


int main() {
    int tab[LINES][COL];
    Saisiep(tab, LINES, COL);
    Affiche(tab);

    return 0;
}