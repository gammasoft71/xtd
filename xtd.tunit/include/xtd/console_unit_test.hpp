/// @file
/// @brief Contains xtd::tunit::console_unit_test class.
#pragma once
#include "unit_test.hpp"
#include "ostream_unit_test.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The console_unit_test class is console unit test interface.
    /// @remarks All messages are displayed on tho console.
    /// @par Examples
    /// This example sho how to instanciate and launch tests witn console unit test.
    /// @include console_unit_test.cpp
    class console_unit_test final : public ostream_unit_test {
    public:
      /// @brief Create a new console unit test
      console_unit_test() : ostream_unit_test(std::cout) {}
      
      console_unit_test(char* argv[], int argc) : ostream_unit_test(std::cout, argv, argc) {}
    };
  }
}
