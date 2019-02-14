/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "unit_test.hpp"
#include <memory>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    template <typename TestClass>
    struct test_class_attribute final {
    public:
      test_class_attribute(const std::string& name) {xtd::tunit::unit_test::add({name, std::make_unique<TestClass>()});}
    };
  }
}
