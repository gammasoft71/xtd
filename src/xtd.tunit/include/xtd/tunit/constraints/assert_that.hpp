/// @file
/// @brief Contains xtd::tunit::constraints::assert_that method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The contraints namespace contains the constraint-based assert model.
    namespace constraints {
      template<class actual_t>
      inline auto assert_that(const actual_t& actual) {return xtd::tunit::constraints::assert().that(actual);}
    }
  }
}
