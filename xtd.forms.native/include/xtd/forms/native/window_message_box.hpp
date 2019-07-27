#pragma once

#ifndef IDOK
constexpr int IDOK = 1;
constexpr int IDCANCEL = 2;
constexpr int IDABORT = 3;
constexpr int IDRETRY = 4;
constexpr int IDIGNORE = 5;
constexpr int IDYES = 6;
constexpr int IDNO = 7;
constexpr int IDTRYAGAIN = 10;
constexpr int IDCONTINUE = 11;

constexpr int MB_OK = 0x00000000L;
constexpr int MB_OKCANCEL = 0x00000001L;
constexpr int MB_ABORTRETRYIGNORE = 0x00000002L;
constexpr int MB_YESNOCANCEL = 0x00000003L;
constexpr int MB_YESNO = 0x00000004L;
constexpr int MB_RETRYCANCEL = 0x00000005L;

constexpr int MB_ICONSTOP = 0x00000010L;
constexpr int MB_ICONERROR = 0x00000010L;
constexpr int MB_ICONHAND = 0x00000010L;
constexpr int MB_ICONQUESTION = 0x00000020L;
constexpr int MB_ICONEXCLAMATION = 0x00000030L;
constexpr int MB_ICONWARNING = 0x00000030L;
constexpr int MB_ICONINFORMATION = 0x00000040L;
constexpr int MB_ICONASTERISK = 0x00000040L;

constexpr int MB_DEFBUTTON1 = 0x00000000L;
constexpr int MB_DEFBUTTON2 = 0x00000100L;
constexpr int MB_DEFBUTTON3 = 0x00000200L;
constexpr int MB_DEFBUTTON4 = 0x00000300L;

constexpr int MB_APPLMODAL = 0x00000000L;
constexpr int MB_SYSTEMMODAL = 0x00001000L;
constexpr int MB_TASKMODAL = 0x00002000L;

constexpr int MB_HELP = 0x00004000L;

constexpr int MB_DEFAULT_DESKTOP_ONLY = 0x00020000L;
constexpr int MB_RIGHT = 0x00080000L;
constexpr int MB_RTLREADING = 0x00100000L;
constexpr int MB_SETFOREGROUND = 0x00010000L;
constexpr int MB_TOPMOST = 0x00040000L;
constexpr int MB_SERVICE_NOTIFICATION = 0x00200000L;

#endif
