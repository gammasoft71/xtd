/// @file
/// @brief Contains xtd::tunit::test_class_attribute class.
#pragma once
#include "unit_test.h"
#include <memory>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    template <typename TestClass>
    class test_class_attribute final {
    public:
      explicit test_class_attribute(const std::string& name) noexcept {xtd::tunit::unit_test::add({name, std::make_shared<TestClass>()});}
    };
  }
}
