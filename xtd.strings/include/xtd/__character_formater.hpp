/// @file
/// @brief Contains __character_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/strings>"
#endif
/// @endcond

#include "__format_stringer.hpp"

/// @cond
template<typename Char, typename Value>
inline std::basic_string<Char> __character_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  if (!std::is_same<Value, char>::value && value <= 255)
    return __format_stringer<Char>(static_cast<char>(value));
  return __format_stringer<Char>(value);
}
/// @endcond
