/**
 * "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
 * cl /nologo /TC /std:c17 /Wall /W4 /Oi /O2 /favor:AMD64 /arch:AVX512 /analyze /MD /GF /GS- /Fecat.exe /Facat.asm cat.c
 *
 */

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

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (512)
#endif

static char error_msg_buffer[BUFFER_SIZE] = { 0 };

FILE* open_file(_In_ const char* filename) {
    _set_errno(0);

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        _strerror_s(error_msg_buffer, BUFFER_SIZE, NULL);

        switch (errno) {
            default: {
                fprintf(stderr, "Could not open file: %s (%s)\n", filename, error_msg_buffer);
                exit(EXIT_FAILURE);
            } break;
        }        
    }

    return file;
}

void close_file(FILE** file) {
    if (file == NULL) {
        return;
    }

    fclose(*file);

    *file = NULL;
}

int main(int argc, char *argv[])
{
    do {
        FILE* file = (argc == 1) ? stdin : open_file(*++argv);

        int c = 0;

        while ((c = fgetc(file)) != EOF) {
            fputc(c, stdout);
        }

        fputc('\n', stdout);

        close_file(&file);
    } while (*(argv + 1));

    return EXIT_SUCCESS;
}
