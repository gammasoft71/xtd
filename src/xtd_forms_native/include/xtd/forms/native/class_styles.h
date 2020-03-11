#pragma once
#include <cstddef>

#ifndef CS_VREDRAW
constexpr size_t CS_VREDRAW = 0x00000001;
constexpr size_t CS_HREDRAW = 0x00000002;
constexpr size_t CS_DBLCLKS = 0x00000008;
constexpr size_t CS_OWNDC = 0x00000020;
constexpr size_t CS_CLASSDC = 0x00000040;
constexpr size_t CS_PARENTDC = 0x00000080;
constexpr size_t CS_NOCLOSE = 0x00000200;
constexpr size_t CS_SAVEBITS = 0x00000800;
constexpr size_t CS_BYTEALIGNCLIENT = 0x00001000;
constexpr size_t CS_BYTEALIGNWINDOW = 0x00002000;
constexpr size_t CS_GLOBALCLASS = 0x00004000;
constexpr size_t CS_IME = 0x00010000;
constexpr size_t CS_DROPSHADOW = 0x00020000;
#endif
