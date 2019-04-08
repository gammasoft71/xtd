/// @file
/// @brief Contains __character_formater method.
#pragma once
#include "__format_stringer.hpp"

/// @cond
template<typename Char, typename Value>
inline std::basic_string<Char> __character_formater(const std::basic_string<Char>& fmt, Value value, const std::locale& loc) {
  return __format_stringer<Char>(value);
}
/// @endcond
