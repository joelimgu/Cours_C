
#include <stdio.h>

int main(int argc, char * argv[]){
    printf("nb d'args: %d \n",argc);
    printf("%s \n",argv[0]);
    if (argc != 3){
        fprintf(stderr,"%s : We DO NOT have 3 args \n", argv[0]);
        return 1;
    }
    printf("We have 3 args \n");
    return 0;
}