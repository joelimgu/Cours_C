
#include "stdio.h"

int contains( int * tab, int tab_size, int n) {
    for (int i=0;i<tab_size;i++){
        if (tab[i] == n){ return 1; }
    }
    return 0;
}

char * empty_line(char * ln){
    for (int i=0;i<65;i++){
        ln[i] = ' ';
    }
    return ln;
}

char * replace_char2(char * ln, int * arr, int arr_size, char ch){
    int i;
    for (i=0;i<64;i++){
        if (contains(arr, arr_size,i)){ ln[i] = ch; }
    }
    ln[64] = '\0';
    return ln;
}

int main(){
    // len of all lines is 65

    char lines[6][65];
//    int * line_char[6][8]; // six lines 4 char types per line pointing to the arr with the char num
    // / len _ len \ len | len

    int l1_lowdash[] = {6,7,20,21,23,24,25,26,27,28,31,32,33,34,35,38,48,49,54,55,56,57,58,59,60,61}; // 26
    int l2_forward_slash[] = {5,7,19,21,22,29,30,36,37,39,47,49,53,61}; // 14
    int l2_lowdash[] = {24,25,32,33,34,35,48,55,56,57,58,59,60}; // 13

    replace_char2(empty_line(lines[0]),l1_lowdash, 26, '_');

    replace_char2(empty_line(lines[1]), l2_forward_slash,14,'/');
    replace_char2(lines[1], l2_lowdash, 13,'_');

    int l3_forward_slash[] = {4,6,18,20,21,23,26,28,29,31,36,38,52,54}; // 14
    int l3_lowdash[] = {11,16,32,46,47,56,57,58,59}; // 9
    replace_char2(empty_line(lines[2]),l3_forward_slash, 14,'/');
    replace_char2(lines[2], l3_lowdash,9,'_');

    int l4_forward_slash[] = {3,5,15,17,19,20,22,25,27,28,32,35,37,45,47,51,53,55,59}; // 19
    int l4_lowdash[] = {11,30,31,56,57}; // 5
    int l4_backslash[] = {6}; // 1
    int l4_pipe[] = {10,12}; // 2
    replace_char2(empty_line(lines[3]),l4_forward_slash,19,'/');
    replace_char2(lines[3], l4_lowdash, 5,'_');
    replace_char2(lines[3], l4_backslash, 1,'\\');
    replace_char2(lines[3], l4_pipe, 2, '|');

    int l5_forward_slash[] = {2,4,7,14,16,18,19,21,24,26,27,29,34,36,44,46,50,52,56,58}; // 20
    int l5_lowdash[] = {11,22,23,30,31,32,37,38,39,41,42,47,48,53,54,55}; // 16
    int l5_backslash[] = {5,7}; // 2
    replace_char2(empty_line(lines[4]),l5_forward_slash,20,'/');
    replace_char2(lines[4], l5_lowdash, 16,'_');
    replace_char2(lines[4], l5_backslash, 2,'\\');

    int l6_forward_slash[] = {1,3,13,17,18,25,26,32,33,39,40,42,43,45,46,48,49,57}; // 18
    int l6_lowdash[] = {2,7,11,14,15,16,19,20,21,22,23,24,27,28,29,30,31,34,35,36,37,38,41,44,47,50,51,52,53,54,55,56}; // 32
    int l6_backslash[] = {6,8}; // 2
    int l6_pipe[] = {10,12}; // 2
    replace_char2(empty_line(lines[5]),l6_forward_slash,18,'/');
    replace_char2(lines[5], l6_lowdash, 32,'_');
    replace_char2(lines[5], l6_backslash, 2,'\\');
    replace_char2(lines[5], l6_pipe,2,'|');

    for (int i = 0; i<6;i++){ printf("%s\n",lines[i]); }
    return 0;
}