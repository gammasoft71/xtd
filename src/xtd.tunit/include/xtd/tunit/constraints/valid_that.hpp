/// @file
/// @brief Contains xtd::tunit::constraints::valid_that method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "valid.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    namespace constraints {
      template<class actual_t>
      inline auto valid_that(const actual_t& actual) {return xtd::tunit::constraints::valid().that(actual);}
    }
  }
}
