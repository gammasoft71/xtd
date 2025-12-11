/// @file
/// @brief Contains xtd::tunit::constraints::assume_that method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "assume.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    namespace constraints {
      template<class actual_t>
      inline auto assume_that(const actual_t& actual) {return xtd::tunit::constraints::assume().that(actual);}
    }
  }
}
