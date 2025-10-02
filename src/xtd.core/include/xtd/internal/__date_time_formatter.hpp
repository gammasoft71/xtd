/// @file
/// @brief Contains __date_time_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../uint32.hpp"
#include <ctime>
#include <string>

/// @cond
// These four following methods are implemented in src/xtd/date_time.cpp file.
std::string __date_time_formatter(std::string fmt, const std::tm& time, xtd::uint32 nanoseconds, const std::locale& loc);
std::wstring __date_time_formatter(std::wstring fmt, const std::tm& time, xtd::uint32 nanoseconds, const std::locale& loc);
std::string __date_time_formatter(const std::string& fmt, time_t time, xtd::uint32 nanoseconds, const std::locale& loc);
std::wstring __date_time_formatter(const std::wstring& fmt, time_t time, xtd::uint32 nanoseconds, const std::locale& loc);
/// @endcond
