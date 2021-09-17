/// @file
/// @brief Contains xtd::string_split_options enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies whether applicable xtd::ustring::split method overloads include or omit empty substrings from the return value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::ustring
  enum class string_split_options {
    /// @brief The return value includes array elements that contain an empty string.
    none,
    /// @brief The return value does not include array elements that contain an empty string.
    remove_empty_entries
  };

  inline std::ostream& operator<<(std::ostream& os, xtd::string_split_options options) {
    switch (options) {
      case xtd::string_split_options::none: os << "none"; break;
      case xtd::string_split_options::remove_empty_entries: os << "remove_empty_entries"; break;
    }
    return os;
  }
}
