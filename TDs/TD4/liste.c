
#include <stdio.h>
#include <stdlib.h>

struct Cellule {
    struct Cellule * suiv;
    int val;
};

struct Cellule * empty_list() {
    return NULL;
}

void append(struct Cellule **l, int n) {
    struct Cellule * s = malloc(sizeof(struct Cellule));
    s->suiv = NULL;
    s->val = n;

    if (*l == NULL) {
        *l = s;
    } else {
        struct Cellule * cell = *l;
        while (cell->suiv != NULL) {
            cell = cell->suiv;
        }
        cell->suiv = s;
    }
}

void pop_first(struct Cellule ** l) {
    struct Cellule * aux = *l;
    if (*l != NULL) {
        *l = (*l)->suiv;
        free(*l);
    }
}

void display_first(struct Cellule * l) {
    printf("%d\n", l->val);
}

void display_last(struct Cellule * l) {
    if (l->suiv == NULL) {
        printf("%d\n", l->val);
    } else {
        display_last(l->suiv);
    }

}

int len(struct Cellule *l) {
    int res = 0;
    while ( l != NULL ) {
        res++;
        l = l->suiv;
    }
    return res;
}

int is_empty(struct Cellule *l) {
    return l == NULL;
}


int main() {
    struct Cellule * l1 = empty_list();
    append(&l1, 1);
    append(&l1, 2);
    append(&l1, 3);
    display_first(l1);
    display_last(l1);
    printf("len: %d\n",len(l1));
    printf("empty: %d\n", is_empty(l1));
    return 0;
}