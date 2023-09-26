/// @file
/// @brief Contains xtd::forms::flat_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a control.
    /// @par Header
    /// @code #include <xtd/forms/flat_style> @endcode
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::flat_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::flat_style> {{xtd::forms::flat_style::flat, "flat"}, {xtd::forms::flat_style::popup, "popup"}, {xtd::forms::flat_style::standard, "standard"}, {xtd::forms::flat_style::system, "system"}};}
};
/// @endcond
