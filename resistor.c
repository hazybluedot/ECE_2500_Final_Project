#include <stdio.h>
#include <stdlib.h>

double mstrtod(const char*, char**);

typedef struct {
    const char* color;
    int sig;
    double multiplier;
} colorcode_t;

static colorcode_t color_table[] = {
    { "black",  0,  1   },
    { "brown",  1,  1e1 },
    { "red",    2,  1e2 },
    { "orange", 3,  1e3 },
    { "yellow", 4,  1e4 },
    { "green",  5,  1e5 },
    { "blue",   6,  1e6 },
    { "violet", 7,  1e7 },
    { "grey",   8,  1e8 },
    { "white",  9,  1e9 },
};

#define COLOR_TABLE_LEN  sizeof(color_table)/sizeof(color_table[0])

const char* getColor(int i) {
    if ( (size_t)i >= COLOR_TABLE_LEN )
        return "\0";
    return color_table[i].color;
}

void frexp10(double x, int *digits, int *exp) {
    char s[10];
    
    snprintf(s, sizeof(s), "%.2E", x);
    digits[0] = s[0] - '0';
    digits[1] = s[2] - '0';
    digits[2] = s[3] - '0';
    
    *exp = strtol(s+6, NULL, 10);
}
