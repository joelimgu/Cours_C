
#include <stdio.h>
#include "interpreter.h"
#include "symbol_list.h"
#include "command_list.h"

#define ANSI_COLOR_GREEN_BOLD "\e[1;32m"
#define ANSI_COLOR_RED_BOLD "\e[1;31m"
#define Color_end "\33[0m" // To flush out prev settings

enum bool assert_int(char * mes, int value, int expected) {
    if ( value == expected ) {
        printf( "    - "ANSI_COLOR_GREEN_BOLD "OK    %s\n" Color_end, mes );
        return true;
    } else {
        printf("    - "ANSI_COLOR_RED_BOLD "ERR! %s.\n Expected: %d But got: %d" Color_end, mes, expected, value);
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


Value test_program(char * s) {
    Programme * p = lexer(s);
    char noms[][10] = {"DROP", "DUP", "SWAP", "ROT", "+", "-", "*", ".", ".S"};
    Commande commands[] = {drop, dup, swap, rot, sum, subtract, multiply, pop_and_print, print_stack_from_etat};
    SymbolList *l2 = init_symbol_list(noms, commands, 9); // add 1 for every addition
    Etat e = {s: *create_empty_stack(), p: *p,Execution, l2};
    return executer(&e);
}

void test_forth() {
    assert_int("3 5 +", test_program("3 5 +").val.Int, 8);
    assert_int("3 5 + 4 2 -", test_program("3 5 + 4 2 -").val.Int, 2);
    assert_int("3 10 +", test_program("3 10 +").val.Int, 13);
    assert_int("3 5 + 4 2 - *", test_program("3 5 + 4 2 - *").val.Int, 16);
    assert_int("3.5 3 +", test_program("3.5 3 +").val.Float, 6.5);
    assert_int("3.5 3 + 4 2 - *", test_program("3.5 3 + 4 2 - *").val.Float, 13.0);


    assert_int("1 2 + DUP *", test_program("1 2 + DUP *").val.Int,9 );
    assert_int("1 2 DROP", test_program("1 2 DROP").val.Int,1 );
    assert_int("2 3 SWAP -", test_program("2 3 SWAP -").val.Int,1 );
    assert_int("3 2 1 ROT", test_program("3 2 1 ROT").val.Int,3 );
    assert_int("printed bonjour tout le monde? ^", test_program(".\" bonjour tout le monde \"").val.Int, -1 );
    assert_int("printed + operation", test_program(".\" bonjour tout le monde \" 3 5 +").val.Int, 8 );

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
    SymbolList *l2 = init_symbol_list(noms, commands, 4);
    assert_int("Init symbol list", search_token(l2, "ROT"), 3);

    assert_pointer("Search function using token", search_token_function_pointer(l2, "DUP"), dup);
    assert_pointer("Search function using token", search_token_function_pointer(l2, "ROT"), rot);
    assert_int("pop and print 5 6 . .", test_program("5 6 . .").val.Int, -1 );
    assert_int("print stack 5 6 .S", test_program("5 6 .S ").val.Int, 0 );

}

int main() {
    test_forth();
    test_symbol_list();
    // free ...
    return 0;
}