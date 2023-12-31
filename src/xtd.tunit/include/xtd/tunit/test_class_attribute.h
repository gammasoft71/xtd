/// @file
/// @brief Contains xtd::tunit::test_class_attribute class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "unit_test.h"
#include <memory>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents a test class attribute.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks The test class attribute is used to to declare a test class in a unit test. It is called for each test.
    /// @par Examples
    /// The following example shows how to use xtd::tunit::test_class_attribute class.
    /// @include test_class_without_helpers.cpp
    template <typename test_class_t>
    class test_class_attribute final {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates a new instance of test_class_attribute with specified name.
      /// @param name The name of the test class attribute.
      explicit test_class_attribute(const std::string& name) noexcept {xtd::tunit::unit_test::add({name, std::make_shared<test_class_t>()});}
      /// @}
    };
  }
}

/// @brief Helper to create a test_class in a test unit.
/// @param class_name The test class to add to unit test.
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following example shows how to use #test_class_ helper.
/// @include test_class.cpp
#define test_class_(class_name) \
  class_name;\
  xtd::tunit::test_class_attribute<class_name> __##class_name##_attribute {#class_name}; \
  class class_name : public xtd::tunit::test_class

/// @brief Helper to create a test_class in a test unit from a specified class base.
/// @param class_name The name of the test class.
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following code show how to create a test class @c derived_class inherited from @c base_class :
/// @code
/// #include <xtd/xtd.tunit>
///
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   test_class_(base_class) {
///   public:
///     void test_method_(test1) {
///       // Do test...
///     }
///   };
///
///   test_class_from_(derived_class, base_class) {
///   public:
///     void test_method_(test2) {
///       // Do test...
///     }
///   };
/// }
///
/// auto main()->int {
///   return console_unit_test().run();
/// }
/// @endcode
#define test_class_from_(class_name, from_class_name) \
  class_name;\
  xtd::tunit::test_class_attribute<class_name> __##class_name##_attribute {#class_name}; \
  class class_name : public from_class_name
