/// @file
/// @brief Contains xtd::forms::dialog_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the style of a dialog.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class dialog_style {
      /// @brief Standard style dialog.
      standard = 0,
      /// @brief System style dialog.
      system = 1,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, dialog_style value) {return os << to_string(value, {{dialog_style::standard, "standard"}, {dialog_style::system, "system"}});}
    inline std::wostream& operator<<(std::wostream& os, dialog_style value) {return os << to_string(value, {{dialog_style::standard, L"standard"}, {dialog_style::system, L"system"}});}
    /// @endcond
  }
}
