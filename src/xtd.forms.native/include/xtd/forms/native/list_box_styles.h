#pragma once
#include <cstddef>

#ifndef LBS_NOSEL
constexpr size_t LBS_NOTIFY = 0x0001;
constexpr size_t LBS_SORT = 0x0002;
constexpr size_t LBS_NOREDRAW = 0x0004;
constexpr size_t LBS_MULTIPLESEL = 0x0008;
constexpr size_t LBS_OWNERDRAWFIXED = 0x0010;
constexpr size_t LBS_OWNERDRAWVARIABLE = 0x0020;
constexpr size_t LBS_HASSTRINGS = 0x0040;
constexpr size_t LBS_USETABSTOPS = 0x0080;
constexpr size_t LBS_NOINTEGRALHEIGHT = 0x0100;
constexpr size_t LBS_MULTICOLUMN = 0x0200;
constexpr size_t LBS_WANTKEYBOARDINPUT = 0x0400;
constexpr size_t LBS_EXTENDEDSEL = 0x0800;
constexpr size_t LBS_DISABLENOSCROLL = 0x1000;
constexpr size_t LBS_NODATA = 0x2000;
constexpr size_t LBS_NOSEL = 0x4000;
constexpr size_t LBS_COMBOBOX = 0x8000;
#endif
