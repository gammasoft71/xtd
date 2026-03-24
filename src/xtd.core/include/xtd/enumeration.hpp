/// @file
/// @brief Contains xtd::enumeration concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/enumeration_.hpp
  template<typename type_t>
  concept enumeration =
  std::is_enum_v<xtd::raw_type<type_t>>;
}
