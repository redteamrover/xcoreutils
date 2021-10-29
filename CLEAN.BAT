@ECHO OFF

FOR %%i IN (cat wc) DO (
    CHDIR %%i\src
    DEL %%i.exe %%i.nativecodeanalysis.xml %%i.obj %%i.asm
    CHDIR ..\..\
)
