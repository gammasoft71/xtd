#pragma once
#include <cstddef>

constexpr size_t IDNONE = 0;
#ifndef IDOK
constexpr size_t IDOK = 1;
constexpr size_t IDCANCEL = 2;
constexpr size_t IDABORT = 3;
constexpr size_t IDRETRY = 4;
constexpr size_t IDIGNORE = 5;
constexpr size_t IDYES = 6;
constexpr size_t IDNO = 7;
constexpr size_t IDCLOSE = 8;
constexpr size_t IDHELP = 9;
constexpr size_t IDTRYAGAIN = 10;
constexpr size_t IDCONTINUE = 11;
#endif

#ifndef IDTIMEOUT
constexpr size_t IDTIMEOUT = 32000;
#endif
