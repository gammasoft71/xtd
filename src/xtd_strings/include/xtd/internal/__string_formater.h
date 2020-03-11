/// @file
/// @brief Contains __string_formater method.
#pragma once

/// @cond
#ifndef __XTD_STRINGS_INCLUDE__
#error "Do not include this file yourself, use only #include <xtd/xtd.strings>"
#endif
/// @endcond

#include "__format_stringer.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __string_formater(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  return __format_stringer<char_t>(value);
}
/// @endcond
