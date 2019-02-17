/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "test_class.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    class class_event_args {
    public:
      explicit class_event_args(const xtd::tunit::test_class& test_class) : tc_(test_class) {}

      const xtd::tunit::test_class& test_class() const noexcept {return this->tc_;}

    private:
      const xtd::tunit::test_class& tc_;
    };
  }
}
