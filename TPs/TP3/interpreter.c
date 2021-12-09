#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#define ASCII_MOINS 45
#define ASCII_SOMME 43
#define ASCII_MULT 42
#include "interpreter.h"
#include "command_list.h"
#include "symbol_list.h"

// returns true if two strings are equal ( deeps equals all characters must be in the same position )
enum bool compare_string(char * s1, char * s2) {
    int len1 = 0;
    int len2 = 0;
    while ( s1[len1] != '\0' ) len1++;
    while ( s2[len2] != '\0' ) len2++;

    if ( len1 != len2) return false;
    for ( int i = 0; i < len1; i++ ) {
        if ( s1[i] != s2[i] ) return false;
    }
    return true;
}


int numberOfDelimiters(char* string) {
    int count = 0;
    for (int i=0;i<strlen(string);i++) {
        if (string[i] == ' ') count++;
    }
    return count;
}


Programme* lexer(char* chaine) {
    char *token,*str;
    str = strdup(chaine);
    int i=0;
    int arraySize = (numberOfDelimiters(str)+1);
    char** programme = (char**)malloc(sizeof(char*)*arraySize);
    while ( (token = strsep(&str, " ")) ) {
        programme[i] = token;
        i++;
    }
    Programme *retour = (Programme*)malloc(sizeof(Programme));
    retour->tokens = programme;
    retour->taille = i;
    return retour;
}


void print_tokens(Programme * p) {
    char ** tokens = p->tokens;
    for (int i = 0; i< p->taille; i++) {
        printf("TOKEN : %s\n", tokens[i]);
    }
}


Value executer(Etat * mut etat) {
    Programme p = etat->p;
    Stack *s = &etat->s;
    Value v;
    v.val.Int = -1;
    v.type = Int;
    etat->mode = Execution;
//    enum bool are_we_in_string = false;
    for (int i = 1; i<=p.taille; i++) {
        char * token = p.tokens[i-1];
        Commande commande = search_token_function_pointer(etat->symbols, token);
        if ( compare_string(token, ".\"") ) {
            etat->mode = Printing;
        } else if ( compare_string(token, "\"" ) ) {
            etat->mode = Execution;
            printf("\n");

        } else if ( etat->mode == Printing ) {
            printf("%s ", token);

        } else if ( commande != NULL ) {

            commande(mut etat);
        } else {
            int type = 0; // 0<=> Int, 1<=> Float
            int j = 0;
            Value v;
            while (token[j] != '\0') {
                if ( token[j] == '.' ){ type = 1; }
                j++;
            }
            if ( type == 0) {
                v.val.Int = atoi(p.tokens[i-1]);
                v.type = Int;
            } else {
                v.val.Float = atof(p.tokens[i-1]);
                v.type = Float;
            }
            push(s, v); // we have a value
        }
    }
    Value res = s->len > 0 ? pop(s) : v;
    return res;
}