
#ifndef XCOREAPI_INTERNAL
#define XCOREAPI_INTERNAL
#endif

#include "xcoreutils.h"

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
