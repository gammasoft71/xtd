/// @file
/// @brief Contains xtd::build_type enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/strings.h>
#undef unix

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the buil type
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see compileer
  enum class build_type {
    /// @brief Build type debug.
    debug = 0,
    /// @brief Build type release.
    release,
  };

  inline std::ostream& operator<<(std::ostream& os, build_type value) {return os << to_string(value, {{build_type::debug, "debug"}, {build_type::release, "release"}});}
  inline std::wostream& operator<<(std::wostream& os, build_type value) {return os << to_string(value, {{build_type::debug, L"debug"}, {build_type::release, L"release"}});}
}
