#include <stdio.h>

main() {}

getbits(x, p, n) unsigned x, p, n; {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

getbitslr(x, p, n) unsigned x, p, n; {
    unsigned l;
    for (l = 0; x >> l != 0; ++l);
    return (x >> (l - p - n)) & ~(~0 << n);
}

wordlength() {
    unsigned int i, l;
    for (i = ~(l = 0); i >>= 1 != 0; ++l);
    return ++l;
}

rightrot(n, b) unsigned n, b; {
    return (n >> b) | (n & ~(~0 << b)) << (wordlength() - b);
}

invert(x, p, n) unsigned x, p, n; {
    return x ^ (~(~0 << n) << (p + 1 - n));
}
