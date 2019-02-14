/// @file
/// @brief Contains xtd::tunit::test_initialize_attribute class.
#pragma once
#include "registered_method.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct test_initialize_attribute final {
    public:
      template<typename TestClass>
      test_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)()) :  test_initialize_attribute(name, test_class, method, xtd::tunit::caller()) {}
      
      template<typename TestClass>
      test_initialize_attribute(const std::string& name, TestClass& test_class, void (*method)(), const xtd::tunit::caller& caller) {test_class.add_test_initialize({name, method, caller});}
    };
  }
}
