
#include <stdio.h>

int main(){
    int a = 1;
    int * pa = &a;
    *pa = 4;
    printf("%d,%d\n",a,*pa);
    return 0;
}