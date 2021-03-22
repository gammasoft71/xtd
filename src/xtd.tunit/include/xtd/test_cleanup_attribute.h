/// @file
/// @brief Contains xtd::tunit::test_cleanup_attribute class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "test.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    class test_cleanup_attribute {
    public:
      template<typename test_class_t>
      test_cleanup_attribute(const std::string& name, test_class_t& test_class, void (*method)()) noexcept :  test_cleanup_attribute(name, test_class, method, xtd::tunit::line_info()) {}
      
      template<typename test_class_t>
      test_cleanup_attribute(const std::string& name, test_class_t& test_class, void (*method)(), const xtd::tunit::line_info& caller) noexcept {test_class.add_test_cleanup({name, method, caller});}
    };
  }
}

#define test_cleanup_(method_name) \
  __##method_name##_unused() = delete; \
  class __test_cleanup_attribute : public xtd::tunit::test_cleanup_attribute { \
  public:\
    template<typename test_class> __test_cleanup_attribute(test_class& test) : test_cleanup_attribute(#method_name, test, &test_class::method_name, {__func__, __FILE__, __LINE__}) {} \
  } __test_cleanup_attribute {*this}; \
  static void method_name()
