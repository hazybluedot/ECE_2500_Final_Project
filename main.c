#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* getColor1and2(int);
const char* getColor3(long);

int main(int argc, char *argv[]) {

    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s value\n", argv[0]);
        exit(-1);
    }

    char* end;
    long val = strtol(argv[1], &end, 10);
    int digit1 = argv[1][0] - '0';
    int digit2 = argv[1][1] - '0';
    if ( *end != '\0') {
        printf("Please enter a valid resistor value\n");
        exit(-1);
    }

    if (val < 10 || val > 9900000000) {
        printf("Please enter a resistor value between 10 and 9900000000\n");
        exit(-1);
    }

    printf("%s %s %s\n", getColor1and2(digit1), getColor1and2(digit2), getColor3(val));
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
