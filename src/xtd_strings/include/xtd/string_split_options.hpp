/// @file
/// @brief Contains xtd::string_split_options enum class.
#pragma once

#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Specifies whether applicable strings::Split method overloads include or omit empty substrings from the return value.
  /// @see xtd::strings
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
