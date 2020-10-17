:: cmd

:: run registered unit tests
::cd build
::ctest --output-on-failure --build-config Debug
::if %ERRORLEVEL% NEQ 0 exit 1
::cd ..
