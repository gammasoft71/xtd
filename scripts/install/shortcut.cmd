@echo off
rem if "%1" == "" goto usage
rem if "%2" == "" goto usage
echo Set oWS = WScript.CreateObject("WScript.Shell") > %temp%\CreateShortcut.vbs
echo sLinkFile = %1 >> %temp%\CreateShortcut.vbs
echo Set oLink = oWS.CreateShortcut(sLinkFile) >> %temp%\CreateShortcut.vbs
echo oLink.TargetPath = %2 >> %temp%\CreateShortcut.vbs
echo oLink.Save >> %temp%\CreateShortcut.vbs
cscript %temp%\CreateShortcut.vbs 
del %temp%\CreateShortcut.vbs
goto end

:usage
echo shortcut link target
echo   link shortcut file to create
echo   target target file with relative or absolute path

:end