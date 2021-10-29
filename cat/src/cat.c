/**
 * "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" amd64
 * cl /nologo /TC /std:c17 /Wall /W4 /Oi /O2 /favor:AMD64 /arch:AVX512 /analyze /MD /GF /GS- /Fecat.exe /Facat.asm cat.c
 *
 */

#include "xcoreutils.h"

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
