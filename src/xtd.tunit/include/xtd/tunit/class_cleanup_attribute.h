/// @file
/// @brief Contains xtd::tunit::class_cleanup_attribute class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "test.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief This attribute is use to add cleaup class method to class test attribute.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    class class_cleanup_attribute {
    public:
      /// @brief Creates new instance of class_cleanup_attribute attribute.
      /// @param name Name of attribute
      /// @param test_class xtd::tunit::class_test containing clean_up method.
      /// @param method Cleanup class method.
      template<typename test_class_t>
      class_cleanup_attribute(const std::string& name, test_class_t& test_class, void (*method)()) noexcept :  class_cleanup_attribute(name, test_class, method, xtd::diagnostics::stack_frame()) {}
      
      /// @brief Creates new instance of class_cleanup_attribute attribute.
      /// @param name Name of attribute
      /// @param test_class xtd::tunit::class_test containing clean_up method.
      /// @param method Cleanup class method.
      /// @param stack_frame Contains information about current file and current line.
      template<typename test_class_t>
      class_cleanup_attribute(const std::string& name, test_class_t& test_class, void (*method)(), const xtd::diagnostics::stack_frame& stack_frame) noexcept {test_class.add_class_cleanup({name, method, stack_frame});}
    };
  }
}

/// @brief add cleaup class method to class test.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit
/// @param method_name cleanup class method to add.
#define class_cleanup_(method_name) \
  __##method_name##_static() {} \
  class __class_cleanup_attribute : public xtd::tunit::class_cleanup_attribute { \
  public:\
    template<typename test_class> __class_cleanup_attribute(test_class& test) : class_cleanup_attribute(#method_name, test, &method_name, {__FILE__, __LINE__, __func__}) {__##method_name##_static();} \
  } __class_cleanup_attribute {*this}; \
  static void method_name()

