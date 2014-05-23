#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>

typedef struct {
    char   sym;
    double mult;
} metric_sym_t;

static metric_sym_t mult_table[] = {
    { 'n', 1e-9 },
    { 'u', 1e-6 },
    { 'c', 1e-3 },
    { 'k', 1e3  },
    { 'M', 1e6  },
    { 'G', 1e9  },
};

#define METRIC_SYM_TABLE_SIZE sizeof(mult_table)/sizeof(mult_table[0])

metric_sym_t* find_symbol(char c) {
    int n;
    metric_sym_t* ptr;

    ptr = mult_table;

    for(n = 0; n < METRIC_SYM_TABLE_SIZE; ++n, ++ptr) {
        if ( c == ptr->sym ) {
            return ptr;
        }
    }
    return NULL;
}

double mstrtod(const char* nptr, char** endptr) {
    double val;
    metric_sym_t* symptr;

    errno = 0;
    val = strtod(nptr, endptr);
    
    if ((errno == ERANGE && (val == DBL_MAX || val == DBL_MIN)) 
        || (errno != 0 && val == 0)) {
        return val;
    }

    if (*endptr == nptr) {
        return val;
    }

    if ((symptr = find_symbol(**endptr)) != NULL) {
        ++*endptr;
        val *= symptr->mult;
    }
    
    return val;
}
