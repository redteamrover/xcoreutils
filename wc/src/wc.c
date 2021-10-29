/**
 * @file wc.c
 * @author Red Team Rover (redteamrover@protonmail.com)
 * @brief Re-write of the GNU wc utility for Windows
 * @version 0.1.0
 * @date 2021-10-29
 * 
 * @copyright Copyright (c) 2021
 * 
 * @todo Refactor function calls into dedicated library?
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

/**
 * @brief Entry point of the wc utility.
 * 
 * @param argc 
 * @param argv 
 * 
 * @return int 
 * 
 * @todo Implement command-line options
 * @todo Print characters upon request
 * @todo Count words in file
 * 
 */
int main(int argc, char *argv[])
{
    do {
        FILE* file = (argc == 1) ? stdin : open_file(*++argv);

        size_t chars = 0;
        size_t lines = 0;

        int c = 0;

        while ((c = fgetc(file)) != EOF) {
            ++chars;

            if ((lines == 0) || (c == '\n')) {
                ++lines;
            }
        }

        close_file(&file);

        printf("%zu", lines);
    } while (*(argv + 1));

    return EXIT_SUCCESS;
}
