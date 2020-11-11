#pragma once
#include <cstddef>

#ifndef TCS_SCROLLOPPOSITE
constexpr size_t TCS_SCROLLOPPOSITE = 0x0001; // assumes multiline tab
constexpr size_t TCS_BOTTOM = 0x0002;
constexpr size_t TCS_RIGHT = 0x0002;
constexpr size_t TCS_MULTISELECT = 0x0004; // allow multi-select in button mode
constexpr size_t TCS_FLATBUTTONS = 0x0008;
constexpr size_t TCS_FORCEICONLEFT = 0x0010;
constexpr size_t TCS_FORCELABELLEFT = 0x0020;
constexpr size_t TCS_HOTTRACK = 0x0040;
constexpr size_t TCS_VERTICAL = 0x0080;
constexpr size_t TCS_TABS = 0x0000;
constexpr size_t TCS_BUTTONS = 0x0100;
constexpr size_t TCS_SINGLELINE = 0x0000;
constexpr size_t TCS_MULTILINE = 0x0200;
constexpr size_t TCS_RIGHTJUSTIFY = 0x0000;
constexpr size_t TCS_FIXEDWIDTH = 0x0400;
constexpr size_t TCS_RAGGEDRIGHT = 0x0800;
constexpr size_t TCS_FOCUSONBUTTONDOWN = 0x1000;
constexpr size_t TCS_OWNERDRAWFIXED = 0x2000;
constexpr size_t TCS_TOOLTIPS = 0x4000;
constexpr size_t TCS_FOCUSNEVER = 0x8000;
#endif
