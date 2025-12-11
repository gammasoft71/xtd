/// @file
/// @brief Contains xtd::tunit::constraints::operator_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "operator_value.hpp"

/// @cond
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    namespace constraints {
      template<class value_t>
      inline auto operator_value<value_t>::and_() {return and_operator_value<value_t>(self_);}
    }
  }
}
/// @endcond
