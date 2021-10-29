@ECHO OFF

CHDIR cat\src
CL.EXE /nologo /TC /std:c17 /Wall /W4 /Oi /O2 /favor:AMD64 /arch:AVX512 /analyze /MD /GF /GS- /Fecat.exe /Facat.asm cat.c
CHDIR ..\..\
