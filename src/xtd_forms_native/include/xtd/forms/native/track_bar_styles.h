#pragma once
#include <cstddef>

#ifndef TBS_AUTOTICKS
constexpr size_t TBS_AUTOTICKS = 0x0001;
constexpr size_t TBS_VERT = 0x0002;
constexpr size_t TBS_HORZ = 0x0000;
constexpr size_t TBS_TOP = 0x0004;
constexpr size_t TBS_BOTTOM = 0x0000;
constexpr size_t TBS_LEFT = 0x0004;
constexpr size_t TBS_RIGHT = 0x0000;
constexpr size_t TBS_BOTH = 0x0008;
constexpr size_t TBS_NOTICKS = 0x0010;
constexpr size_t TBS_ENABLESELRANGE = 0x0020;
constexpr size_t TBS_FIXEDLENGTH = 0x0040;
constexpr size_t TBS_NOTHUMB = 0x0080;
constexpr size_t TBS_TOOLTIPS = 0x0100;
constexpr size_t TBS_REVERSED = 0x0200;  // Accessibility hint: the smaller number (usually the min value) means "high" and the larger number (usually the max value) means "low"
constexpr size_t TBS_DOWNISLEFT = 0x0400;  // Down=Left and Up=Right (default is Down=Right and Up=Left)
constexpr size_t TBS_NOTIFYBEFOREMOVE = 0x0800;  // Trackbar should notify parent before repositioning the slider due to user action (enables snapping)
constexpr size_t TBS_TRANSPARENTBKGND = 0x1000;  // Background is painted by the parent via WM_PRINTCLIENT
#endif
