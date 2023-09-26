/// @file
/// @brief Contains xtd::forms::form_border_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the border styles for a form.
    /// @par Header
    /// @code #include <xtd/forms/form_border_style> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the form class. It represents the different styles of the form. The default style is sizable.
    enum class form_border_style {
      /// @brief No border.
      none = 0,
      /// @brief A fixed, single-line border.
      fixed_single = 1,
      /// @brief A fixed, three-dimensional border.
      fixed_3d = 2,
      /// @brief A thick, fixed dialog-style border.
      fixed_dialog = 3,
      /// @brief A resizable border.
      sizable = 4,
      /// @brief A tool window border that is not resizable. A tool window does not appear in the taskbar or in the window that appears when the user presses ALT+TAB. Although forms that specify fixed_tool_window typically are not shown in the taskbar, you must also ensure that the show_in_taskbar property is set to false, since its default value is true.
      fixed_tool_window = 5,
      /// @brief A resizable tool window border. A tool window does not appear in the taskbar or in the window that appears when the user presses ALT+TAB.
      sizable_tool_window = 6,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::form_border_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::form_border_style> {{xtd::forms::form_border_style::none, "none"}, {xtd::forms::form_border_style::fixed_single, "fixed_single"}, {xtd::forms::form_border_style::fixed_3d, "fixed_3d"}, {xtd::forms::form_border_style::fixed_dialog, "fixed_dialog"}, {xtd::forms::form_border_style::sizable, "sizable"}, {xtd::forms::form_border_style::fixed_tool_window, "fixed_tool_window"}, {xtd::forms::form_border_style::sizable_tool_window, "sizable_tool_window"}};}
};
/// @endcond
