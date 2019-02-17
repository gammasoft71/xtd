/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    class tunit_event_args {
    public:
      tunit_event_args() = default;
      static tunit_event_args empty() { return tunit_event_args(); }
    };
  }
}
