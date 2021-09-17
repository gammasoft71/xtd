/// @file
/// @brief Contains __fixed_point_formater method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__character_formater.h"
#include "__currency_formater.h"
#include "__format_exception.h"
#include "__format_stringer.h"
#include "__natural_formater.h"
#include "__sprintf.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __fixed_point_formater(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  if (fmt.empty()) return __format_stringer<char_t>(value);
  
  std::vector<char_t> possible_formats {'c', 'C', 'e', 'E', 'f', 'F', 'g', 'G', 'n', 'N', 'p', 'P'};
  if (fmt.size() > 3 || std::find(possible_formats.begin(), possible_formats.end(), fmt[0]) == possible_formats.end() || (fmt.size() >= 2 && !std::isdigit(fmt[1])) || (fmt.size() == 3 && !std::isdigit(fmt[2])))
    __format_exception("Custom format not yet implemented");
  
  int precision = 0;
  try {
    if (fmt.size() > 1) precision = std::stoi(fmt.substr(1));
  } catch(...) {
    __format_exception("Invalid format expression");
  }
  if ((fmt[0] == 'f' || fmt[0] == 'F' || fmt[0] == 'n' || fmt[0] == 'N' || fmt[0] == 'p' || fmt[0] == 'P' || fmt[0] == 'r' || fmt[0] == 'R') && fmt.size() == 1) precision = 2;
  if ((fmt[0] == 'e' || fmt[0] == 'E') && fmt.size() == 1) precision = 6;
  if ((fmt[0] == 'g' || fmt[0] == 'G') && fmt.size() == 1) precision = sizeof(value) <= 4 ? 7 : 15;

  std::basic_string<char_t> fmt_str({'%', '.', '*', 'L'});
  switch (fmt[0]) {
    case 'c':
    case 'C': return __currency_formater<char_t>(static_cast<long double>(value), loc);
    case 'e':
    case 'E':
    case 'f':
    case 'F':
    case 'g':
    case 'G': return __sprintf((fmt_str + fmt[0]).c_str(), precision, static_cast<long double>(value));
    case 'n':
    case 'N': return __natural_formater<char_t>(static_cast<long double>(value), precision, loc);
    case 'p': return __sprintf((fmt_str + char_t('f')).c_str(), precision, static_cast<long double>(value * 100)) + std::basic_string<char_t>({char_t(' '), char_t('%')});
    case 'P': return __sprintf((fmt_str + char_t('F')).c_str(), precision, static_cast<long double>(value * 100)) + std::basic_string<char_t>({char_t(' '), char_t('%')});
    default: __format_exception("Invalid format expression"); return {};
  }
}
/// @endcond
