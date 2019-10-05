#pragma once
#include <cstddef>

#ifndef IDOK
constexpr size_t IDOK = 1;
constexpr size_t IDCANCEL = 2;
constexpr size_t IDABORT = 3;
constexpr size_t IDRETRY = 4;
constexpr size_t IDIGNORE = 5;
constexpr size_t IDYES = 6;
constexpr size_t IDNO = 7;
constexpr size_t IDTRYAGAIN = 10;
constexpr size_t IDCONTINUE = 11;

constexpr size_t MB_OK = 0x00000000L;
constexpr size_t MB_OKCANCEL = 0x00000001L;
constexpr size_t MB_ABORTRETRYIGNORE = 0x00000002L;
constexpr size_t MB_YESNOCANCEL = 0x00000003L;
constexpr size_t MB_YESNO = 0x00000004L;
constexpr size_t MB_RETRYCANCEL = 0x00000005L;

constexpr size_t MB_ICONSTOP = 0x00000010L;
constexpr size_t MB_ICONERROR = 0x00000010L;
constexpr size_t MB_ICONHAND = 0x00000010L;
constexpr size_t MB_ICONQUESTION = 0x00000020L;
constexpr size_t MB_ICONEXCLAMATION = 0x00000030L;
constexpr size_t MB_ICONWARNING = 0x00000030L;
constexpr size_t MB_ICONINFORMATION = 0x00000040L;
constexpr size_t MB_ICONASTERISK = 0x00000040L;

constexpr size_t MB_DEFBUTTON1 = 0x00000000L;
constexpr size_t MB_DEFBUTTON2 = 0x00000100L;
constexpr size_t MB_DEFBUTTON3 = 0x00000200L;
constexpr size_t MB_DEFBUTTON4 = 0x00000300L;

constexpr size_t MB_APPLMODAL = 0x00000000L;
constexpr size_t MB_SYSTEMMODAL = 0x00001000L;
constexpr size_t MB_TASKMODAL = 0x00002000L;

constexpr size_t MB_HELP = 0x00004000L;

constexpr size_t MB_DEFAULT_DESKTOP_ONLY = 0x00020000L;
constexpr size_t MB_RIGHT = 0x00080000L;
constexpr size_t MB_RTLREADING = 0x00100000L;
constexpr size_t MB_SETFOREGROUND = 0x00010000L;
constexpr size_t MB_TOPMOST = 0x00040000L;
constexpr size_t MB_SERVICE_NOTIFICATION = 0x00200000L;

#endif
