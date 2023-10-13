#include <stdio.h>

#define STACKDEPTH 100

static int stackpointer = 0;
static double val[STACKDEPTH];

double push(f) double f; {
    if (stackpointer < STACKDEPTH) return val[stackpointer++] = f;
    else {
        printf("err: stack full\n");
        clear();
        return 0;
    }
}

double pop() {
    if (stackpointer > 0) return val[--stackpointer];
    else {
        printf("err: stack empty\n");
        clear();
        return 0;
    }
}

clear() {
    stackpointer = 0;
}
