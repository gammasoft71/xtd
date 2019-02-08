/// @file
/// @brief Contains __format method.
#pragma once
#include <cstdarg>
#include <string>

/// @cond
template <class Char>
inline std::basic_string<Char> __format(const Char* fmt, ...) {return std::basic_string<Char>();}

template <>
inline std::basic_string<char> __format<char>(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::basic_string<char> formated_string(vsnprintf(nullptr, 0, fmt, args), 0);
  va_end(args);
  va_start(args, fmt);
  vsnprintf(&formated_string[0], formated_string.size() + 1, fmt, args);
  va_end(args);
  return formated_string;
}

template <>
inline std::basic_string<wchar_t> __format<wchar_t>(const wchar_t* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::basic_string<wchar_t> formated_string(vswprintf(nullptr, 0, fmt, args), 0);
  va_end(args);
  va_start(args, fmt);
  vswprintf(&formated_string[0], formated_string.size() + 1, fmt, args);
  va_end(args);
  return formated_string;
}
/// @endcond
