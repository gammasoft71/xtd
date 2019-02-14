/// @file
/// @brief Contains xtd::tunit::test_method_attribute class.
#pragma once
#include "registered_method.hpp"
#include "test_state.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct test_method_attribute {
    public:
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)()) noexcept : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, xtd::tunit::line_info()) {}
      
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), const xtd::tunit::line_info& caller) noexcept : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, {__func__, __FILE__, __LINE__}) {}
      
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), xtd::tunit::test_state test_state) noexcept : test_method_attribute(name, test_class, method, test_state, xtd::tunit::line_info()) {}
      
      template<typename TestClass>
      test_method_attribute(const std::string& name, TestClass& test_class, void (TestClass::*method)(), xtd::tunit::test_state test_state, const xtd::tunit::line_info& caller) noexcept {test_class.add_test_method({name, {test_class, method}, test_state == xtd::tunit::test_state::ignored, caller});}
    };
  }
}

#define ignore_test_method_(method_name) \
  __##method_name##_unused() = delete; \
  struct __##method_name##_attribute##_class : public xtd::tunit::test_method_attribute { \
  template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, xtd::tunit::test_state::ignored, {__func__, __FILE__, __LINE__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()

#define test_method_(method_name) \
  __##method_name##_unused() = delete; \
  struct __##method_name##_attribute##_class : public xtd::tunit::test_method_attribute { \
  template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, {__func__, __FILE__, __LINE__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()
