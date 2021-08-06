/// @file
/// @brief Contains xtd::forms::form_border_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the border styles for a form.
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

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, form_border_style value) {return os << to_string(value, {{form_border_style::none, "none"}, {form_border_style::fixed_single, "fixed_single"}, {form_border_style::fixed_3d, "fixed_3d"}, {form_border_style::fixed_dialog, "fixed_dialog"}, {form_border_style::sizable, "sizable"}, {form_border_style::fixed_tool_window, "fixed_tool_window"}, {form_border_style::sizable_tool_window, "sizable_tool_window"}});}
    inline std::wostream& operator<<(std::wostream& os, form_border_style value) {return os << to_string(value, {{form_border_style::none, L"none"}, {form_border_style::fixed_single, L"fixed_single"}, {form_border_style::fixed_3d, L"fixed_3d"}, {form_border_style::fixed_dialog, L"fixed_dialog"}, {form_border_style::sizable, L"sizable"}, {form_border_style::fixed_tool_window, L"fixed_tool_window"}, {form_border_style::sizable_tool_window, L"sizable_tool_window"}});}
    /// @endcond
  }
}
