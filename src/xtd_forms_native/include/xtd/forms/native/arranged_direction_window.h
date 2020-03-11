#pragma once
#include <cstddef>

#ifndef ARW_BOTTOMLEFT
constexpr size_t ARW_BOTTOMLEFT = 0x0000L;
constexpr size_t ARW_BOTTOMRIGHT = 0x0001L;
constexpr size_t ARW_TOPLEFT = 0x0002L;
constexpr size_t ARW_TOPRIGHT = 0x0003L;
constexpr size_t ARW_STARTMASK = 0x0003L;
constexpr size_t ARW_STARTRIGHT = 0x0001L;
constexpr size_t ARW_STARTTOP = 0x0002L;

constexpr size_t ARW_LEFT = 0x0000;
constexpr size_t ARW_RIGHT = 0x0000L;
constexpr size_t ARW_UP = 0x0004L;
constexpr size_t ARW_DOWN = 0x0004L;
constexpr size_t ARW_HIDE = 0x0008L;
#endif

