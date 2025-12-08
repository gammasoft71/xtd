/// @file
/// @brief Contains unit test application main entry point #tunit_main_ definition.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/startup>
#include <xtd/static>
#include "../tunit_export.hpp"

/// @cond
struct tunit_export_ __tunit_main final static_ {
  static auto main() -> int;
  static auto main_with_gtest_compatibility() -> int;
};
/// @endcond

/// @brief Defines the entry point to be called with #startup_ for unit test application.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @remarks The #tunit_main_ contains a main method and launch xtd::tunit::console_unit_test::run.
/// @par Examples
/// The followng code shows ho to use #tunit_main_.
/// ```cpp
/// #include <xtd/xtd.tunit>
///
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   test_class_(class_to_test) {
///   public:
///     auto test_method_(test1) {
///       // Do test...
///     }
///   };
/// }
///
/// startup_(tunit_main_);
/// ```
#define tunit_main_ \
  __tunit_main::main

/// @brief Defines the entry point to be called with #startup_ for unit test application with Google test compatibility.
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit tunit
/// @remarks The #tunit_main_  contains main method, launch xtd::tunit::console_unit_test::run and set xtd::tunit::settings::gtest_compatibility to `true`.
/// @par Examples
/// The followng code shows ho to use #tunit_main_with_gtest_compatibility_.
/// ```cpp
/// #include <xtd/xtd.tunit>
///
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   test_class_(class_to_test) {
///   public:
///     auto test_method_(test1) {
///       // Do test...
///     }
///   };
/// }
///
/// startup_(tunit_main_with_gtest_compatibility_);
/// ```
#define tunit_main_with_gtest_compatibility_ \
  __tunit_main::main_with_gtest_compatibility
