/// @file
/// @brief Contains xtd::tunit::generic_test_class_ helper.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "register_test_class_types.hpp"

#define generic_test_class_(test_class_type, ...) \
  template<class type_t> \
  class test_class_type; \
  auto register_##test_class_type = register_test_class_types<test_class_type, __VA_ARGS__> {}; \
  template<class type_t> \
  class test_class_type : public test_class
