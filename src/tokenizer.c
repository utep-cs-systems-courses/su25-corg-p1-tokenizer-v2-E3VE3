#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c) {          //Returns true if there is a space or tab
    return c == ' ' || c == '\t';
}

int non_space_char(char c) {      //Returns true if no spaces   
    return !space_char(c) && c != '\0';
}

char *token_start(char *s) {      //finds the beggining of the next token(If space theres token)  
    while (*s && space_char(*s)) s++;
    return *s ? s : NULL;
}

char *token_terminator(char *token) { //finds the end of token
    while (*token && non_space_char(*token)) token++;
    return token;
}

int count_tokens(char *s) { 
    int count = 0;
    for (char *p = token_start(s); p; p = token_start(token_terminator(p)))
        count++;
    return count;
}

// Copy part of string into new memory
char *copy_str(char *inStr, short len) {
    char *copy = malloc(len + 1);
    if (!copy) return NULL;
    for (int i = 0; i < len; i++) copy[i] = inStr[i];
    copy[len] = '\0';
    return copy;
}

char **tokenize(char *s) {
    int count = count_tokens(s);
    char **tokens = malloc((count + 1) * sizeof(char *));
    if (!tokens) return NULL;

    char *p = token_start(s);
    for (int i = 0; i < count; i++) {
        char *end = token_terminator(p);
        tokens[i] = copy_str(p, end - p);
        p = token_start(end);
    }
    tokens[count] = NULL;
    return tokens;
}

void print_tokens(char **tokens) {
    for (int i = 0; tokens[i]; i++)
        printf("token[%d]: %s\n", i, tokens[i]);
}

void free_tokens(char **tokens) {
    for (int i = 0; tokens[i]; i++) free(tokens[i]);
    free(tokens);
}
