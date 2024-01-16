/// @cond

/// @file
/// @brief Contains gtest helpers.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "xtd.tunit.h"

#if !defined(__XTD_EXPERIMENTAL_GTEST_HELPERS__)
#error "Do not use this file: it is for experimental purposes only"
#endif

namespace testing {
  void InitGoogleTest() {xtd::tunit::settings::default_settings().gtest_compatibility(true);}
  void InitGoogleTest(int argc, char* argv[]) {InitGoogleTest();}
}

#define ASSERT_EQ(val1, val2) xtd::tunit::assert::are_equal(val1, val2, csf_)
#define ASSERT_NE(val1, val2) xtd::tunit::assert::are_not_equal(val1, val2, csf_)
#define ASSERT_FALSE(condition) xtd::tunit::assert::is_false(condition, csf_)
#define ASSERT_TRUE(condition) xtd::tunit::assert::is_true(condition, csf_)

#define EXPECT_FALSE(condition) xtd::tunit::assume::is_false(condition, csf_)
#define EXPECT_TRUE(condition) xtd::tunit::assume::is_true(condition, csf_)

#define RUN_ALL_TESTS xtd::tunit::console_unit_test().run

#define TEST(class_name, method_name) \
  void __##class_name##method_name(); \
  class __class_##class_name##_##method_name; \
  xtd::tunit::test_class_attribute<__class_##class_name##_##method_name> __class_##class_name##_##method_name##_attr {typeof_<__class_##class_name##_##method_name>().full_name().replace(typeof_<__class_##class_name##_##method_name>().name(), "") + #class_name}; \
  class __class_##class_name##_##method_name : public xtd::tunit::test_class { \
    xtd::tunit::test_method_attribute __class_##class_name##_##method_name##_method {#method_name, *this, &__class_##class_name##_##method_name::__method}; \
    void __method() { \
      if (xtd::ustring {#method_name}.starts_with("DISABLED_")) xtd::tunit::assert::ignore();\
      __##class_name##method_name(); \
    } \
  }; \
  void __##class_name##method_name()

/// @endcond
