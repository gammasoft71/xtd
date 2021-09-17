/// @file
/// @brief Contains xtd::forms::flat_style enum class.
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
    /// @remarks This enumeration is used by members such as button_base::flat_style, group_box::flat_style, and label::flat_style.
    /// @remarks In the case of the popup style button, this enumeration controls some behavior as well as appearance. The popup style control initially appears flat until the mouse pointer moves over it. When the mouse pointer moves over the popup control, it appears as a standard style control until the mouse pointer is moved off of it again.
    /// @remarks If the system style is used, the appearance of the control is determined by the user's operating system and the following property values will be ignored: control_background_image, image_align, image, image_index, image_list, and text_align. In addition, the control.back_color property will be ignored for button controls. If supported, users can change the appearance of controls by adjusting the appearance settings of their operating system.
    enum class flat_style {
      /// @brief The control appears flat.
      flat = 0,
      /// @brief A control appears flat until the mouse pointer moves over it, at which point it appears three-dimensional.
      popup,
      /// @brief The control appears three-dimensional.
      standard,
      /// @brief The appearance of the control is determined by the user's operating system.
      system,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, flat_style value) {return os << to_string(value, {{flat_style::flat, "flat"}, {flat_style::popup, "popup"}, {flat_style::standard, "standard"}, {flat_style::system, "system"}});}
    inline std::wostream& operator<<(std::wostream& os, flat_style value) {return os << to_string(value, {{flat_style::flat, L"flat"}, {flat_style::popup, L"popup"}, {flat_style::standard, L"standard"}, {flat_style::system, L"system"}});}
    /// @endcond
  }
}
