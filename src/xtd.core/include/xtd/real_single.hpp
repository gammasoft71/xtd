/// @file
/// @brief Contains xtd::real_single concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "single.hpp"
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/real_single_.hpp
  template<typename type_t>
  concept real_single =
  std::same_as<xtd::raw_type<type_t>, xtd::single>;
}
