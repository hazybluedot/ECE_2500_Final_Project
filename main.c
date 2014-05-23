#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* getColor1and2(int);
const char* getColor3(long);
int  valueToColor(const char*);

void usage(FILE* fp, int status, const char* progname) {
    fprintf(fp, "Usage: %s value\n", progname);
    exit(status);
}

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

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
    char* end;
    long val = strtol(str, &end, 10);
    int digit1 = str[0] - '0';
    int digit2 = str[1] - '0';
    if ( *end != '\0') {
        return -1;
    }

    if (val < 10 || val > 9900000000) {
        return -1;
    }

    printf("%s %s %s\n", getColor1and2(digit1), getColor1and2(digit2), getColor3(val));
    return 0;
}

const char* getColor1and2(int i) {
    if (i == 0)
        return "black";
    else if (i == 1)
        return "brown";
    else if (i == 2)
        return "red";
    else if (i == 3)
        return "orange";
    else if (i == 4)
        return "yellow";
    else if (i == 5)
        return "green";
    else if (i == 6)
        return "blue";
    else if (i == 7)
        return "violet";
    else if (i == 8)
        return "grey";
    else if (i == 9)
        return "white";
    else 
        return "xxx";
}

const char* getColor3(long i) {
    if (i / 100000000 > 0)
        return "violet";
    else if (i / 10000000 > 0)
        return "blue";
    else if (i / 1000000 > 0)
        return "green";
    else if (i / 100000 > 0)
        return "yellow";
    else if (i / 10000 > 0)
        return "orange";
    else if (i / 1000 > 0)
        return "red";
    else if (i / 100 > 0)
        return "brown";
    else if (i / 10 > 0)
        return "black";
    else
        return "xxx";
}
