@echo off
set xtd_program_path=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\xtd
if not exist "%xtd_program_path%" mkdir "%xtd_program_path%"
rem mklink "%xtd_program_path%\xtdc-gui" "%USERPROFILE%\local\xtd\bin\xtdc-gui.exe"
call shortcut.bat "%xtd_program_path%\xtdc-gui.lnk" "%USERPROFILE%\local\xtd\bin\xtdc-gui.exe"
