#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getColor1and2(int);
void getColor3(long);
int  valueToColor(const char*);

int main(int argc, char *argv[]) {

    if ( argc != 2 ) {
        fprintf(stderr, "Usage: %s value\n", argv[0]);
        exit(-1);
    }

	if (valueToColor(argv[1]) < 0) {
        printf("Please enter a valid resistor value\n");
		exit(-1);
	}
	return 0;
}


int valueToColor(const char* str) {	
    char* end;
    long val = strtol(str, &end, 10);
    int digit1 = str[0] - '0';
    int digit2 = str[1] - '0';
    if ( *end != '\0') {
        exit(-1);
    }

    if (val < 10 || val > 9900000000) {
        printf("Please enter a resistor value between 10 and 9900000000\n");
		return -1;
    }

    printf("First Band: ");
    getColor1and2(digit1);
    printf("Second Band: ");
    getColor1and2(digit2);
    printf("Third Band: ");
    getColor3(val);
	return 0;
}

void getColor1and2(int i) {
    if (i == 0)
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

void getColor3(long i) {
    if (i / 100000000 > 0)
        printf("Violet\n");
    else if (i / 10000000 > 0)
        printf("Blue\n");
    else if (i / 1000000 > 0)
        printf("Green\n");
    else if (i / 100000 > 0)
        printf("Yellow\n");
    else if (i / 10000 > 0)
        printf("Orange\n");
    else if (i / 1000 > 0)
        printf("Red\n");
    else if (i / 100 > 0)
        printf("Brown\n");
    else if (i / 10 > 0)
        printf("Black\n");
}
