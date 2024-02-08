@echo off
if exist "%~1" del "%~1"
:nextLine
   set line=
   set /P line=
   if not defined line goto endInput
   echo(%line%>> "%~1"
   echo(%line% 
   goto nextLine
:endInput
