@echo off

g++ efficient.cpp -std=c++17 -o efficient.exe
g++ naive.cpp -std=c++17 -o naive.exe
g++ generator.cpp -std=c++17 -o generator.exe

set i = 1

:loop
    echo %i%
    generator.exe %i% > input
    efficient.exe < input > out-efficient
    naive.exe < input > out-naive

    fc out-efficient out-naive
    if errorlevel 1 goto fail

    echo OK
    set /a i=%i% + 1
    goto loop

:fail
    echo Found failing test, check input for the test case where your solution fails!
    pause