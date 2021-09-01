/// @file
/// @brief Contains xtd::cnull ostream.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/// @cond
int __get_file_attributes(const char*path);
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides a null std::ostream.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  inline std::ostream cnull(nullptr);
}
