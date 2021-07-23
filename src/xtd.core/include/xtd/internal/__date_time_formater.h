/// @file
/// @brief Contains __date_time_formater method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__format_exception.h"
#include "../strings.h"

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
inline std::basic_string<char_t> __tm_formater(const char_t* fmt, const std::tm& value, const std::locale& loc) {
  std::basic_stringstream<char_t> result;
  result.imbue(loc);
  result << std::put_time(&value, fmt);
  return result.str();
}

std::string __date_time_formater(std::string fmt, const std::tm& time, const std::locale& loc);

std::wstring __date_time_formater(std::wstring fmt, const std::tm& time, const std::locale& loc);

std::string __date_time_formater(std::string fmt, time_t time, const std::locale& loc);

std::wstring __date_time_formater(std::wstring fmt, time_t time, const std::locale& loc);
/// @endcond
