/// @file
/// @brief Contains xtd::real concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "real_decimal.hpp"
#include "real_double.hpp"
#include "real_single.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/real_.hpp
  template<typename type_t>
  concept real =
  xtd::real_single<type_t> ||
  xtd::real_double<type_t> ||
  xtd::real_decimal<type_t>;
}
