/// @file
/// @brief Contains xtd::collections::generic::list definitions.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <cstddef>

/// @cond
namespace xtd::collections::generic {
  template<typename type_t, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  class list;
}
/// @endcond
