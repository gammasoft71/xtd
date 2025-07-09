/// @file
/// @brief Contains xtd::tunit::console_unit_test class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "unit_test.hpp"
#include "ostream_unit_test.hpp"
#include <xtd/console>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The console_unit_test class is console unit test interface.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks All messages are displayed on the console.
    /// @par Examples
    /// This example shows how to instantiate and launch tests with console unit test.
    /// @include console_unit_test.cpp
    class tunit_export_ console_unit_test final : public ostream_unit_test {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new console unit test
      /// @remarks The arguments of the unit test application are done with xtd::environment::get_command_line_args method.
      console_unit_test() noexcept;
      /// @}
    };
  }
}
