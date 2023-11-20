#include <stdbool.h>
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode *prev;
    struct ListNode *next;
} NODE;

typedef struct LinkedList {
    int length;
    NODE *head;
    NODE *tail;
} LIST;

LIST *newList() {
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list != NULL) {
        list->length = 0;
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

bool isEmpty(LIST *list) { return list == NULL || list->length == 0; }

int size(LIST *list) { return list == NULL ? -1 : list->length; }

int indexOf(LIST *list, int value) {
    if (list == NULL)
        return -1;
    NODE *curr = list->head;
    for (int i = 0; curr != NULL; ++i, curr = curr->next)
        if (curr->value == value)
            return i;
    return -1;
}

bool contains(LIST *list, int value) {
    if (list == NULL)
        return false;
    for (NODE *curr = list->head; curr != NULL; curr = curr->next)
        if (curr->value == value)
            return true;
    return false;
}

bool add(LIST *list, int value) {
    return list == NULL ? false : addIndex(list, value, list->length);
}

bool addIndex(LIST *list, int value, int n) {
    if (list == NULL || n < 0 || n > list->length)
        return false;
    NODE *node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL)
        return false;
    if (isEmpty(list) || n == 0) {
        node->prev = NULL;
        node->next = list->head;
        if (isEmpty(list))
            list->tail = node;
        else
            list->head->prev = node;
        list->head = node;
    } else if (n == list->length) {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    } else {
        NODE *curr = list->head;
        for (int i = 0; curr != NULL && i != n; i++)
            curr = curr->next;
        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;
    }
    node->value = value;
    list->length++;
    return true;
}

bool remove(LIST *list, int value) {
    if (list == NULL)
        return false;
    int i = indexOf(list, value);
    if (i == -1)
        return false;
    removeIndex(list, i);
    return true;
}

int removeIndex(LIST *list, int n) {
    if (n < 0 || n >= list->length)
        return -1;
    int value;
    if (n == 0) {
        value = list->head->value;
        if (size(list) == 1) {
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
        } else {
            NODE *temp = list->head;
            list->head = list->head->next;
            list->head->prev = NULL;
            free(temp);
        }
    } else if (n == list->length - 1) {
        NODE *temp = list->tail;
        value = list->tail->value;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(temp);
    } else {
        NODE *curr = list->head;
        for (int i = 0; curr != NULL && i != n; i++)
            curr = curr->next;
        value = curr->value;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
    list->length--;
    return value;
}

int get(LIST *list, int n) {
    if (list == NULL || n < 0 || n >= list->length)
        return -1;
    NODE *curr = list->head;
    while (n-- > 0)
        curr = curr->next;
    return curr->value;
}

bool set(LIST *list, int value, int n) {
    if (list == NULL || n < 0 || n >= list->length)
        return false;
    NODE *curr = list->head;
    while (n-- > 0)
        curr = curr->next;
    curr->value = value;
    return true;
}