/// @file
/// @brief Contains __numeric_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__binary_formatter.h"
#include "__fixed_point_formatter.h"
#include "__format_exception.h"
#include "__sprintf.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __numeric_formatter(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  std::basic_string<char_t> format = fmt;
  if (format.empty()) format = {'G'};
  
  std::vector<char_t> possible_formats {'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'o', 'O', 'p', 'P', 'x', 'X'};
  if (format.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), format[0]) == possible_formats.end() || (format.size() >= 2 && !std::isdigit(format[1])) || (format.size() == 3 && !std::isdigit(format[2])))
    __format_exception("Custom format not yet implemented");
  
  int precision = 0;
  if (format[0] == 'b' || format[0] == 'B' || format[0] == 'd' || format[0] == 'D' || format[0] == 'o' || format[0] == 'O' || format[0] == 'x' || format[0] == 'X') {
    try {
      for (auto c : format.substr(1))
        if (!std::isdigit(c) && c != ' ' && c != '+' && c != '-') __format_exception("Invalid format expression");
      if (format.size() > 1) precision = std::stoi(format.substr(1));
    } catch(...) {
      __format_exception("Invalid format expression");
    }
    if ((format[0] == 'd' || format[0] == 'D') && precision > 0 && value < 0) precision += 1;
    if ((format[0] == 'd' || format[0] == 'D') && precision < 0 && value < 0) precision -= 1;
  }
  
  std::basic_string<char_t> fmt_str({'%', '0', '*', 'l', 'l'});
  switch (format[0]) {
    case 'b':
    case 'B': return __binary_formater<char_t>(value, precision);
    case 'd':
    case 'D':
    case 'G': return __sprintf((fmt_str + char_t(std::is_unsigned<value_t>::value ? 'u' : 'd')).c_str(), precision, static_cast<long long>(value));
    case 'o':
    case 'O': return __sprintf((fmt_str + char_t('o')).c_str(), precision, static_cast<long long>(value));
    case 'x':
    case 'X': return __sprintf((fmt_str + format[0]).c_str(), precision, static_cast<long long>(value));
    default: return __fixed_point_formater(format, static_cast<long double>(value), loc);
  }
}
/// @endcond
