
#ifndef PROJECT_INCLUDES_XCOREUTILS_FILE_H
#define PROJECT_INCLUDES_XCOREUTILS_FILE_H

#ifndef PROJECT_INCLUDES_XCOREUTILS_H
#include "xcoreutils.h"
#endif

XCOREAPI FILE* __cdecl open_file(_In_ const char* filename);

XCOREAPI void __cdecl close_file(FILE** file);

#endif /** PROJECT_INCLUDES_XCOREUTILS_FILE_H */
