/// @file
/// @brief Contains xtd::tunit::test_event_args class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "test_class.h"
#include "test.h"
#include "tunit_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Provides data for the xtd::tunit::test events.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit events
    class test_event_args : public xtd::tunit::tunit_event_args {
    public:
      /// @brief Create a new instance of class class_event_args.
      /// @param test Current test.
      /// @param test_class Current test_class.
      explicit test_event_args(const xtd::tunit::test& test, const xtd::tunit::test_class& test_class, const xtd::tunit::unit_test& unit_test) : xtd::tunit::tunit_event_args(unit_test), t_(test), tc_(test_class) {}

      /// @brief Gets current test.
      /// @return Current test.
      const xtd::tunit::test& test() const noexcept {return t_;}

      /// @brief Gets current class test.
      /// @return Current class test.
      const xtd::tunit::test_class& test_class() const noexcept {return tc_;}

    private:
      const xtd::tunit::test& t_;
      const xtd::tunit::test_class& tc_;
    };
  }
}
