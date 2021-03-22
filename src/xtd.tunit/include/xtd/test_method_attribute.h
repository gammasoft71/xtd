/// @file
/// @brief Contains xtd::tunit::test_method_attribute class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "test.h"
#include "test_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    class test_method_attribute {
    public:
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)()) noexcept : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, xtd::tunit::line_info()) {}
      
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)(), const xtd::tunit::line_info& line_info) noexcept : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, line_info) {}
      
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)(), xtd::tunit::test_state test_state) noexcept : test_method_attribute(name, test_class, method, test_state, xtd::tunit::line_info()) {}
      
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)(), xtd::tunit::test_state test_state, const xtd::tunit::line_info& line_info) noexcept {test_class.add_test_method({name, std::bind(method, &test_class), test_state == xtd::tunit::test_state::ignored, line_info});}
    };
  }
}

#define ignore_test_method_(method_name) \
  __##method_name##_unused() = delete; \
  class __##method_name##_attribute##_class : public xtd::tunit::test_method_attribute { \
  public:\
    template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, xtd::tunit::test_state::ignored, {__func__, __FILE__, __LINE__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()

#define test_method_(method_name) \
  __##method_name##_unused() = delete; \
  class __##method_name##_attribute##_class : public xtd::tunit::test_method_attribute { \
  public:\
    template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, {__func__, __FILE__, __LINE__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()
