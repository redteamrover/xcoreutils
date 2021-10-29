@ECHO OFF

FOR %%i IN (cat seq wc) DO (
    CHDIR %%i\src
    DEL %%i.exe %%i.nativecodeanalysis.xml %%i.obj %%i.asm
    CHDIR ..\..\
)
