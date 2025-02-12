/// @file
/// @brief Contains xtd::argument_collection alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "array.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the collection of arguments passed to the main entry point method.
  /// @par Header
  /// ```cpp
  /// #include <xtd/argument_collection>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  using argument_collection = xtd::array<xtd::string>;
}
