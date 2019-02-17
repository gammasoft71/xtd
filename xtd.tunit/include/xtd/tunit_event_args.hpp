/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    /// @brief tunit_event_args is the base class for classes containing event data.
    class tunit_event_args {
    public:
      /// @brief Create a new instance of class tunit_event_args
      tunit_event_args() = default;
      
      /// @cond
      tunit_event_args(const tunit_event_args&) = default;
      tunit_event_args& operator=(const tunit_event_args&) = default;
      virtual ~tunit_event_args() = default;
      /// @endcond

      /// @brief Represents an event with no event data.
      static tunit_event_args empty() { return tunit_event_args(); }
    };
  }
}
