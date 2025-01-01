/// @file
/// @brief Contains xtd::cnull ostream.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "types.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/// @cond
xtd::int32 __get_file_attributes(const char* path);
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides a null std::ostream.
  /// @par Header
  /// ```cpp
  /// #include <xtd/cnull>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cnull(nullptr);
}
