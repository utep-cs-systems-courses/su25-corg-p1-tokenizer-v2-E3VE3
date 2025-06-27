#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

// Add a new item to the end of the history list
void add_history(struct HistoryItem **head, int id, char *str) {
    struct HistoryItem *new_item = malloc(sizeof(struct HistoryItem));
    new_item->id = id;
    new_item->str = strdup(str);
    new_item->next = NULL;

    if (!*head) {
        *head = new_item;
    } else {
        struct HistoryItem *cur = *head;
        while (cur->next) cur = cur->next;
        cur->next = new_item;
    }
}

void print_history(struct HistoryItem *head) {
    while (head) {
        printf("%d: %s", head->id, head->str);
        head = head->next;
    }
}

// Find item by its ID
struct HistoryItem *recall_history(struct HistoryItem *head, int id) {
    while (head && head->id != id) head = head->next;
    return head;
}

// Free all history items
void free_history(struct HistoryItem *head) {
    while (head) {
        struct HistoryItem *temp = head->next;
        free(head->str);
        free(head);
        head = temp;
    }
}