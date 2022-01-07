/// @file
/// @brief Contains __boolean_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__numeric_formatter.h"
#include "__format_exception.h"


/// @cond
template<typename char_t>
inline std::basic_string<char_t> __boolean_formatter(const std::basic_string<char_t>& fmt, bool value, const std::locale& loc) {
  if (fmt.empty()) return value ? std::basic_string<char_t> {'t', 'r', 'u', 'e'} : std::basic_string<char_t> {'f', 'a', 'l', 's', 'e'};
  
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return __numeric_formatter(fmt, value ? 1 : 0, loc);
    case 'g':
    case 'G': return value ? std::basic_string<char_t> {'t', 'r', 'u', 'e'} : std::basic_string<char_t> {'f', 'a', 'l', 's', 'e'};
    default: __format_exception("Invalid format expression"); return {};
  }
}
/// @endcond
