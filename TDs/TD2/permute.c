
#include <stdio.h>

void permute(int * a, int * b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a = 5;
    int b = 10;
    printf("a: %d, b: %d \n",a,b);
    permute(&a,&b);
    printf("a: %d, b: %d \n",a,b);

    return 0;
}