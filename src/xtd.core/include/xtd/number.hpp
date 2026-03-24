/// @file
/// @brief Contains xtd::number concept alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "numeric.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/number_.hpp
  template<typename value_t>
  concept number = xtd::numeric<value_t>;
}
