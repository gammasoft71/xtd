@echo off
setlocal enabledelayedexpansion

::______________________________________________________________________________
::                                                                 Check context
if "%xtd_version%"== "" (
  echo ---------------------------------------------------------------
  echo ERROR : Use uninstall.cmd from the root folder!
  echo ---------------------------------------------------------------
  exit /B 1
)

echo Uninstalling xtd libraries version %xtd_version%, copyright © 2025 Gammasoft
echo.

::______________________________________________________________________________
::                                                   Check if administrator mode
whoami /Groups | find "12288" > nul 2>&1
if %ERRORLEVEL% neq 0 (
  echo ---------------------------------------------------------------
  echo ERROR : You are not in administrator mode!
  echo Please run cmd as administrator before executing uninstall.
  echo ---------------------------------------------------------------
  exit /B 1
)

::______________________________________________________________________________
::                                                   Optional parameter --silent
set silent=
if /I "%1"=="--silent" (
  set silent=1
  shift
)

::______________________________________________________________________________
::                                                                  User warning
if not defined silent (
  echo ---------------------------------------------------------------
  echo WARNING : This will completely uninstall xtd.
  echo ---------------------------------------------------------------
  echo Press ENTER to continue or CTRL-C to cancel...
  pause > nul
)

::______________________________________________________________________________
::                                                                Removing files
echo Removing files...
rd /S /Q "%ProgramFiles(x86)%\wxwidgets" > nul 2>&1
rd /S /Q "%ProgramFiles(x86)%\xtd" > nul 2>&1
rd /S /Q "%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd" > nul 2>&1

::______________________________________________________________________________
::                                                            Cleaning variables
echo Cleaning environment variables...
reg delete "HKCU\Environment" /v XTD_ROOT_PATH /f > nul 2>&1
reg delete "HKCU\Environment" /v XTD_TOOLKIT_PATH /f > nul 2>&1

:: WARNING : Do not attempt to modify PATH directly via script to avoid 
::           incorrect deletions.


::______________________________________________________________________________
::                                                                 Final message
echo.
echo ---------------------------------------------------------------
echo xtd has been successfully uninstalled.
echo If you want to reinstall it, just run install.cmd again.
echo ---------------------------------------------------------------

endlocal
