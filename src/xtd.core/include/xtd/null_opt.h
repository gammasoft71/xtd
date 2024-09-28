/// @file
/// @brief Contains xtd::null_opt alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "optional.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the null_opt alias on [std::nullopt_t](https://en.cppreference.com/w/cpp/utility/optional/nullopt_t).
  /// @par Header
  /// ```cpp
  /// #include <xtd/null_opt>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using null_opt = std::nullopt_t;
}
