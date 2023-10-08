#include <stdio.h>
#include <math.h>

main() {

}

double atof(s) char s[]; {
    int i, c, decimal, exp;
    double out;

    for (i = decimal = exp = 0; (c = s[i]) != '\0'; ++i) {
        if (c - 48 < 10) {
            if (decimal == 0) {
                (out *= 10) += c - 48;
            } else if (decimal != 0) {
                out += (c - 48) / pow(10, decimal++);
            }
        } else if (c == '.' && decimal == 0) {
            ++decimal;
        } else if (c == 'e' || c == 'E') {

