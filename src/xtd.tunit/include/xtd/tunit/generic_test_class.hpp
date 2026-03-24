/// @file
/// @brief Contains #generic_test_class_ helper.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "register_test_class_types.hpp"

/// @brief Helper to create a generic test_class in a test unit.
/// @param class_name The test class to add to unit test.
/// @param ... type list.
/// @ingroup xtd_tunit tunit
/// @par Examples
/// The following example shows how to use #generic_test_class_ helper.
/// ```cpp
/// #include <xtd/tunit/tunit>
///
/// generic_test_class_(vector_tests, int, char, bool) {
///    auto test_method_(default_constructor) {
///      auto v = std::vector<type_t> {};
///      collection_assert::is_empty(v);
///    }
/// };
/// ```
#define generic_test_class_(class_name, ...) \
  template<typename type_t> \
  class class_name; \
  inline auto __register_##class_name = register_test_class_types<class_name, __VA_ARGS__> {}; \
  template<typename type_t> \
  class class_name : public test_class
