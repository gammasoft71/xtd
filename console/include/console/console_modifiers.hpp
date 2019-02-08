/// @file
/// @brief Contains xtd::console_modifiers enum.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Represents the SHIFT, ALT, and CTRL modifier keys on a keyboard.
  /// @see Console
  enum class console_modifiers {
    /// @brief The left or right ALT modifier key.
    alt = 0b1,
    /// @brief The left or right SHIFT modifier key.
    shift = 0b10,
    /// @brief The left or right CTRL modifier key.
    control = 0b100
  };
}

