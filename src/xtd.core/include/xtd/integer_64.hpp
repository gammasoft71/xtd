/// @file
/// @brief Contains xtd::integer_64 concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "signed_integer_64.hpp"
#include "unsigned_integer_64.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/integer_64_.hpp
  template<typename type_t>
  concept integer_64 =
  xtd::signed_integer_64<type_t> ||
  xtd::unsigned_integer_64<type_t>;
}
