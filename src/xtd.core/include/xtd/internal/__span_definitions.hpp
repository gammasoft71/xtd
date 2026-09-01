/// @file
/// @brief Contains xtd::read_only_span and xtd::span definitions.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../dynamic_extent.hpp"
#include "../usize.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t, xtd::usize extent = xtd::dynamic_extent>
  class read_only_span;

  template<typename type_t, xtd::usize extent = xtd::dynamic_extent>
  class span;
}
