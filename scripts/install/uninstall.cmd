@echo off

if "%xtd_version%"== "" (
  echo ERROR : Use uninstall.cmd from root folder
  exit /B 1
)

echo Uninstall xtd libraries version %xtd_version%, copyright © 2024 Gammasoft

::______________________________________________________________________________
::                                                   Check if administrator mode
whoami /Groups | find "12288" > nul 2>&1
if %ERRORLEVEL% neq 0 (
  echo You are not in administrator mode!
  echo Run cmd as administrator before execute install.
  exit /B 1
)

echo.
echo ---------------------------------------------------------------
echo.
echo WARNING : You will unsinstall xtd!
echo.
echo ---------------------------------------------------------------
echo.
echo Press ENTER to continue or CTRL-C to stop...
pause > nul 2>&1

::______________________________________________________________________________
::                                                                Removing files
echo Removing files...
del /F /S /Q "%ProgramFiles(x86)%\wxwidgets" > nul 2>&1
del /F /S /Q "%ProgramFiles(x86)%\xtd" > nul 2>&1
del /F /S /Q "%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd" > nul 2>&1

echo.
echo xtd is uninstalled.
echo If you want to use xtd again, you will have to reinstall it.
