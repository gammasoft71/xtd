/// @file
/// @brief Contains xtd::build_type enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the build type
  /// @par Header
  /// @code #include <xtd/build_type> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see compiler
  enum class build_type {
    /// @brief Build type debug.
    debug = 0,
    /// @brief Build type release.
    release,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::build_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::build_type> {{xtd::build_type::debug, "debug"}, {xtd::build_type::release, "release"}};}
};
/// @endcond
