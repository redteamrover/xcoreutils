
#ifndef PROJECT_INCLUDES_XCOREUTILS_H
#define PROJECT_INCLUDES_XCOREUTILS_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <Windows.h>
#include <tchar.h>

#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef LINKAGE_SPEC
#if defined(__cplusplus)
#define LINKAGE_SPEC extern "C"
#else
#define LINKAGE_SPEC
#endif
#endif

#ifndef XCOREAPI_INTERNAL
#define XCOREAPI LINKAGE_SPEC __declspec(dllimport)
#else
#define XCOREAPI LINKAGE_SPEC __declspec(dllexport)
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (8096)
#endif

#include "xcoreutils/file.h"

#endif /** PROJECT_INCLUDES_XCOREUTILS_H */
