
#ifndef PROJECT_INCLUDES_XCOREUTILS_FILE_H
#define PROJECT_INCLUDES_XCOREUTILS_FILE_H

#ifndef PROJECT_INCLUDES_XCOREUTILS_H
#include "xcoreutils.h"
#endif

XCOREAPI FILE* open_file(_In_ const char* filename);

XCOREAPI void close_file(FILE** file);

#endif /** PROJECT_INCLUDES_XCOREUTILS_FILE_H */
