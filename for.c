
#include <stdio.h>

int main(){
    int a = 0;
    int i = 0;
    for(int i = 0; i<2; i++){
        a = i+1;
    }
    printf("i:%d , a: %d\n",i,a);
    return 0;
}