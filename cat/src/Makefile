
all : cat.exe

cat.exe : file.lib cat.c
	CL /nologo /TC /std:c17 /Wall /W4 /Oi /O2 /favor:AMD64 /arch:AVX2 /analyze /MD /Gd /GF /GS- cat.c /Fe:cat.exe /I"C:\Users\jflop\Projects\xcoreutils\lib\include" /link file.lib
