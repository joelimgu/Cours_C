
#include <stdio.h>
#include "interpreter.h"
#include "symol_list.h"
#include "command_list.h"

#define ANSI_COLOR_GREEN_BOLD "\e[1;32m"
#define ANSI_COLOR_RED_BOLD "\e[1;31m"
#define Color_end "\33[0m" // To flush out prev settings

enum bool assert_int(char * mes, int value, int expected) {
    if ( value == expected ) {
        printf( "    - "ANSI_COLOR_GREEN_BOLD "OK    %s\n" Color_end, mes );
        return true;
    } else {
        printf("    - "ANSI_COLOR_RED_BOLD "ERR! %s.\n Expected: %d. But got: %d" Color_end, mes, expected, value);
        return false;
    }
}


enum bool assert_pointer(char * mes, void *value, void *expected) {
    if ( value == expected ) {
        printf( "    - "ANSI_COLOR_GREEN_BOLD "OK    %s\n" Color_end, mes );
        return true;
    } else {
        printf("    - "ANSI_COLOR_RED_BOLD "ERR! %s.\n      Expected: %p. But got: %p" "\n" Color_end, mes, expected, value);
        return false;
    }
}


int test_program(char * s) {
    Programme * p = lexer(s);
    Etat e = {s: *create_empty_stack(), p: *p};
    return executer(&e);
}

void test_forth() {
    assert_int("3 5 +", 8, test_program("3 5 +"));
    assert_int("3 5 + 4 2 -", 2, test_program("3 5 + 4 2 -"));
    assert_int("3 10 +", 13, test_program("3 10 +"));
    assert_int("3 5 + 4 2 - *", 16, test_program("3 5 + 4 2 - *"));
}

void test_symbol_list() {
    SymbolList *l = empty_list();
    assert_pointer("Create empty symbol list",l, NULL);
    add_entry(&l, "DROP", drop);
    assert_pointer("Add entry DROP next",l->next, NULL);
    assert_pointer("Add entry DROP func pointer",l->val.func, drop);

    add_entry(&l, "DUP", dup);
    assert_pointer("Add entry DUP next",l->next->next, NULL);
    assert_pointer("Add entry DUP func pointer",l->next->val.func, dup);

    assert_int("Compare strings true", compare_string("Hello", "Hello"), true);
    assert_int("Compare strings false", compare_string("asdf", "Hello"), false );

    assert_int("Search token pos1", search_token(l, "DROP"), 0);
    assert_int("Search token pos2", search_token(l, "DUP"), 1);

    char noms[][10] = {"DROP", "DUP", "SWAP", "ROT"};
    Commande commands[] = {drop, dup, swap, rot };
    SymbolList *l2 = init_symbol_list(noms, commands, 2);
    assert_int("Init symbol list", search_token(l2, "DUP"), 1);

}

int main() {
    test_forth();
    test_symbol_list();
    // free ...
    return 0;
}