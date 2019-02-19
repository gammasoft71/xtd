/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "test.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    enum class test_state {
      considered,
      ignored
    };
  }
}
