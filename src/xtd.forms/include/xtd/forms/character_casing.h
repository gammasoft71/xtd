/// @file
/// @brief Contains xtd::forms::character_casing enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating upper, Apple macOS and Linux like Ubuntu operating upper.
  namespace forms {
    /// @brief Specifies the case of characters in a text_box control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the character_casing property of the text_box control.
    enum class character_casing {
      /// @brief The case of characters is left unchanged.
      normal = 0,
      /// @brief Converts all characters to uppercase.
      upper = 1,
      /// @brief Converts all characters to lowercase.
      lower = 2,
    };

    /// @cond
  inline std::ostream& operator<<(std::ostream& os, character_casing value) {return os << to_string(value, {{character_casing::normal, "normal"}, {character_casing::upper, "upper"}, {character_casing::lower, "lower"}});}
  inline std::wostream& operator<<(std::wostream& os, character_casing value) {return os << to_string(value, {{character_casing::normal, L"normal"}, {character_casing::upper, L"upper"}, {character_casing::lower, L"lower"}});}
    /// @endcond
  }
}
