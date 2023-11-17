#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

struct listnode
{
    char *text;
    struct listnode *prev;
    struct listnode *next;
};

int main()
{
    struct listnode *head = NULL;
    struct listnode *tail = NULL;
    struct listnode *curr = head;
    char line[MAXLEN];

    while (fgets(line, MAXLEN, stdin) != NULL)
    {
        char *save = (char *)malloc(strlen(line) + 1);
        strcpy(line, save); // copy save into line

        struct listnode *new = (struct listnode *)
            malloc(sizeof(struct listnode));
        new->text = save;
        new->next = NULL;
        new->prev = tail;

        if (head == NULL)
            head = new;
        if (tail != NULL)
            tail->next = new;
        tail = new;
    }

    for (curr = tail; curr != NULL; curr = curr->prev)
    {
        printf("%s", curr->text);
    }
}