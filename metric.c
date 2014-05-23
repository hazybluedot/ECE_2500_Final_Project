#include <stdio.h>
#include <stdlib.h>

double mstrtod(char*, char **);

int main(int argc, char * argv[]) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    double value;
    char *endptr;
    const char* fmt = "%.0f";

    while ((read = getline(&line, &len, stdin)) != -1) {
        line[read-1] = '\0';
        value = mstrtod(line, &endptr);
        if (endptr != line) {
            printf(fmt, value);
            putchar('\n');
            if (endptr != '\0')
                fprintf(stderr, "remaining string: %s\n", endptr);
        } else {
            fprintf(stderr, "%s: out of range\n", line);
        }
    }

    free(line);
    exit(EXIT_SUCCESS);
}
