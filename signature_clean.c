
#include "stdio.h"

#define clone(struct) struct
#define mut(a) a
#define owned(a) mut(a)

enum bool {false, true};

struct int_arr{
    int len;
    int * value;
};

struct line {
    int len;
    char value[65];
};

enum bool contains( struct int_arr * tab, int n) {
    int i;
    for (i=0;i<tab->len;i++){
        if (tab->value[i] == n){ return true; }
    }
    return false;
}

struct line empty_line(){
    struct line ln;
    ln.len = 65;
    int i;
    for (i=0;i<ln.len;i++){
        ln.value[i] = ' ';
    }
    return ln;
}

void print_line(struct line * ln){
    for (int i = 0; i< ln->len; i++){
        printf("%c",ln->value[i]);
    }
    printf("\n");
}

// &mut line; &arr; owned char
struct line * replace_char(struct line * ln, struct int_arr * arr, char ch){
    int i;
    for (i=0;i<ln->len - 1;i++){
        if (contains(arr,i)){
            ln->value[i] = ch;
        }
    }
    ln->value[ln->len-1] = '\0';
    return ln;
}


// we pass by value so ok (ln.clone() owned); &arr non mut
struct line build_lowdash(struct line ln, struct int_arr * arr) {
    return *replace_char(&mut(ln), arr, '_');
}

// pass by value, ln is owned, &arr
struct line build_forward_slash(struct line ln, struct int_arr * arr) {
    return *replace_char(&mut(ln), arr, '/');
}

// pass by value, ln is owned, &arr
struct line build_backslash(struct line ln, struct int_arr * arr) {
    return *replace_char(&mut(ln), arr, '\\');
}

// pass by value, ln is owned, &arr
struct line build_pipe(struct line ln, struct int_arr * arr) {
    return *replace_char(&mut(ln), arr, '|');
}

int main(){
    int l1_lowdash[] = {6,7,20,21,23,24,25,26,27,28,31,32,33,34,35,38,48,49,54,55,56,57,58,59,60,61};
    struct int_arr lowdash_ln1 = {
        len: 26,
        value: l1_lowdash
    };
    int l2_forward_slash[] = {5,7,19,21,22,29,30,36,37,39,47,49,53,61};
    struct int_arr forward_slash_ln2 = {
        len: sizeof(l2_forward_slash)/sizeof(int),
        value: l2_forward_slash
    };
    int l2_lowdash[] = {24,25,32,33,34,35,48,55,56,57,58,59,60};
    struct int_arr lowdash_ln2 = {
            len: sizeof(l2_lowdash)/sizeof(int),
            value: l2_lowdash
    };

    int l3_forward_slash[] = {4,6,18,20,21,23,26,28,29,31,36,38,52,54};
    struct int_arr forward_slash_ln3 = {
            len: sizeof(l3_forward_slash)/sizeof(int),
            value: l3_forward_slash
    };
    int l3_lowdash[] = {11,16,32,46,47,56,57,58,59};
    struct int_arr lowdash_ln3 = {
            len: sizeof(l3_lowdash)/sizeof(int),
            value: l3_lowdash
    };

    // +++++++++++++++ FOUR 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int l4_forward_slash[] = {3,5,15,17,19,20,22,25,27,28,32,35,37,45,47,51,53,55,59};
    struct int_arr forward_slash_ln4 = {
            len: sizeof(l4_forward_slash)/sizeof(int),
            value: l4_forward_slash
    };
    int l4_lowdash[] = {11,56,57};
    struct int_arr lowdash_ln4 = {
            len: sizeof(l4_lowdash)/sizeof(int),
            value: l4_lowdash
    };
    int l4_backslash[] = {6};
    struct int_arr backslash_ln4 = {
            len: sizeof(l4_backslash)/sizeof(int),
            value: l4_backslash
    };
    int l4_pipe[] = {10,12};
    struct int_arr pipe_ln4 = {
            len: sizeof(l4_pipe)/sizeof(int),
            value: l4_pipe
    };

    // +++++++++++++++ FIVE 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int l5_forward_slash[] = {2,4,7,14,16,18,19,21,24,26,27,29,34,36,44,46,50,52,56,58};
    struct int_arr forward_slash_ln5 = {
            len: sizeof(l5_forward_slash)/sizeof(int),
            value: l5_forward_slash
    };
    int l5_lowdash[] = {11,22,23,30,31,32,37,38,39,41,42,47,48,53,54,55};
    struct int_arr lowdash_ln5 = {
            len: sizeof(l5_lowdash)/sizeof(int),
            value: l5_lowdash
    };
    int l5_backslash[] = {5,7};
    struct int_arr backslash_ln5 = {
            len: sizeof(l5_backslash)/sizeof(int),
            value: l5_backslash
    };
    
    // +++++++++++++++ SIX 6 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    int l6_forward_slash[] = {1,3,13,17,18,25,26,32,33,39,40,42,43,45,46,48,49,57};
    struct int_arr forward_slash_ln6 = {
            len: sizeof(l6_forward_slash)/sizeof(int),
            value: l6_forward_slash
    };
    int l6_lowdash[] = {2,7,11,14,15,16,19,20,21,22,23,24,27,28,29,30,31,34,35,36,37,38,41,44,47,50,51,52,53,54,55,56};
    struct int_arr lowdash_ln6 = {
            len: sizeof(l6_lowdash)/sizeof(int),
            value: l6_lowdash
    };
    int l6_backslash[] = {6,8};
    struct int_arr backslash_ln6 = {
            len: sizeof(l6_backslash)/sizeof(int),
            value: l6_backslash
    };
    int l6_pipe[] = {10,12};
    struct int_arr pipe_ln6 = {
            len: sizeof(l6_pipe)/sizeof(int),
            value: l6_pipe
    };


    struct line line1 = build_lowdash(owned(empty_line()),&lowdash_ln1);
    struct line line2 = build_lowdash(owned(empty_line()), &lowdash_ln2);
    line2 = build_forward_slash(owned(line2), &forward_slash_ln2);
    struct line line3 = build_forward_slash(owned(empty_line()),&forward_slash_ln3);
    line3 = build_lowdash(owned(line3), &lowdash_ln3);
    struct line line4 = build_forward_slash(owned(empty_line()),&forward_slash_ln4);
    line4 = build_lowdash(owned(line4), &lowdash_ln4);
    line4 = build_backslash(owned(line4), &backslash_ln4);
    line4 = build_pipe(owned(line4), &pipe_ln4);
    struct line line5 = build_forward_slash(owned(empty_line()),&forward_slash_ln5);
    line5 = build_lowdash(owned(line5), &lowdash_ln5);
    line5 = build_backslash(owned(line5), &backslash_ln5);
    struct line line6 = build_forward_slash(owned(empty_line()),&forward_slash_ln6);
    line6 = build_lowdash(owned(line6), &lowdash_ln6);
    line6 = build_backslash(owned(line6), &backslash_ln6);
    line6 = build_pipe(owned(line6), &pipe_ln6);
    
    print_line(&line1);
    print_line(&line2);
    print_line(&line3);
    print_line(&line4);
    print_line(&line5);
    print_line(&line6);
    return 0;
}