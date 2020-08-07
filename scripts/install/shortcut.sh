#!/usr/bin/env sh

echo "Set oWS = WScript.CreateObject(\"WScript.Shell\")" >> /tmp/CreateShortcut.vbs
echo "sLinkFile = \"$1\"" >> /tmp/CreateShortcut.vbs
echo "Set oLink = oWS.CreateShortcut(sLinkFile)" >> /tmp/CreateShortcut.vbs
echo "oLink.TargetPath = \"$2\"" >> /tmp/CreateShortcut.vbs
echo "oLink.Save" >> /tmp/CreateShortcut.vbs
cscript /tmp/CreateShortcut.vbs 
rm /tmp/CreateShortcut.vbs
