/// @file
/// @brief Contains xtd::forms::form_start_position enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the initial position of a form.
    /// @par Header
    /// @code #include <xtd/forms/form_start_position> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the start_position property of the form class. It represents the different start positions of the form. The default start position is windows_default_location.
    enum class form_start_position {
      /// @brief The position of the form is determined by the Location property.
      manual = 0,
      /// @brief The form is centered on the current display, and has the dimensions specified in the form's size.
      center_screen = 1,
      /// @brief The form is positioned at the Windows default location and has the dimensions specified in the form's size.
      windows_default_location = 2,
      /// @brief The form is positioned at the Windows default location and has the bounds determined by Windows default.
      windows_default_bounds = 3,
      /// @brief The form is centered within the bounds of its parent form.
      center_parent = 4,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::form_start_position> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::form_start_position> {{xtd::forms::form_start_position::manual, "manual"}, {xtd::forms::form_start_position::center_screen, "center_screen"}, {xtd::forms::form_start_position::windows_default_location, "windows_default_location"}, {xtd::forms::form_start_position::windows_default_bounds, "windows_default_bounds"}, {xtd::forms::form_start_position::center_parent, "center_parent"}};}
};
/// @endcond
