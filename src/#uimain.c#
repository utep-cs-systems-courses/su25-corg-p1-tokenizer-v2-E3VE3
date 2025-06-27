#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"
int main() {
    char input[224];
    struct HistoryItem *history = NULL;
    int history_id = 1;

    while (1) {
        printf("$ ");
        fflush(stdout);
        if (!fgets(input, sizeof(input), stdin)) break;

        // Handle !N to recall command from history
        if (input[0] == '!' && input[1] != '\0') {
            int id = atoi(input + 1);
            struct HistoryItem *item = recall_history(history, id);
            if (!item) {
                printf("No such history item\n");
                continue;
            }
            printf("%s", item->str);
            strncpy(input, item->str, sizeof(input));
        }
        add_history(&history, history_id++, input); // Save command to history

        char **tokens = tokenize(input);  // Break input into tokens
        print_tokens(tokens);             // Show tokens
        free_tokens(tokens);              // Free memory
    }

    free_history(history); // Clean up
    return 0;
}