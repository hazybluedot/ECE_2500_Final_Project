#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getColor(int);

int main(int argc, char *argv[]) {

    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s value\n", argv[0]);
        exit(-1);
    }

    int val = strtol(argv[1], NULL, 10);
    if (val == 0) {
        printf("Please enter a valid resistor value\n");
        exit(-1);
    }

    if (val / 100000000 > 0) {
        printf("First Band: ");
        getColor(val/100000000);
        printf("Second Band: ");
        getColor(val/10000000 - (val/100000000 * 10));
        printf("Third Band: ");
        printf("Violet\n");
    }
    else if (val / 10000000 > 0) {
        printf("First Band: ");
        getColor(val/10000000);
        printf("Second Band: ");
        getColor(val/1000000 - (val/10000000 * 10));
        printf("Third Band: ");
        printf("Blue\n");
    }
    else if (val / 1000000 > 0) {
        printf("First Band: ");
        getColor(val/1000000);
        printf("Second Band: ");
        getColor(val/100000 - (val/1000000 * 10));
        printf("Third Band: ");
        printf("Green\n");
    }
    else if (val / 100000 > 0) {
        printf("First Band: ");
        getColor(val/100000);
        printf("Second Band: ");
        getColor(val/10000 - (val/100000 * 10));
        printf("Third Band: ");
        printf("Yellow\n");
    }
    else if (val / 10000 > 0) {
        printf("First Band: ");
        getColor(val/10000);
        printf("Second Band: ");
        getColor(val/1000 - (val/10000 * 10));
        printf("Third Band: ");
        printf("Orange\n");
    }
    else if (val / 1000 > 0) {
        printf("First Band: ");
        getColor(val/1000);
        printf("Second Band: ");
        getColor(val/100 - (val/1000 * 10));
        printf("Third Band: ");
        printf("Red\n");
    }
   else if (val / 100 > 0) {
        printf("First Band: ");
        getColor(val/100);
        printf("Second Band: ");
        getColor(val/10 - (val/100 * 10));
        printf("Third Band: ");
        printf("Brown\n");
    }
    else if (val / 1 > 0) {
        printf("First Band: ");
        getColor(val/10);
        printf("Second Band: ");
        getColor(val/1 - (val/10 * 10));
        printf("Third Band: ");
        printf("Black\n");
    }
}

void getColor(int i) {
    if(i == 0)
        printf("Black\n");
    else if (i == 1)
        printf("Brown\n");
    else if (i == 2)
        printf("Red\n");
    else if (i == 3)
        printf("Orange\n");
    else if (i == 4)
        printf("Yellow\n");
    else if (i == 5)
        printf("Green\n");
    else if (i == 6)
        printf("Blue\n");
    else if (i == 7)
        printf("Violet\n");
    else if (i == 8)
        printf("Grey\n");
    else if (i == 9)
        printf("White\n");
}
