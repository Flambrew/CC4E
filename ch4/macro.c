#include <stdio.h>

#define swap(x, y) {int z = x; x = y; y = z;}

main() {
    int x = 0, y = 1;
    printf("%d, %d\n", x, y);
    swap(x, y);
    printf("%d, %d\n", x, y);
}
