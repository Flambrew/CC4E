#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 1000

struct treenode
{
    int val;
    struct treenode *less;
    struct treenode *more;
};

void add(struct treenode *head, struct treenode *add)
{
    if (add->val < head->val)
        if (head->less != NULL)
            head->less = add;
        else
            add(head->less, add);
    else if (head->more != NULL)
        head->more = add;
    else
        add(head->more, add);
}

bool remove(struct treenode *head, struct treenode *remove) {
    
}

void main() {
    struct treenode *head = {"1", NULL, NULL};


}