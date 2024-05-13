/// @file
/// @brief Contains xtd::tunit::class_cleanup_attribute class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "test.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief This attribute is use to add cleanup class method to class test attribute.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks The class cleanup method is the method that is called just after all the tests are finished. It is called only once.
    /// @par Examples
    /// The following example shows how to use xtd::tunit::class_initialize_attribute class.
    /// @include test_class_without_helpers.cpp
    class class_cleanup_attribute {
    public:
      /// @name Public Constructors
      
      /// @{
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
      /// @}
    };
  }
}

/// @brief Add class cleanup method to class test.
/// @param method_name The class cleanup method to add.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following example shows how to use #class_cleanup_ helper.
/// @include test_class.cpp
#define class_cleanup_(method_name) \
  __##method_name##_static() {} \
  class __class_cleanup_attribute : public xtd::tunit::class_cleanup_attribute { \
  public: \
    template<typename test_class> __class_cleanup_attribute(test_class& test) : class_cleanup_attribute(#method_name, test, &method_name, {__FILE__, __LINE__, __func__}) {__##method_name##_static();} \
  } __class_cleanup_attribute {*this}; \
  static void method_name()

