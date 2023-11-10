#include <stdio.h>

struct date { 
    int day;
    int month;
    int year;
    int yearday;
    char mon_name[3];
};

static int day_table[2][12] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(struct date *date) {
    int day = date->day, year = date->year;
    int leap = !(year%4) && year%100 || !(year%400);

    for (int i = 0; i < date->month - 1; ++i) {
        day += day_table[leap][i];
    }

    return day;
}

int main() {
    struct date d = { 4, 7, 1776, 182, "JUL" };

    printf("%s %d, %d\n", d.mon_name, d.day, d.year);

    return 0;
}