#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <libgen.h>
#include <assert.h>
#include <errno.h>
#include <float.h>

#include "resistor.h"

int valueToColor(const char*);
double mstrtod(const char*, char**);

char progname[NAME_MAX];

void usage(FILE* fp, int status) {
    fprintf(fp, "Usage: %s [value...]\n", progname);
    exit(status);
}

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    strncpy(progname, basename(argv[0]), NAME_MAX);

    if (argc > 1) {
        ++argv; /* skip over program name */
        do {
            valueToColor(*argv);
        } while(*++argv);
    } else {
        while((read = getline(&line, &len, stdin)) != -1) {
            line[read-1] = '\0';
            valueToColor(line);
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

    value = mstrtod(str, &endptr); /* convert string to double */
    if ((errno == ERANGE && (value >= DBL_MAX || value <= DBL_MIN)) 
        || (errno != 0 && value == 0)) {
        perror("strtod");
        return value;
    }

    if (endptr == str) {
        fprintf(stderr, "No digits were found\n");
        return value;
    }

    if (value > 0) {
        frexp10(value, digits, &exp); /* extract digits of significand and exponent */
  
        printf("%s %s %s\n", getColor(digits[0]), getColor(digits[1]), getColor(exp-1)); /* convert each digit to a color value and print the result */
    }
    return value;
}

