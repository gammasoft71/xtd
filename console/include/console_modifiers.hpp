/// @file
/// @brief Contains console_modifiers enum.
#pragma once

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  /// @brief Represents the SHIFT, ALT, and CTRL modifier keys on a keyboard.
  /// @par Library
  /// Switch.Core
  /// @ingroup SwitchCore
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

