/// @file
/// @brief Contains __string_formatter method.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "__format_stringer.h"

/// @cond
template<typename char_t, typename value_t>
inline std::basic_string<char_t> __string_formatter(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
  return __format_stringer<char_t>(value);
}
/// @endcond
