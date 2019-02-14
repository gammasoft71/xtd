/// @file
/// @brief Contains xtd::tunit::class_cleanup_attribute class.
#pragma once
#include "registered_method.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct class_cleanup_attribute {
    public:
      template<typename TestClass>
      class_cleanup_attribute(const std::string& name, TestClass& test_class, void (*method)()) noexcept :  class_cleanup_attribute(name, test_class, method, xtd::tunit::line_info()) {}
      
      template<typename TestClass>
      class_cleanup_attribute(const std::string& name, TestClass& test_class, void (*method)(), const xtd::tunit::line_info& caller) noexcept {test_class.add_class_cleanup({name, method, caller});}
    };
  }
}

#define class_cleanup_(method_name) \
  __##method_name##_static() {} \
  struct __class_cleanup_attribute : public xtd::tunit::class_cleanup_attribute { \
  template<typename test_class> __class_cleanup_attribute(test_class& test) : class_cleanup_attribute(#method_name, test, &method_name, {__func__, __FILE__, __LINE__}) {__##method_name##_static();} \
  } __class_cleanup_attribute {*this}; \
  static void method_name()

