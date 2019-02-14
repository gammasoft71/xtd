/// @file
/// @brief Contains xtd::tunit::test_method_attribute class.
#pragma once
#include "registered_method.hpp"
#include "test_state.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct test_method_attribute final {
    public:
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)()) : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, xtd::tunit::line_info()) {}
      
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), const xtd::tunit::line_info& caller) : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, {__func__, __FILE__, __LINE__}) {}
      
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), xtd::tunit::test_state test_state)  : test_method_attribute(name, test_class, method, test_state, xtd::tunit::line_info()) {}
      
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), xtd::tunit::test_state test_state, const xtd::tunit::line_info& caller) {test_class.add_test_method({name, {test_class, method}, test_state == xtd::tunit::test_state::ignored, caller});}
    };
  }
}
