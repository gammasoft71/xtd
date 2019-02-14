/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "registered_method.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    enum class test_state {
      considered,
      ignored
    };
  }
}
