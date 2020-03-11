/// @file
/// @brief Contains __numeric_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include "__binary_formater.h"
#include "__fixed_point_formater.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __numeric_formater(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  if (fmt.empty()) return __format_stringer<char_t>(value);
  
  std::vector<char_t> possible_formats {'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'o', 'O', 'p', 'P', 'x', 'X'};
  if (fmt.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), fmt[0]) == possible_formats.end() || (fmt.size() >= 2 && !std::isdigit(fmt[1])) || (fmt.size() == 3 && !std::isdigit(fmt[2])))
    throw std::invalid_argument("Custom format not yet implemented");
  
  int precision = 0;
  if (fmt[0] == 'b' || fmt[0] == 'B' || fmt[0] == 'd' || fmt[0] == 'D' || fmt[0] == 'o' || fmt[0] == 'O' || fmt[0] == 'x' || fmt[0] == 'X') {
    try {
      for (auto c : fmt.substr(1))
        if (!std::isdigit(c) && c != ' ' && c != '+' && c != '-') throw std::invalid_argument("Invalid format expression");
      if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
    } catch(...) {
      throw std::invalid_argument("Invalid format expression");
    }
    if ((fmt[0] == 'd' || fmt[0] == 'D') && precision > 0 && value < 0) precision += 1;
    if ((fmt[0] == 'd' || fmt[0] == 'D') && precision < 0 && value < 0) precision -= 1;
  }
  
  std::basic_string<char_t> fmt_str({'%', '0', '*', 'l', 'l'});
  switch (fmt[0]) {
    case 'b':
    case 'B': return __binary_formater<char_t>(value, precision);
    case 'd':
    case 'D': return xtd::strings::formatf(fmt_str + char_t(std::is_unsigned<value_t>::value ? 'u' : 'd'), precision, static_cast<long long>(value));
    case 'o':
    case 'O': return xtd::strings::formatf(fmt_str + char_t('o'), precision, static_cast<long long>(value));
    case 'x':
    case 'X': return xtd::strings::formatf(fmt_str + fmt[0], precision, static_cast<long long>(value));
    default: return __fixed_point_formater(fmt, static_cast<long double>(value), loc);
  }
}
/// @endcond
