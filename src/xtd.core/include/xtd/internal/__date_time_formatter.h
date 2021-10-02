/// @file
/// @brief Contains __date_time_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__format_exception.h"
#include "__sprintf.h"

/// @cond
template<typename char_t>
inline std::basic_string<char_t> __get_weekday_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value, std::basic_string<char_t>{'%', 'A'}.c_str());
  return result.str();
}

template<typename char_t>
inline std::basic_string<char_t> __get_brief_weekday_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value,std::basic_string<char_t>{'%', 'a'}.c_str());
  return result.str();
}

template<typename char_t>
inline std::basic_string<char_t> __get_month_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value, std::basic_string<char_t>{'%', 'B'}.c_str());
  return result.str();
}

template<typename char_t>
inline std::basic_string<char_t> __get_brief_month_name(const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value, std::basic_string<char_t>{'%', 'b'}.c_str());
  return result.str();
}

template<typename char_t>
inline std::basic_string<char_t> __tm_formatter(const char_t* fmt, const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value, fmt);
  return result.str();
}

inline std::string __date_time_formatter(std::string fmt, const std::tm& time, const std::locale& loc) {
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'd': return __sprintf("%02d/%02d/%d", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'D': return __sprintf("%d/%02d/%d", time.tm_mon+1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __tm_formatter("%Ec", time, loc);
    case 'F': return __tm_formatter("%c", time, loc);
    case 'g': return __tm_formatter("%Ec", time, loc);
    case 'G': return __tm_formatter("%c", time, loc);
    case 'h': return __sprintf("%s", __get_brief_weekday_name<char>(time, loc).c_str());
    case 'H': return __sprintf("%s", __get_weekday_name<char>(time, loc).c_str());
    case 'i': return __sprintf("%02d", time.tm_mday);
    case 'I': return __sprintf("%d", time.tm_mday);
    case 'j': return __sprintf("%s", __get_brief_month_name<char>(time, loc).c_str());
    case 'J': return __sprintf("%s", __get_month_name<char>(time, loc).c_str());
    case 'k': return __sprintf("%02d", time.tm_mon + 1);
    case 'K': return __sprintf("%d", time.tm_mon + 1);
    case 'l': return __sprintf("%02d", time.tm_year % 100);
    case 'L': return __sprintf("%d", time.tm_year + 1900);
    case 'm':
    case 'M': return __sprintf("%s %d", __get_month_name<char>(time, loc).c_str(), time.tm_mday);
    case 'n': return __sprintf("%s, %d %s %d", __get_weekday_name<char>(time, loc).c_str(), time.tm_mday, __get_month_name<char>(time, loc).c_str(), time.tm_year + 1900);
    case 'N': return __sprintf("%s, %d %s %d %d:%02d:%02d", __get_weekday_name<char>(time, loc).c_str(), time.tm_mday, __get_month_name<char>(time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return __sprintf("%d %s %d", time.tm_mday, __get_month_name<char>(time, loc).c_str(), time.tm_year + 1900);
    case 's': return __sprintf("%d-%02d-%02dT%02d:%02d:%02d", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 't': return __sprintf("%02d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return __sprintf("%d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return __sprintf("%d-%02d-%02d %02d:%02d:%02d", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return __sprintf("%s, %d %s %d %d:%02d:%02d", __get_weekday_name<char>(time, loc).c_str(), time.tm_mday, __get_month_name<char>(time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return __sprintf("%02d:%02d", time.tm_hour, time.tm_min);
    case 'V': return __sprintf("%d:%02d", time.tm_hour, time.tm_min);
    case 'y': return __sprintf("%s %d", __get_month_name<char>(time, loc).c_str(), time.tm_year % 100);
    case 'Y': return __sprintf("%s %d", __get_month_name<char>(time, loc).c_str(), time.tm_year + 1900);
    case 'z':
    case 'Z': return __tm_formatter("%Z", time, loc);
    default: __format_exception("Invalid format"); return {};
  }
}

inline std::wstring __date_time_formatter(std::wstring fmt, const std::tm& time, const std::locale& loc) {
  if (fmt.empty()) fmt =  L"G";
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'd': return __sprintf(L"%02d/%02d/%d", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'D': return __sprintf(L"%d/%02d/%d", time.tm_mon+1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __tm_formatter(L"%Ec", time, loc);
    case 'F': return __tm_formatter(L"%c", time, loc);
    case 'g': return __tm_formatter(L"%Ec", time, loc);
    case 'G': return __tm_formatter(L"%c", time, loc);
    case 'h': return __sprintf(L"%ls", __get_brief_weekday_name<wchar_t>(time, loc).c_str());
    case 'H': return __sprintf(L"%ls", __get_weekday_name<wchar_t>(time, loc).c_str());
    case 'i': return __sprintf(L"%02d", time.tm_mday);
    case 'I': return __sprintf(L"%d", time.tm_mday);
    case 'j': return __sprintf(L"%ls", __get_brief_month_name<wchar_t>(time, loc).c_str());
    case 'J': return __sprintf(L"%ls", __get_month_name<wchar_t>(time, loc).c_str());
    case 'k': return __sprintf(L"%02d", time.tm_mon + 1);
    case 'K': return __sprintf(L"%d", time.tm_mon + 1);
    case 'l': return __sprintf(L"%02d", time.tm_year % 100);
    case 'L': return __sprintf(L"%d", time.tm_year + 1900);
    case 'm':
    case 'M': return __sprintf(L"%ls %d", __get_month_name<wchar_t>(time, loc).c_str(), time.tm_mday);
    case 'n': return __sprintf(L"%ls, %d %ls %d", __get_weekday_name<wchar_t>(time, loc).c_str(), time.tm_mday, __get_month_name<wchar_t>(time, loc).c_str(), time.tm_year + 1900);
    case 'N': return __sprintf(L"%ls, %d %ls %d %d:%02d:%02d", __get_weekday_name<wchar_t>(time, loc).c_str(), time.tm_mday, __get_month_name<wchar_t>(time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return __sprintf(L"%d %ls %d", time.tm_mday, __get_month_name<wchar_t>(time, loc).c_str(), time.tm_year + 1900);
    case 's': return __sprintf(L"%d-%02d-%02dT%02d:%02d:%02d", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 't': return __sprintf(L"%02d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return __sprintf(L"%d:%02d:%02d", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return __sprintf(L"%d-%02d-%02d %02d:%02d:%02d", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return __sprintf(L"%ls, %d %ls %d %d:%02d:%02d", __get_weekday_name<wchar_t>(time, loc).c_str(), time.tm_mday, __get_month_name<wchar_t>(time, loc).c_str(), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return __sprintf(L"%02d:%02d", time.tm_hour, time.tm_min);
    case 'V': return __sprintf(L"%d:%02d", time.tm_hour, time.tm_min);
    case 'y': return __sprintf(L"%ls %d", __get_month_name<wchar_t>(time, loc).c_str(), time.tm_year % 100);
    case 'Y': return __sprintf(L"%ls %d", __get_month_name<wchar_t>(time, loc).c_str(), time.tm_year + 1900);
    case 'z':
    case 'Z': return __tm_formatter(L"%Z", time, loc);
    default: __format_exception("Invalid format"); return {};
  }
}

inline std::string __date_time_formatter(std::string fmt, time_t time, const std::locale& loc) {
  return __date_time_formatter(fmt, *std::localtime(&time), loc);
}

inline std::wstring __date_time_formatter(std::wstring fmt, time_t time, const std::locale& loc) {
  return __date_time_formatter(fmt, *std::localtime(&time), loc);
}
/// @endcond
