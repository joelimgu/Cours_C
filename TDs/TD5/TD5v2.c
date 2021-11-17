
#include <stdio.h>
#define MAX_LEN 1024
enum bool {false, true};

enum bool EcritFichier(char * nom_fich_lire, char * nom_fich_ecrit, int nb_lignes) {
    FILE * fich_lect = fopen(nom_fich_lire,"r");

    FILE * fw = fopen(nom_fich_ecrit,"w");
//    if (f != NULL) return false;

    printf("Copying content to: %s \n ", nom_fich_ecrit);
    // on suppose que le nb de lignes donné est correct
    for (int i = 0; i<nb_lignes; i++) {
        char ln[MAX_LEN];
        fgets(ln,MAX_LEN,fich_lect);
        fputs(ln, fw);
    }
    fclose(fw);
    fclose(fich_lect);
    return true;
}


int main() {
    char nom_r[MAX_LEN];
    char nom_w[MAX_LEN];
    printf("Write the name of the file to read:\n");
    scanf("%s", nom_r);
    printf("Write the name of the new file:\n");
    scanf("%s", nom_w);
    EcritFichier(nom_r, nom_w, 10);
    return 0;
}