/// @file
/// @brief Contains xtd::unique_ptr_object definition.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include <memory>

/// @cond
namespace xtd {
  template<class type_t, class deleter_t = std::default_delete<type_t>>
  class unique_ptr_object;
}
/// @endcond
