@echo off
setlocal

echo Abriendo mp3...

g++ main.cpp nucleo\*.cpp clases\*.cpp estructuras\*.cpp -o main.exe

if %errorlevel% neq 0 (
    echo.
    echo Build failed.
    pause
    exit /b %errorlevel%
)

echo mp3 Abierto...
if exist main.exe (
    echo Ejecutando main.exe...
    main.exe
) else (
    echo main.exe no encontrado.
)

echo.
pause
endlocal
