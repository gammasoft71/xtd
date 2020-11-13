#pragma once
#include <cstddef>

#if !defined(PROGDLG_NORMAL)
constexpr size_t PROGDLG_NORMAL = 0x00000000;
constexpr size_t PROGDLG_MODAL = 0x00000001;
constexpr size_t PROGDLG_AUTOTIME = 0x00000002;
constexpr size_t PROGDLG_NOTIME = 0x00000004;
constexpr size_t PROGDLG_NOMINIMIZE = 0x00000008;
constexpr size_t PROGDLG_NOPROGRESSBAR = 0x00000010;
constexpr size_t PROGDLG_MARQUEEPROGRESS = 0x00000020;
constexpr size_t PROGDLG_NOCANCEL = 0x00000040;
#endif
constexpr size_t PROGDLG_NOSKIP = 0x00000080;
constexpr size_t PROGDLG_SMOOTH = 0x00000100;
constexpr size_t PROGDLG_SMOOTH_REVERSE = 0x00000200;
constexpr size_t PROGDLG_ELAPSEDTIME = 0x00000400;
constexpr size_t PROGDLG_ESTIMATEDTIME = 0x00000800;
