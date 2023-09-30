/// @file
/// @brief Contains xtd::tunit::test_cleanup_attribute class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "test.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents a test cleanup attribute.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks The test cleanup method is the method that is called right after a test method is finished. It is called for each test.
    /// @par Examples
    /// The following example shows how to use xtd::tunit::test_cleanup_attribute class.
    /// @include test_class_without_helpers.cpp
    class test_cleanup_attribute {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates a new instance of test_cleanup_attribute with specified name, test_class and method.
      /// @param name The name of the test cleanups attribute.
      /// @param test_class The test_class that will contians the test cleanup attribute.
      /// @param method The test cleanup method.
      template<typename test_class_t>
      test_cleanup_attribute(const std::string& name, test_class_t& test_class, void (*method)()) noexcept :  test_cleanup_attribute(name, test_class, method, xtd::diagnostics::stack_frame()) {}
      
      /// @brief Creates a new instance of test_cleanup_attribute with specified name, test class, method and stack frame.
      /// @param name The name of the test class attribute.
      /// @param test_class The test_class that will contians the test cleanup attribute.
      /// @param method The test cleanup method.
      /// @param stack_frame The stack frame of test cleanup method.
      template<typename test_class_t>
      test_cleanup_attribute(const std::string& name, test_class_t& test_class, void (*method)(), const xtd::diagnostics::stack_frame& stack_frame) noexcept {test_class.add_test_cleanup({name, method, stack_frame});}
      /// @}
    };
  }
}

/// @brief Helper to create a test cleanup method in a test class.
/// @param method_name The test cleanup method to add.
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following example shows how to use #test_cleanup_ helper.
/// @include test_class.cpp
#define test_cleanup_(method_name) \
  __##method_name##_unused() = delete; \
  class __test_cleanup_attribute : public xtd::tunit::test_cleanup_attribute { \
  public:\
    template<typename test_class> __test_cleanup_attribute(test_class& test) : test_cleanup_attribute(#method_name, test, &test_class::method_name, {__FILE__, __LINE__, __func__}) {} \
  } __test_cleanup_attribute {*this}; \
  static void method_name()
