/// @file
/// @brief Contains xtd::unsigned_integer concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "unsigned_integer_16.hpp"
#include "unsigned_integer_32.hpp"
#include "unsigned_integer_64.hpp"
#include "unsigned_integer_8.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/unsigned_integer_.hpp
  template<typename type_t>
  concept unsigned_integer =
  xtd::unsigned_integer_8<type_t> ||
  xtd::unsigned_integer_16<type_t> ||
  xtd::unsigned_integer_32<type_t> ||
  xtd::unsigned_integer_64<type_t>;
}
