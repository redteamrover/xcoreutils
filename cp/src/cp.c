
#include "xcoreutils.h"

int _tmain(int argc, LPTSTR argv[])
{
    if (argc != 3) {
        return EXIT_FAILURE;
    }

    const LPTSTR original = argv[1];
    const LPTSTR duplicate = argv[2];

    if (CopyFile(original, duplicate, TRUE) == 0) {
        // TODO: Actually handle this via _strerror_s
        fprintf(stderr, "Error: %d\n", GetLastError());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
