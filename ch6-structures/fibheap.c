#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct binheap {
    int size;
    struct node *arr[63];
};

struct node {
    int value;
};

void insert(struct binheap *heap, struct node *new) {
    heap->arr[heap->size] = new;
    ++heap->size;
}

int getMin(struct binheap *heap) {
    return heap->arr[0] != NULL ? heap->arr[0]->value : NULL;
}

void extractMin(struct binheap *heap) {

}

void decreaseKey(struct binheap *heap) {

}

