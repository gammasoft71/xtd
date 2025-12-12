/// @file
/// @brief Contains xtd::tunit::constraints::assert method.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "actual_value.hpp"
#include "and_operator_value.hpp"
#include "assert_value.hpp"
#include "does_not_value.hpp"
#include "does_value.hpp"
#include "is_not_value.hpp"
#include "is_value.hpp"
#include "operator_value.hpp"
#include "that_value.hpp"

#include "operator_value_.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The constraints namespace contains the constraint-based assert model.
    namespace constraints {
      inline auto assume() {return constraints::assert_value(constraints::assert_type::assume);}
    }
  }
}
