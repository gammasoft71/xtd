/// @file
/// @brief Contains xtd::forms::control_appearance enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class control_appearance {
      /// @brief The appearance of the control is determined by current theme of xtd.
      standard = 0,
      /// @brief The appearance of the control is determined by the user's operating system.
      system,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, control_appearance value) {return os << to_string(value, {{control_appearance::standard, "standard"}, {control_appearance::system, "system"}});}
    inline std::wostream& operator<<(std::wostream& os, control_appearance value) {return os << to_string(value, {{control_appearance::standard, L"standard"}, {control_appearance::system, L"system"}});}
    /// @endcond
  }
}
