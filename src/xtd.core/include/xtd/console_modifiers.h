/// @file
/// @brief Contains xtd::console_modifiers enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the SHIFT, ALT, and CTRL modifier keys on a keyboard.
  /// @par Header
  /// @code #include <xtd/console_modifiers> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see Console
  enum class console_modifiers {
    /// @brief No modifier key.
    none = 0,
    /// @brief The left or right ALT modifier key.
    alt = 0b1,
    /// @brief The left or right SHIFT modifier key.
    shift = 0b10,
    /// @brief The left or right CTRL modifier key.
    control = 0b100
  };
}

/// @cond
flags_attribute_(xtd, console_modifiers);

template<> struct xtd::enum_register<xtd::console_modifiers> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::console_modifiers> {{xtd::console_modifiers::none, "none"}, {xtd::console_modifiers::alt, "alt"}, {xtd::console_modifiers::shift, "shift"}, {xtd::console_modifiers::control, "control"}};}
};
/// @endcond

