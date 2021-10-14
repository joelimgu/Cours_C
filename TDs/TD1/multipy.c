
#include <stdio.h>


int main(){
    int val = 5;
    printf("a = %d\n",val);
    val = val << 1;
    printf("a * 2 = %d\n",val);

    // int = 4octets
    unsigned int a = 0x55555555;
    unsigned int b = 0x99999999;
    unsigned int c = 0;
    // 2 bit poids fort en bin 4 octets = 1100 --> 0xF0
    c = (a & 0xFFFF0000) | (b & 0x0000FFFF);

    printf("HEX (a): %x\n", a);
    printf("HEX (b): %x\n", b);
    printf("HEX (c): %x\n", c);

    a = 0x11223344;
    b = 0x11223144;
//    b = 0x11223344;
    printf("10eme bit test:  %x\n", (a ^b ) == (1 << 9));
    return 0;
}


/*
 * 0001 --> 1 --> 0010 --> 2 --> on a decalé
 * 0010 --> 2 --> 0100 --> 4 --> on a decalé
 * 0101 --> 5 --> 1010 --> 5 -->
 * 0011 --> 3 --> 0110 --> 6 -->
 */