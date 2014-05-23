#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

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

int  valueToColor(const char*);

void usage(FILE* fp, int status, const char* progname) {
    fprintf(fp, "Usage: %s value\n", progname);
    exit(status);
}

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

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    assert(COLOR_TABLE_LEN <= INT_MAX); /* sanity check */

    if (argc > 1) {
        ++argv; /* skip over program name */
        do {
            if (valueToColor(*argv) < 0) {
                usage(stderr, 1, argv[0]);
            }         
        } while(*++argv);
    } else {
        while((read = getline(&line, &len, stdin)) != -1) {
            line[read-1] = '\0';
            if (valueToColor(line) < 0) {
                usage(stderr, 1, argv[0]);
            }
        }
    }
    
    free(line);

    return 0;
}

int valueToColor(const char* str) {	
    char* endptr;
    int digits[3];
    int exp;
    double value;

    value = strtod(str, &endptr); /* convert string to double */
    
    frexp10(value, digits, &exp); /* extract digits of significand and exponent */
  
    printf("%s %s %s\n", getColor(digits[0]), getColor(digits[1]), getColor(exp-1)); /* convert each digit to a color value and print the result */
    return 0;
}

