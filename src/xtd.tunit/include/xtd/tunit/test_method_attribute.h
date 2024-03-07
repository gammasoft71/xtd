/// @file
/// @brief Contains xtd::tunit::test_method_attribute class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "test.h"
#include "test_state.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents a test method attribute.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks The test method is the method that performs the unit test.
    /// @par Examples
    /// The following example shows how to use xtd::tunit::test_method_attribute class.
    /// @include test_class_without_helpers.cpp
    class test_method_attribute {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates a new instance of test_method_attribute with specified name, test_class, and method.
      /// @param name The name of the test method attribute.
      /// @param test_class The test_class that will contians the test method attribute.
      /// @param method The test method.
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)()) noexcept : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, xtd::diagnostics::stack_frame()) {}
      
      /// @brief Creates a new instance of test_method_attribute with specified name, test_class, method, and stack frame.
      /// @param name The name of the test method attribute.
      /// @param test_class The test_class that will contians the test method attribute.
      /// @param method The test method.
      /// @param stack_frame The stack frame of test method.
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)(), const xtd::diagnostics::stack_frame& stack_frame) noexcept : test_method_attribute(name, test_class, method, xtd::tunit::test_state::considered, stack_frame) {}
      
      /// @brief Creates a new instance of test_method_attribute with specified name, test_class, method, and tes state.
      /// @param name The name of the test method attribute.
      /// @param test_class The test_class that will contians the test method attribute.
      /// @param method The test method.
      /// @param test_state One of xtd::tunit_test_state values.
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)(), xtd::tunit::test_state test_state) noexcept : test_method_attribute(name, test_class, method, test_state, xtd::diagnostics::stack_frame()) {}
      
      /// @brief Creates a new instance of test_method_attribute with specified name, test_class, method, stack frame and tes state.
      /// @param name The name of the test method attribute.
      /// @param test_class The test_class that will contians the test method attribute.
      /// @param method The test method.
      /// @param test_state One of xtd::tunit_test_state values.
      /// @param stack_frame The stack frame of test method.
      template<typename test_class_t>
      test_method_attribute(const std::string& name, test_class_t& test_class, void (test_class_t::*method)(), xtd::tunit::test_state test_state, const xtd::diagnostics::stack_frame& stack_frame) noexcept {test_class.add_test_method({name, std::bind(method, &test_class), test_state == xtd::tunit::test_state::ignored, stack_frame});}
      /// @}
    };
  }
}

/// @brief Add ignored test method to class test.
/// @param method_name The ignored test method to add.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @remarks This helper is used to ingor a test method. You can use the xtd::tunit::assert::ignore method instead.
/// @par Examples
/// The following example shows how to use #ignore_test_method_ helper.
/// @include test_class.cpp
#define ignore_test_method_(method_name) \
  __##method_name##_unused() = delete; \
  class __##method_name##_attribute##_class : public xtd::tunit::test_method_attribute { \
  public:\
    template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, xtd::tunit::test_state::ignored, {__FILE__, __LINE__, __func__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()

/// @brief Add test method to class test.
/// @param method_name The test method to add.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following example shows how to use #test_method_ helper.
/// @include test_class.cpp
#define test_method_(method_name) \
  __##method_name##_unused() = delete; \
  class __##method_name##_attribute##_class : public xtd::tunit::test_method_attribute { \
  public:\
    template<typename test_class> __##method_name##_attribute##_class(test_class& test) : test_method_attribute(#method_name, test, &test_class::method_name, {__FILE__, __LINE__, __func__}) {} \
  } __##method_name##_attribute {*this}; \
  void method_name()
