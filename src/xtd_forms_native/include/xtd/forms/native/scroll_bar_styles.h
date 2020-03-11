#pragma once
#include <cstddef>

#ifndef SB_HORZ
// Scroll Bar Control Constants
constexpr size_t SB_HORZ = 0;
constexpr size_t SB_VERT = 1;
constexpr size_t SB_CTL = 2;
constexpr size_t SB_BOTH = 3;

/*
 * Scroll Bar Commands
 */
constexpr size_t SB_LINEUP = 0;
constexpr size_t SB_LINELEFT = 0;
constexpr size_t SB_LINEDOWN = 1;
constexpr size_t SB_LINERIGHT = 1;
constexpr size_t SB_PAGEUP = 2;
constexpr size_t SB_PAGELEFT = 2;
constexpr size_t SB_PAGEDOWN = 3;
constexpr size_t SB_PAGERIGHT = 3;
constexpr size_t SB_THUMBPOSITION = 4;
constexpr size_t SB_THUMBTRACK = 5;
constexpr size_t SB_TOP = 6;
constexpr size_t SB_LEFT = 6;
constexpr size_t SB_BOTTOM = 7;
constexpr size_t SB_RIGHT = 7;
constexpr size_t SB_ENDSCROLL = 8;
#endif
