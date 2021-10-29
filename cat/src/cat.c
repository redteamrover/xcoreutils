/**
 * "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
 * cl /nologo /TC /std:c17 /Wall /W4 /Oi /O2 /favor:AMD64 /arch:AVX512 /analyze /MD /GF /GS- /Fecat.exe /Facat.asm cat.c
 *
 */

#include "xcoreutils.h"

int _tmain(int argc, LPTSTR argv[])
{
    /** TODO: Implement the ability to read from stdin */
    if (argc == 1) {
        return EXIT_FAILURE;
    }

    static CHAR read_buffer[BUFFER_SIZE] = { 0 };

    do {
        HANDLE input_file = CreateFile(*++argv, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);

        if (input_file == INVALID_HANDLE_VALUE) {
            fprintf(stderr, "%x\n", GetLastError());
            return EXIT_FAILURE;
        }

        DWORD bytes_read = 0;

        while (ReadFile(input_file, read_buffer, BUFFER_SIZE, &bytes_read, NULL) && (bytes_read)) {
            fprintf(stdout, "%s", read_buffer);
        }

        CloseHandle(input_file);
    } while (*(argv + 1));

    return EXIT_SUCCESS;
}
