
#include <stdio.h>
#include <stdlib.h>
#define MAXNAMELENGHT 255


struct Student {
    char * name;
    int year;
    int birth_year;
    int nb_of_marks;
    int *marks;
};


struct Student sasirFiche() {
    int input = 0;
    int max_notes = 0;
    struct Student student;

    int * marks = malloc(max_notes);
    student.marks = marks;
    char * name = malloc(MAXNAMELENGHT);

    printf("How many grades you have?\n");
    scanf("%i", &max_notes);
    student.nb_of_marks = max_notes;

    for (int i = 0; i < max_notes; i++) {
        printf("Insert the grades and press enter: \n");
        scanf("%i",&input);
        student.marks[i] = input;
    }

    printf("Insert the student's year\n");
    scanf("%i",&input);
    student.year = input;

    printf("Insert the student's birth year\n");
    scanf("%i",&input);
    student.birth_year = input;

    printf("Insert the student's name\n");
    scanf("%s", name);
    student.name = name;
    return student;
}

void AfficherFiche(struct Student *st ) {
    printf("Name: %s\n", st->name);
    printf("It's in the %d year\n", st->year);
    printf("It was born on %d\n", st->birth_year);
    printf("Grades: ");
    for (int i = 0; i < st->nb_of_marks; i++) {
        printf(" %d ", st->marks[i]);
    }
    printf(" ;\n");
}

float moyenne(struct Student *st) {
    int somme = 0;
    if (st->nb_of_marks < 0 ) return 0;

    for (int i = 0; i < st->nb_of_marks; i++ ) {
        somme += st->marks[i];
    }
    printf("here\n");
    return somme/((float) st->nb_of_marks);

}

int main() {
    struct Student st = sasirFiche();
    AfficherFiche(&st);
    printf("Moy: %f\n", moyenne(&st));
    return 0;
}