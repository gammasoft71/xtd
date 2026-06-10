/// @file
/// @brief Contains xtd::tunit::tunit_event_args class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    /// @ingroup xtd_tunit tunit events
    class tunit_event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class tunit_event_args
      explicit tunit_event_args(const xtd::tunit::unit_test& unit_test) : ut_(unit_test) {};
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets current unit test.
      /// @return Current unit test.
      [[nodiscard]] auto unit_test() const -> const xtd::tunit::unit_test& {return ut_;}
      /// @}
      
    private:
      const xtd::tunit::unit_test& ut_;
    };
  }
}
