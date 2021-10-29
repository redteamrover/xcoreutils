@ECHO OFF

FOR %%i IN (cat seq wc) DO (
    CHDIR %%i\src
    CL.EXE /nologo /TC /std:c17 /Wall /W4 /Oi /O2 /favor:AMD64 /arch:AVX512 /analyze /MD /GF /GS- /Fe%%i.exe /Fa%%i.asm %%i.c
    CHDIR ..\..\
)
