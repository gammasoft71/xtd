/// @file
/// @brief Contains xtd::tunit::tunit_event_args class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    class unit_test;
    /// @endcond
    
    /// @brief tunit_event_args is the base class for classes containing event data.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit events
    class tunit_event_args {
    public:
      /// @brief Create a new instance of class tunit_event_args
      explicit tunit_event_args(const xtd::tunit::unit_test& unit_test) : ut_(unit_test) {};
      
      /// @cond
      tunit_event_args(const tunit_event_args&) = default;
      /// @endcond
      
      /// @brief Gets current unit test.
      /// @return Current unit test.
      const xtd::tunit::unit_test& unit_test() const {return ut_;}

    private:
      const xtd::tunit::unit_test& ut_;
    };
  }
}
