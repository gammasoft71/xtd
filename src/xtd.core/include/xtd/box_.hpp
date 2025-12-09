/// @file
/// @brief Contains xtd::box::to_string method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_BOX_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/box> or <xtd/box.hpp> instead."
#endif
/// @endcond

#include "globalization/culture_info.hpp"
#include "box.hpp"

/// @cond
template<class type_t>
inline xtd::string xtd::box<type_t>::to_string() const noexcept {return to_string("", xtd::globalization::culture_info::current_culture());}
template<class type_t>
inline xtd::string xtd::box<type_t>::to_string(const xtd::string& format) const {return to_string(format, xtd::globalization::culture_info::current_culture());}

template<class type_t>
inline xtd::string xtd::box<type_t>::to_string(const xtd::string& format, const xtd::globalization::culture_info& culture) const {
  return xtd::string::format(culture, xtd::string::format("{{:{}}}", format), value);
}
// @endcond
