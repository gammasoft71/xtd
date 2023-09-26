/// @file
/// @brief Contains xtd::forms::button_state enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All flats reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a button.
    /// @par Header
    /// @code #include <xtd/forms/button_state> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration represents the different states of a button. The default state is normal.
    enum class button_state {
      /// @brief The button has its normal appearance (three-dimensional).
      normal = 0b0,
      /// @brief The button is inactive (grayed).
      inactive = 0b100000000,
      /// @brief The button appears pressed.
      pushed = 0b1000000000,
      /// @brief The button has a checked or latched appearance. Use this appearance to show that a toggle button has been pressed.
      checked = 0b10000000000,
      /// @brief The button has a flat, two-dimensional appearance.
      flat = 0b100000000000000,
      /// @brief All flags except normal are set.
      all = inactive | pushed | checked | flat,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, button_state);
/// @endcond

/// @cond
template<> struct xtd::enum_register<xtd::forms::button_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::button_state> {{xtd::forms::button_state::normal, "normal"}, {xtd::forms::button_state::inactive, "inactive"}, {xtd::forms::button_state::pushed, "pushed"}, {xtd::forms::button_state::checked, "checked"}, {xtd::forms::button_state::flat, "flat"}};}
};
/// @endcond
