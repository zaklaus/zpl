echo zpl.h generated.
#/bin/bash 2>nul || goto :windows
python3 code/zpl/build.py
exit

:windows
@echo off
python.exe code\zpl\build.py