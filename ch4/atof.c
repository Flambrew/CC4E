#include <stdio.h>

main() {
    double atof();
    printf("1234.5678e9\n");
    printf("%.5f\n", atof("1234.5678e9"));
}

double atof(s) char s[]; {
    unsigned int i, c, decimal, exp;
    double out, power();

    for (i = decimal = exp = 0; (c = s[i]) != '\0'; ++i) {
        if (c - 48 < 10) {
            printf("a\n");
            if (exp != 0) {
                decimal = decimal * 10 + c - 48;
            } else if (decimal == 0) {
                out = out * 10 + c - 48;
            } else if (decimal != 0) {
                out += (c - 48) / power(10, decimal++);
            }
        } else if (c == '.' && decimal == 0) {
            printf("b\n");
            ++decimal;
        } else if (c == 'e' || c == 'E') {
            printf("c\n");
            ++exp;
        } else { return 0; }
        printf("%.5f\n\n", out);
    }
    return out * power(10, exp);
}

double power(a, b) double a; int b; {
    double temp;
    for (temp = 1; b > 0; --b) {
        temp *= a;
    }
    return temp;
}
