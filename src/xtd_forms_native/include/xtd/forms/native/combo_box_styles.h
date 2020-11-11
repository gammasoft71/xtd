#pragma once
#include <cstddef>

#ifndef CBS_SIMPLE
constexpr size_t CBS_SIMPLE = 0x0001L;
constexpr size_t CBS_DROPDOWN = 0x0002L;
constexpr size_t CBS_DROPDOWNLIST = 0x0003L;
constexpr size_t CBS_OWNERDRAWFIXED = 0x0010L;
constexpr size_t CBS_OWNERDRAWVARIABLE = 0x0020L;
constexpr size_t CBS_AUTOHSCROLL = 0x0040L;
constexpr size_t CBS_OEMCONVERT = 0x0080L;
constexpr size_t CBS_SORT = 0x0100L;
constexpr size_t CBS_HASSTRINGS = 0x0200L;
constexpr size_t CBS_NOINTEGRALHEIGHT = 0x0400L;
constexpr size_t CBS_DISABLENOSCROLL = 0x0800L;
constexpr size_t CBS_UPPERCASE = 0x2000L;
constexpr size_t CBS_LOWERCASE = 0x4000L;
#endif
