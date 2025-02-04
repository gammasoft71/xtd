/// @file
/// @brief Contains xtd::native_array alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "optional.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a native array alias.
  /// @par Header
  /// ```cpp
  /// #include <xtd/native_array>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  template<class type_t>
  using native_array = type_t[];
}
