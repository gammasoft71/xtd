/// @file
/// @brief Contains xtd::string_comparison enum class.
#pragma once

#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Specifies the culture, case, and sort rules to be used by certain overloads of the strings::compare(string, string) method
  /// @see xtd::strings
  enum class string_comparison {
    /// @brief Compare strings using ordinal (binary) sort rules.
    ordinal,
    /// @brief Compare strings using ordinal (binary) sort rules and ignoring the case of the strings being compared.
    ordinal_ignore_case
  };
}

inline std::ostream& operator<<(std::ostream& os, xtd::string_comparison sc) {
  switch (sc) {
    case xtd::string_comparison::ordinal: os << "ordinal"; break;
    case xtd::string_comparison::ordinal_ignore_case: os << "ordinal_ignore_case"; break;
  }
  return os;
}
