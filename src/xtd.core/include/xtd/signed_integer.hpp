/// @file
/// @brief Contains xtd::signed_integer concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "signed_integer_16.hpp"
#include "signed_integer_32.hpp"
#include "signed_integer_64.hpp"
#include "signed_integer_8.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/signed_integer_.hpp
  template<typename type_t>
  concept signed_integer =
  xtd::signed_integer_8<type_t> ||
  xtd::signed_integer_16<type_t> ||
  xtd::signed_integer_32<type_t> ||
  xtd::signed_integer_64<type_t>;
}
