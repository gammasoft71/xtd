/// @file
/// @brief Contains xtd::tunit::constraints::assert_type enum.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The constraints namespace contains the constraint-based assert model.
    namespace constraints {
      enum class assert_type {
        assert,
        valid,
        assume
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::tunit::constraints::assert_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::tunit::constraints::assert_type> {{xtd::tunit::constraints::assert_type::assert, "assert"}, {xtd::tunit::constraints::assert_type::valid, "valid"}, {xtd::tunit::constraints::assert_type::assume, "assume"}};}
};
/// @endcond
