#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#define ASCII_MOINS 45
#define ASCII_SOMME 43
#define ASCII_MULT 42
#include "interpreter.h"

//
//typedef struct Programme {
//    char **tokens;
//    int taille;
//} Programme;
//
//
//typedef struct {
//    Stack s;
//    Programme p;
//} Etat;
//
//union Test {
//    int ValEntier;
//    float ValReel;
//};
//
//int numberOfDelimiters(char* string) {
//    int count = 0;
//    for (int i=0;i<strlen(string);i++) {
//        if (string[i] == ' ') count++;
//    }
//    return count;
//}
//
//
//Programme* lexer(char* chaine) {
//    char *token,*str;
//    str = strdup(chaine);
//    int i=0;
//    int arraySize = (numberOfDelimiters(str)+1);
//    char** programme = (char**)malloc(sizeof(char*)*arraySize);
//    while ( (token = strsep(&str, " ")) ) {
//        programme[i] = token;
//        i++;
//    }
//    Programme *retour = (Programme*)malloc(sizeof(Programme));
//    retour->tokens = programme;
//    retour->taille = i;
//    return retour;
//}
//
//
//void print_tokens(Programme * p) {
//    char ** tokens = p->tokens;
//    for (int i = 0; i< p->taille; i++) {
//        printf("TOKEN : %s\n", tokens[i]);
//    }
//}
//
//
//void executer(Etat *etat) {
//    Programme p = etat->p;
//    Stack s = etat->s;
//    int a,b;
//    for (int i = 1; i<=p.taille; i++) {
//        printf("init loop: ");
//        print_stack(&s);
//
//        switch ((int)p.tokens[i-1][0]) {
//            case ASCII_SOMME:
//                print_stack(&s);
//                b = pop(&s);
//                a = pop(&s);
//                push(&s, a + b);
//                printf("%d + %d = %d\n", a , b, a+b );
//                continue;
//            case ASCII_MULT:
//                print_stack(&s);
//                b = pop(&s);
//                a = pop(&s);
//                push(&s, a * b);
//                printf("%d * %d = %d\n", a , b, a*b );
//                continue;
//            case ASCII_MOINS:
//                print_stack(&s);
//                b = pop(&s);
//                a = pop(&s);
//                push(&s, a - b);
//                printf("%d - %d = %d\n", a , b, a-b );
//                continue;
//            default: // we have a value
//                push(&s, atoi(p.tokens[i-1]));
//        }
//    }
//    printf("SORTIE : %d\n", pop(&s));
//}
//
//
//void test_forth() {
//    Programme * p = lexer("3 5 + 4 2 - *");
//    print_tokens(p);
//    Etat e = {s: *create_empty_stack(), p: *p};
//    executer(&e);
//}


int main() {
    Programme * p = lexer("3 5 + 4 2 - *");
    print_tokens(p);
    Etat e = {s: *create_empty_stack(), p: *p};
    int res = executer(&e);
    printf("%d\n",res);
    return 0;
}