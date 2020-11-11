#pragma once
#include <cstddef>

#ifndef DTS_UPDOWN
constexpr size_t DTS_UPDOWN = 0x0001; // use UPDOWN instead of MONTHCAL
constexpr size_t DTS_SHOWNONE = 0x0002; // allow a NONE selection
constexpr size_t DTS_SHORTDATEFORMAT = 0x0000; // use the short date format (app must forward WM_WININICHANGE messages)
constexpr size_t DTS_LONGDATEFORMAT = 0x0004; // use the long date format (app must forward WM_WININICHANGE messages)
constexpr size_t DTS_SHORTDATECENTURYFORMAT = 0x000C; // short date format with century (app must forward WM_WININICHANGE messages)
constexpr size_t DTS_TIMEFORMAT = 0x0009; // use the time format (app must forward WM_WININICHANGE messages)
constexpr size_t DTS_APPCANPARSE = 0x0010; // allow user entered strings (app MUST respond to DTN_USERSTRING)
constexpr size_t DTS_RIGHTALIGN = 0x0020; // right-align popup instead of left-align it
#endif
