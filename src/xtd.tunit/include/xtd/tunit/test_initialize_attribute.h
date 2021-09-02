/// @file
/// @brief Contains xtd::tunit::test_initialize_attribute class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "test.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    class test_initialize_attribute {
    public:
      template<typename test_class_t>
      test_initialize_attribute(const std::string& name, test_class_t& test_class, void (*method)()) noexcept :  test_initialize_attribute(name, test_class, method, xtd::diagnostics::stack_frame()) {}
      
      template<typename test_class_t>
      test_initialize_attribute(const std::string& name, test_class_t& test_class, void (*method)(), const xtd::diagnostics::stack_frame& caller) noexcept {test_class.add_test_initialize({name, method, caller});}
    };
  }
}

#define test_initialize_(method_name) \
  __##method_name##_unused() = delete; \
  class __test_initialize_attribute : public xtd::tunit::test_initialize_attribute { \
  public:\
    template<typename test_class> __test_initialize_attribute(test_class& test) : test_initialize_attribute(#method_name, test, &test_class::method_name, {__FILE__, __LINE__, __func__}) {} \
  } __test_initialize_attribute {*this}; \
  static void method_name()

