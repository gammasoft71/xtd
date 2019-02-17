/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "test_class.hpp"
#include "test.hpp"
#include "tunit_event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    class test_event_args : public xtd::tunit::tunit_event_args {
    public:
      explicit test_event_args(const xtd::tunit::test& test, const xtd::tunit::test_class& test_class) : t_(test), tc_(test_class) {}

      const xtd::tunit::test& test() const noexcept {return this->t_;}
      const xtd::tunit::test_class& test_class() const noexcept {return this->tc_;}

    private:
      const xtd::tunit::test& t_;
      const xtd::tunit::test_class& tc_;
    };
  }
}
