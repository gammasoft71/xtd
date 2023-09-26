/// @file
/// @brief Contains xtd::forms::input_box_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which input_box style is used.
    /// @par Header
    /// @code #include <xtd/forms/input_box_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the input_box class.
    enum class input_box_style {
      /// @brief Single line text box.
      normal,
      /// @brief Multiline text box.
      multiline,
      /// @brief Single line text box with password characters.
      password
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::input_box_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::input_box_style> {{xtd::forms::input_box_style::normal, "normal"}, {xtd::forms::input_box_style::multiline, "multiline"}, {xtd::forms::input_box_style::password, "password"}};}
};
/// @endcond
