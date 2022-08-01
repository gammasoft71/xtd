@echo off

if "%xtd_version%"== "" (
  echo "ERROR : Use install.cmd from root folder"
  exit /B 1
)

set WXWIDGETS_VERSION=v3.2.0

echo Install xtd libraries version %xtd_version%, copyright Gammasoft, 2022
echo.

echo   Operating System is Windows

:: check if administrator mode
whoami /Groups | find "12288" > nul 2>&1
if %ERRORLEVEL% neq 0 (
  echo You are not in administrator mode!
  echo Run cmd as administrator before executing install.
  exit /B 1
)

echo Downloading and installing wxwidgets...
mkdir build\3rdparty
cd build\3rdparty
git clone https://github.com/wxWidgets/wxWidgets.git -b %WXWIDGETS_VERSION% --depth 1
cd wxwidgets
git submodule update --init
cd..
mkdir wxwidgets\build_cmake
cd wxwidgets\build_cmake
cmake .. -DwxBUILD_SHARED=OFF %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..\..\..\..

:: generate, build and install xtd
echo Installing xtd...
mkdir build
cd build
cmake .. %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

:: create gui tools shortcut in system operating applications
set xtd_program_path=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd
if not exist "%xtd_program_path%" mkdir "%xtd_program_path%"
call scripts\install\shortcut.cmd "%xtd_program_path%\keycode.lnk" "%ProgramFiles(x86)%\xtd\bin\keycode.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\xtdc-gui.lnk" "%ProgramFiles(x86)%\xtd\bin\xtdc-gui.exe"
call scripts\install\shortcut.cmd "%xtd_program_path%\guidgen-gui.lnk" "%ProgramFiles(x86)%\xtd\bin\guidgen-gui.exe"

:: add xtdc-gui path
echo.%path%|findstr /C:"xtd\bin" >nul 2>&1
if not errorlevel 1 (
  echo The environment variable path already contains xtd.
) else (
  set path=%ProgramFiles(x86)%\xtd\bin;%path%
  call :strlen path_length path
  if  %path_length% LSS 1024 (
    setx path "%path%"
  ) else (
    echo.
    echo ---------------------------------------------------------------
    echo.
    color 47
    echo WARNING
    echo -------
    color
    echo.
    echo The path is greater than 1024. setx will not work correctly with a path greater than 1024.
    echo Manually add "%ProgramFiles(x86)%\xtd\bin" in your path.
    echo.
    echo ---------------------------------------------------------------
    pause
  )
)

:: launch xtdc-gui
echo Launching xtdc-gui...
start "xtdc-gui" "%ProgramFiles(x86)%\xtd\bin\xtdc-gui.exe"

goto :eof

:: -----------------------------------------------------------------------
:: Gets the length of specified string.
:: param result_var That will cantains the length of the specified string.
:: param string_var The string to compute length.
:strlen <result_var> <string_var> (   
  setlocal EnableDelayedExpansion
  (set^ tmp=!%~2!)
  if defined tmp (
    set "len=1"
    for %%P in (4096 2048 1024 512 256 128 64 32 16 8 4 2 1) do (
      if "!tmp:~%%P,1!" NEQ "" ( 
        set /a "len+=%%P"
        set "tmp=!tmp:~%%P!"
      )
    )
  ) else (
    set len=0
  )
)
( 
  endlocal
  set "%~1=%len%"
  exit /b
)
