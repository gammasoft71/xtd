/// @file
/// @brief Contains xtd::tunit::test_state enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "test.h"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represent the test state enumeration used bu test.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    enum class test_state {
      /// @brief Test is considered.
      considered,
      /// @brief Test is ignored.
      ignored
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::tunit::test_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::tunit::test_state> {{xtd::tunit::test_state::considered, "considered"}, {xtd::tunit::test_state::ignored, "ignored"}};}
};
/// @endcond
