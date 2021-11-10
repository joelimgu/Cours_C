
// this exo is not finished

#include <stdio.h>

struct S1 {
    int a;
    char * ch;
};

struct S2 {
    int a;
    char ch[40];
};

int main() {
    struct S1 v11, v12;
    struct S2 v21, v22;
    char str[] = "Hulk";
    v11.a = 3;
    v11.ch = str;
    v21.a = 5;
    v21.ch = "Gruik";
    return 0;
}