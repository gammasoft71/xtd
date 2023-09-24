/// @file
/// @brief Contains __date_time_formatter method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../types"
#include "__format_exception"
#include "__sprintf"

/// @cond
template<typename char_t>
inline std::basic_string<char_t> __to_string(const char_t* fmt, const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value, fmt);
  return result.str();
}

inline std::string __date_time_formatter(std::string fmt, const std::tm& time, xtd::uint32 nanoseconds, const std::locale& loc) {
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'a': return __sprintf("%s", time.tm_hour / 12 ? "PM" : "AM");
    case 'b': return __sprintf("%03d", nanoseconds / 1000000);
    case 'B': return __sprintf("%d", nanoseconds / 1000000);
    case 'd': return __sprintf("%02d/%02d/%d", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'D': return __sprintf("%d/%02d/%d", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __to_string("%Ec", time, loc);
    case 'F': return __to_string("%c", time, loc);
    case 'g': return __to_string("%Ec", time, loc);
    case 'G': return __to_string("%c", time, loc);
    case 'h': return __sprintf("%s", __to_string("%a", time, loc).c_str());
    case 'H': return __sprintf("%s", __to_string("%A", time, loc).c_str());
    case 'i': return __sprintf("%02d", time.tm_mday);
    case 'I': return __sprintf("%d", time.tm_mday);
    case 'j': return __sprintf("%s", __to_string("%b", time, loc).c_str());
    case 'J': return __sprintf("%s", __to_string("%B", time, loc).c_str());
    case 'k': return __sprintf("%02d", time.tm_mon + 1);
    case 'K': return __sprintf("%d", time.tm_mon + 1);
    case 'l': return __sprintf("%02d", time.tm_year % 100);
    case 'L': return __sprintf("%d", time.tm_year + 1900);
    case 'm':
    case 'M': return __sprintf("%s %d", __to_string("%B", time, loc).c_str(), time.tm_mday);
    case 'n': return __sprintf("%s, %d %s %d", __to_string("%A", time, loc).c_str(), time.tm_mday, __to_string("%B", time, loc).c_str(), time.tm_year + 1900);
    case 'N': return __sprintf("%s, %d %s %d %d:%02d:%02d", __to_string("%A", time, loc).c_str(), time.tm_mday, __to_string("%B", time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return __sprintf("%d %s %d", time.tm_mday, __to_string("%B", time, loc).c_str(), time.tm_year + 1900);
    case 's': return __sprintf("%d-%02d-%02dT%02d:%02d:%02d.%07d", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec, nanoseconds);
    case 't': return __sprintf("%02d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return __sprintf("%d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return __sprintf("%d-%02d-%02d %02d:%02d:%02d", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return __sprintf("%s, %d %s %d %d:%02d:%02d", __to_string("%A", time, loc).c_str(), time.tm_mday, __to_string("%B", time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return __sprintf("%02d:%02d", time.tm_hour, time.tm_min);
    case 'V': return __sprintf("%d:%02d", time.tm_hour, time.tm_min);
    case 'w': return __sprintf("%02d}", time.tm_hour);
    case 'W': return __sprintf("%d", time.tm_hour);
    case 'x': return __sprintf("%02d", time.tm_hour % 12);
    case 'X': return __sprintf("%d", time.tm_hour % 12);
    case 'y': return __sprintf("%s %d", __to_string("%B", time, loc).c_str(), time.tm_year % 100);
    case 'Y': return __sprintf("%s %d", __to_string("%B", time, loc).c_str(), time.tm_year + 1900);
    case 'z':
    case 'Z': return __to_string("%Z", time, loc);
    default: __format_exception("Invalid format"); return {};
  }
}

inline std::wstring __date_time_formatter(std::wstring fmt, const std::tm& time, xtd::uint32 nanoseconds, const std::locale& loc) {
  if (fmt.empty()) fmt =  L"G";
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'a': return __sprintf(L"%s", time.tm_hour / 12 ? "PM" : "AM");
    case 'b': return __sprintf(L"%03d", nanoseconds / 1000000);
    case 'B': return __sprintf(L"%d", nanoseconds / 1000000);
    case 'd': return __sprintf(L"%02d/%02d/%d", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'D': return __sprintf(L"%d/%02d/%d", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __to_string(L"%Ec", time, loc);
    case 'F': return __to_string(L"%c", time, loc);
    case 'g': return __to_string(L"%Ec", time, loc);
    case 'G': return __to_string(L"%c", time, loc);
    case 'h': return __sprintf(L"%ls", __to_string(L"%a", time, loc).c_str());
    case 'H': return __sprintf(L"%ls", __to_string(L"%A", time, loc).c_str());
    case 'i': return __sprintf(L"%02d", time.tm_mday);
    case 'I': return __sprintf(L"%d", time.tm_mday);
    case 'j': return __sprintf(L"%ls", __to_string(L"%b", time, loc).c_str());
    case 'J': return __sprintf(L"%ls", __to_string(L"%B", time, loc).c_str());
    case 'k': return __sprintf(L"%02d", time.tm_mon + 1);
    case 'K': return __sprintf(L"%d", time.tm_mon + 1);
    case 'l': return __sprintf(L"%02d", time.tm_year % 100);
    case 'L': return __sprintf(L"%04d", time.tm_year + 1900);
    case 'm':
    case 'M': return __sprintf(L"%ls %d", __to_string(L"%B", time, loc).c_str(), time.tm_mday);
    case 'n': return __sprintf(L"%ls, %d %ls %d", __to_string(L"%A", time, loc).c_str(), time.tm_mday, __to_string(L"%B", time, loc).c_str(), time.tm_year + 1900);
    case 'N': return __sprintf(L"%ls, %d %ls %d %d:%02d:%02d", __to_string(L"%A", time, loc).c_str(), time.tm_mday, __to_string(L"%B", time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return __sprintf(L"%d %ls %d", time.tm_mday, __to_string(L"%B", time, loc).c_str(), time.tm_year + 1900);
    case 's': return __sprintf(L"%d-%02d-%02dT%02d:%02d:%02d.%07d", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec, nanoseconds / 100);
    case 't': return __sprintf(L"%02d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return __sprintf(L"%d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return __sprintf(L"%d-%02d-%02d %02d:%02d:%02d", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return __sprintf(L"%ls, %d %ls %d %d:%02d:%02d", __to_string(L"%A", time, loc).c_str(), time.tm_mday, __to_string(L"%B", time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return __sprintf(L"%02d:%02d", time.tm_hour, time.tm_min);
    case 'V': return __sprintf(L"%d:%02d", time.tm_hour, time.tm_min);
    case 'w': return __sprintf(L"%02d}", time.tm_hour);
    case 'W': return __sprintf(L"%d", time.tm_hour);
    case 'x': return __sprintf(L"%02d", time.tm_hour % 12);
    case 'X': return __sprintf(L"%d", time.tm_hour % 12);
    case 'y': return __sprintf(L"%ls %d", __to_string(L"%B", time, loc).c_str(), time.tm_year % 100);
    case 'Y': return __sprintf(L"%ls %d", __to_string(L"%B", time, loc).c_str(), time.tm_year + 1900);
    case 'z':
    case 'Z': return __to_string(L"%Z", time, loc);
    default: __format_exception("Invalid format"); return {};
  }
}

inline std::string __date_time_formatter(const std::string& fmt, time_t time, xtd::uint32 nanoseconds, const std::locale& loc) {
  return __date_time_formatter(fmt, *std::localtime(&time), nanoseconds, loc);
}

inline std::wstring __date_time_formatter(const std::wstring& fmt, time_t time, xtd::uint32 nanoseconds, const std::locale& loc) {
  return __date_time_formatter(fmt, *std::localtime(&time), nanoseconds, loc);
}
/// @endcond
