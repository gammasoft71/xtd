/// @file
/// @brief Contains google test markers definitions.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TUNIT_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/unused.h>

/// @cond
// The following variables are a hack to ensure that GoogleTestAdapter (Microsoft Visual Studio) will detect the tunit application as a google test application...
// See https://github.com/csoltenborn/GoogleTestAdapter/blob/master/GoogleTestAdapter/Core/GoogleTestConstants.cs
inline static const char* __test_body_signature__ = "::TestBody";
inline static const char* __parameterized_test_marker__ = "  # GetParam() = ";
inline static const char* __typed_test_marker__ = ".  # TypeParam = ";
inline static const char* __google_test_dll_marker__ = "gtest.dll";
inline static const char* __google_test_dll_marker_debug__ = "gtestd.dll";
inline static const char* __google_test_main_dll_marker__ = "gtest_main.dll";
inline static const char* __google_test_main_dll_marker_debug__ = "gtest_maind.dll";
inline static const char* __google_test_executable_markers__[] = {
  "This program contains tests written using Google Test. You can use the",
  "For more information, please read the Google Test documentation at",
  "Run only the tests whose name matches one of the positive patterns but",
  "--gtest_list_tests"
};

inline void __unused_google_test_markers__() {
  unused_(__test_body_signature__);
  unused_(__parameterized_test_marker__);
  unused_(__typed_test_marker__);
  unused_(__google_test_dll_marker__);
  unused_(__google_test_dll_marker_debug__);
  unused_(__google_test_main_dll_marker__);
  unused_(__google_test_main_dll_marker_debug__);
  unused_(__google_test_executable_markers__);
}
/// @endcond
