/// @file
/// @brief Contains xtd::tunit::register_test_class_types class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "test_class_attribute.hpp"
#include <xtd/typeof>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents the register test class types.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @par Examples
    /// The following example shows how to regeister types for a specified test class.
    /// ```cpp
    /// #include <xtd/tunit/tunit>
    ///
    /// template<typename type_t>
    /// class vector_tests;
    ///
    /// auto register_vector_tests = register_test_class_types<vector_tests, int, char, bool> {};
    ///
    /// template<typename type_t>
    /// class vector_tests : public test_class {
    ///    auto test_method_(default_constructor) {
    ///      auto v = std::vector<type_t> {};
    ///      collection_assert::is_empty(v);
    ///    }
    /// };
    /// ```
    template<template<typename> class test_class_t, typename... args_t>
    class register_test_class_types;
    
    /// @cond
    template<template<typename> class test_class_t, typename arg_t, typename... args_t>
    class register_test_class_types<test_class_t, arg_t, args_t...> {
      test_class_attribute<test_class_t<arg_t>> attr {typeof_<test_class_t<arg_t>>().name()};
      register_test_class_types<test_class_t, args_t...> next;
    };
    
    template<template<typename> class test_class_t>
    class register_test_class_types<test_class_t> {};
    /// @endcond
  }
}
