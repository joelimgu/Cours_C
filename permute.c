//
// Created by joel on 20/9/21.
//
#include <stdio.h>

void permute(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a = 1;
    int b = 2;
    printf("%d %d \n", a,b);
    permute(&a,&b);
    printf("%d %d \n", a,b);
}