
#include "stdio.h"

int contains( int * tab, int tab_size, int n) {
    for (int i=1;i<=tab_size;i++){
        if (tab[i] == n){ return 1; }
    }
    return 0;
}

char * empt(char * ln){
    for (int i=0;i<65;i++){
        ln[i] = ' ';
    }
    return ln;
}

char * replace_char2(char * ln, int * arr, int arr_size, char ch){
    ln[64] = '\0';
    if (!arr) return ln;
    for (int i=0;i<64;i++){
        if (contains(arr, arr[0],i)){ ln[i] = ch; }
    }
    return ln;
}

int main(){

    char lines[6][65];
    //    int * line_char[6][8]; // six lines 4 char types per line pointing to the arr with the char num
    // / len _ len \ len | len
    /// the index 0 specifies the size of the array -1 as it doesn't include itself
    int l1_l[] = {26,6,7,20,21,23,24,25,26,27,28,31,32,33,34,35,38,48,49,54,55,56,57,58,59,60,61};
    // forward_slash, lowdash, backslash, pipe
    int * line1[4] = {NULL, l1_l, NULL, NULL};

    int l2_f[] = {14,5,7,19,21,22,29,30,36,37,39,47,49,53,61};
    int l2_l[] = {13,24,25,32,33,34,35,48,55,56,57,58,59,60};
    int * line2[4] = {l2_f, l2_l, NULL, NULL};

    int l3_f[] = {14,4,6,18,20,21,23,26,28,29,31,36,38,52,54};
    int l3_l[] = {9,11,16,32,46,47,56,57,58,59};
    int * line3[4] = {l3_f, l3_l, NULL, NULL};

    int l4_f[] = {19,3,5,15,17,19,20,22,25,27,28,32,35,37,45,47,51,53,55,59};
    int l4_l[] = {5,11,30,31,56,57};
    int l4_b[] = {1,6};
    int l4_p[] = {2,10,12};
    int * line4[4] = {l4_f, l4_l, l4_b, l4_p};

    int l5_f[] = {20,2,4,7,14,16,18,19,21,24,26,27,29,34,36,44,46,50,52,56,58};
    int l5_l[] = {16,11,22,23,30,31,32,37,38,39,41,42,47,48,53,54,55};
    int l5_b[] = {2,5,7}; // 2
    int * line5[4] = {l5_f, l5_l, l5_b, NULL};

    int l6_f[] = {18,1,3,13,17,18,25,26,32,33,39,40,42,43,45,46,48,49,57};
    int l6_l[] = {32,2,7,11,14,15,16,19,20,21,22,23,24,27,28,29,30,31,34,35,36,37,38,41,44,47,50,51,52,53,54,55,56};
    int l6_b[] = {2,6,8};
    int l6_p[] = {2,10,12};
    int * line6[4] = {l6_f, l6_l, l6_b, l6_p};

    int ** lines_arr[6] =  {line1, line2, line3, line4, line5, line6};

    char c[4] = "/_\\|";
    for (int i = 0; i<6; i++) {
        char *ln=empt(lines[i]);
        for (int j=0;j<4;j++) {
            replace_char2(ln,lines_arr[i][j], -1, c[j]);
        }
    }
    for (int i = 0; i<6;i++){ printf("%s\n",lines[i]); }
    return 0;
}