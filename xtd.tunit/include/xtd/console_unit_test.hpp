/// @file
/// @brief Contains xtd::console_unit_test class.
#pragma once
#include "unit_test.hpp"
#include "ostream_unit_test.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace tunit {
    /// @brief The console_unit_test class.
    class console_unit_test final : public ostream_unit_test {
    public:
      console_unit_test() : ostream_unit_test(std::cout) {}
      
      console_unit_test(char* argv[], int argc) : ostream_unit_test(std::cout) {
        // parse args...
      }
    };
  }
}
