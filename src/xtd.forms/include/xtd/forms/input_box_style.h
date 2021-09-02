/// @file
/// @brief Contains xtd::forms::input_box_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which input_box style is used.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the input_box class.
    enum class input_box_style {
      /// @brief Single line text boox.
      normal,
      /// @brief Multiline text box.
      multiline,
      /// @brief Single line text box with password characters.
      password
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, input_box_style value) {return os << to_string(value, {{input_box_style::normal, "normal"}, {input_box_style::multiline, "multiline"}, {input_box_style::password, "password"}});}
    inline std::wostream& operator<<(std::wostream& os, input_box_style value) {return os << to_string(value, {{input_box_style::normal, L"normal"}, {input_box_style::multiline, L"multiline"}, {input_box_style::password, L"password"}});}
    /// @endcond
  }
}
