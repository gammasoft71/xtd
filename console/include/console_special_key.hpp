/// @file
/// @brief Contains Switch::System::ConsoleSpecialKey enum.
#pragma once

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  /// @brief Specifies combinations of modifier and console keys that can interrupt the current process.
  /// @par Library
  /// Switch.Core
  /// @ingroup SwitchCore
  /// @remarks The ConsoleCancelEventArgs.SpecialKey property returns the ConsoleSpecialKey enumeration type.
  /// @remarks Simultaneously pressing certain key combinations signals the operating system to interrupt the currently running process. The two valid key combinations are ConsoleModifiers.Control plus BREAK (CTRL+BREAK) and ConsoleModifiers.Control plus ConsoleKey.C (CTRL+C).
  enum class console_special_key {
    /// @brief The ConsoleModifiers.Control modifier key plus the BREAK console key.
    control_break,
    /// @brief The ConsoleModifiers.Control modifier key plus the ConsoleKey C console key.
    control_c,
    /// @brief The ConsoleModifiers.Control modifier key plus the ConsoleKey \\ console key.
    control_backslash,
    /// @brief The ConsoleModifiers.Control modifier key plus the ConsoleKey Z console key.
    control_z,
  };
}
