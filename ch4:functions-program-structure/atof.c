#include <stdio.h>

double atof(s) char s[]; {
    unsigned int i, c, decimal, exp;
    double out, power();

    for (i = decimal = exp = 0; (c = s[i]) != '\0'; ++i) {
        if (c - 48 < 10) {
            if (exp != 0) {
                decimal = decimal * 10 + c - 48;
            } else if (decimal == 0) {
                out = out * 10 + c - 48;
            } else if (decimal != 0) {
                out += (c - 48) / power(10, decimal++);
            }
        } else if (c == '.' && decimal == 0) {
            ++decimal;
        } else if (exp == 0 && (c == 'e' || c == 'E')) {
            decimal = ++exp - 1;
        } else { return 0; }
    }
    return (out * power(10, decimal));
}

double power(a, b) int a, b; {
    double temp;
    for (temp = 1; b > 0; --b) {
        temp *= a;
    }
    return temp;
}
