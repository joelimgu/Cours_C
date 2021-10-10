
#include "stdlib.h"
#include "stdio.h"

int sum(int * a, int b) {
    free(a);
    return *a+b;
}

int main(){
    int * p = malloc(sizeof(int));
    *p = 42;
    int b = sum(p,27);
    printf("Result: %d \n",b );
    return 0;
}