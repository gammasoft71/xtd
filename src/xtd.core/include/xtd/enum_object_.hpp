/// @file
/// @brief Contains xtd::enum_object::to_string method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_ENUM_OBJECT_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/enum_object> or <xtd/enum_object.hpp> instead."
#endif
/// @endcond

#include "globalization/culture_info.hpp"
#include "enum_object.hpp"

/// @cond
template < class enum_t >
xtd::string xtd::enum_object < enum_t >::to_string(const xtd::string& format, const xtd::globalization::culture_info& culture) const {
  init();
  auto fmt = format;
  if (xtd::string::is_empty(fmt)) fmt = "G";
  
  switch (fmt[0]) {
    case 'b':
    case 'B':
    case 'd':
    case 'D':
    case 'o':
    case 'O':
    case 'x':
    case 'X': return __numeric_formatter(fmt.chars(), static_cast < long long int > (value), culture);
    case 'f':
    case 'F':
    case 'g':
    case 'G': return xtd::enum_object < >::get_name(value);
  }
  xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
}
/// @endcond
