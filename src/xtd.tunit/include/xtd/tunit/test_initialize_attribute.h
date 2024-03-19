/// @file
/// @brief Contains xtd::tunit::test_initialize_attribute class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/diagnostics/stack_frame>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents a test initialize attribute.
    /// @remarks The test initialize method is the method that is called just before a test method starts.
    /// @par Examples
    /// The following example shows how to use xtd::tunit::test_initialize_attribute class.
    /// @include test_class_without_helpers.cpp
    class test_initialize_attribute {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates a new instance of test_initialize_attribute with specified name, test_class and method.
      /// @param name The name of the test initialize attribute.
      /// @param test_class The test_class that will contians the test initialize attribute.
      /// @param method The test initialize method.
      template<typename test_class_t>
      test_initialize_attribute(const xtd::ustring& name, test_class_t& test_class, void (*method)()) noexcept :  test_initialize_attribute(name, test_class, method, xtd::diagnostics::stack_frame()) {}
      
      /// @brief Creates a new instance of test_initialize_attribute with specified name, test_class and method.
      /// @param name The name of the test initialize attribute.
      /// @param test_class The test_class that will contians the test initialize attribute.
      /// @param method The test initialize method.
      /// @param stack_frame The stack frame of test initialize method.
      template<typename test_class_t>
      test_initialize_attribute(const xtd::ustring& name, test_class_t& test_class, void (*method)(), const xtd::diagnostics::stack_frame& stack_frame) noexcept {test_class.add_test_initialize({name, method, stack_frame});}
      /// @}
    };
  }
}

/// @brief Helper to create a test initialize method in a test class.
/// @param method_name The name of the test initialize method.
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following example shows how to use #test_initialize_ helper.
/// @include test_class.cpp
#define test_initialize_(method_name) \
  __##method_name##_unused() = delete; \
  class __test_initialize_attribute : public xtd::tunit::test_initialize_attribute { \
  public:\
    template<typename test_class> __test_initialize_attribute(test_class& test) : test_initialize_attribute(#method_name, test, &test_class::method_name, {__FILE__, __LINE__, __func__}) {} \
  } __test_initialize_attribute {*this}; \
  static void method_name()

