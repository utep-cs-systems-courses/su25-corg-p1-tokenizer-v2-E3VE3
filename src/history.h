#ifndef HISTORY_H
#define HISTORY_H

struct HistoryItem {
    int id;
    char *str;
    struct HistoryItem *next;
};

void add_history(struct HistoryItem **head, int id, char *str);
void print_history(struct HistoryItem *head);
struct HistoryItem *recall_history(struct HistoryItem *head, int id);
void free_history(struct HistoryItem *head);

#endif
