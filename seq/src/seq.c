
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    union {
        size_t setting[3];
        struct {
            size_t start;
            size_t step;
            size_t stop;
        };
    };
} parameters_t;

int main(int argc, char *argv[])
{
    parameters_t parameters;
    parameters.start = 1;
    parameters.step = 1;
    parameters.stop = 1;

    for (int i = argc - 1, j = 2; i != 0; --i, --j) {
        parameters.setting[j] = strtoul(argv[i], NULL, 10);
    }

    for (size_t i = parameters.start; i != parameters.stop + 1; i += parameters.step) {
        if (i != parameters.start) {
            fputc('\n', stdout);
        }

        printf("%zu", i);
    }

    return EXIT_SUCCESS;
}
