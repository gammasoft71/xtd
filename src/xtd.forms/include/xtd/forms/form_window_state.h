/// @file
/// @brief Contains xtd::forms::form_window_state enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a form window is displayed.
    /// @par Header
    /// @code #include <xtd/forms/form_window_state> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the form class. It represents the different states of the form. The default state is normal.
    enum class form_window_state {
      /// @brief A default sized window.
      normal = 0,
      /// @brief A minimized window.
      minimized = 1,
      /// @brief A maximized window.
      maximized = 2,
      /// @brief A full screen window.
      full_screen = 3,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::form_window_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::form_window_state> {{xtd::forms::form_window_state::normal, "normal"}, {xtd::forms::form_window_state::minimized, "minimized"}, {xtd::forms::form_window_state::maximized, "maximized"}, {xtd::forms::form_window_state::full_screen, "full_screen"}};}
};
/// @endcond
