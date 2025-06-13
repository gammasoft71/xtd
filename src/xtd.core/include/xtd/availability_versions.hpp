/// @file
/// @brief Contains availability versions.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @cond
// Availability versions

// xtd version definition : major.minor[.build[.revision]]
// * major    : 0 to 2147483647
// * minor    : 0 to 99
// * build    : 0 to 99
// * revision : 0 to 99

// For example xtd 1.2.3 (major = 1, minor = 2, build = 3 and revision = -1) :
// #define __XTD_1_2_3__ 1020300

// Example
// The following code shows how to used availability versions.
//
// #include <xtd/xtd>
//
// auto main() -> int {
// #if defined(__XTD_42_42_42__)
//   auto s = xtd::xstring("Hello, World!");
// #elif defined(__XTD_0_2_0__)
//   auto s = xtd::string("Hello, World!");
// #else
//   auto s = xtd::ustring("Hello, World!");
// #endif
//   xtd::console::write_line(s);
// }

#define __XTD_0_1_0__ 10000
#define __XTD_0_1_1__ 10100
#define __XTD_0_1_2__ 10200
#define __XTD_0_2_0__ 20000
/// @endcond
