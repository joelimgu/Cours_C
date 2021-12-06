
#include <stdio.h>
#include "joel_macros.h"

void print_tab(int * tab, int size) {
    for (int i = 0; i < size; i++ ){
        printf("%d\n", tab[i]);
    }
}

void sort_tab(int * tab, int size) {
    enum bool sorted = true;
    do {
        sorted = true;
        for (int i = 0;i < size -1; i++ ) {
            if (tab[i] > tab[i+1]){
                int temp = tab[i+1];
                tab[i+1] = tab[i];
                printf("changed %d for %d\n",tab[i], temp);
                tab[i] = temp;
                sorted = false;
            }
        }
    } while (!sorted);
}


int main(){
    int tab[10] = {9,8,7,10,6,5,4,3,2,1};
    print_tab(tab, 10);
    sort_tab(mut tab,10);
    printf("-----------------------------------\n");
    print_tab(tab,10);
    return 0;
}