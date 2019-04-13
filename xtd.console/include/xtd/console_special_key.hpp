/// @file
/// @brief Contains xtd::console_special_key enum.
#pragma once
#include <string>
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies combinations of modifier and console keys that can interrupt the current process.
  /// @remarks The ConsoleCancelEventArgs::SpecialKey property returns the console_special_key enumeration type.
  /// @remarks Simultaneously pressing certain key combinations signals the operating system to interrupt the currently running process. The two valid key combinations are console_modifiers::control plus BREAK (CTRL+BREAK) and console_modifiers::Control plus console_key.c (CTRL+C).
  enum class console_special_key {
    /// @brief The console_modifiers::control modifier key plus the BREAK console key.
    control_break,
    /// @brief The console_modifiers::control modifier key plus the console_key C console key.
    control_c,
    /// @brief The console_modifiers::control modifier key plus the console_key \\ console key.
    control_backslash,
    /// @brief The console_modifiers::control modifier key plus the console_key Z console key.
    control_z,
  };
}

/// @cond
template<typename Char>
std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, xtd::console_special_key sk) {
  switch (sk) {
    case xtd::console_special_key::control_break: os << std::basic_string<Char> {'c', 'o', 'n', 't', 'r', 'o', 'l', '_', 'b', 'r', 'e', 'a', 'k'}; break;
    case xtd::console_special_key::control_c: os << std::basic_string<Char> {'c', 'o', 'n', 't', 'r', 'o', 'l', '_', 'c'}; break;
    case xtd::console_special_key::control_backslash: os << std::basic_string<Char> {'c', 'o', 'n', 't', 'r', 'o', 'l', '_', 'b', 'a', 'c', 'k', 's', 'l', 'a', 's', 'h'}; break;
    case xtd::console_special_key::control_z: os << std::basic_string<Char> {'c', 'o', 'n', 't', 'r', 'o', 'l', '_', 'z'}; break;
    default: os << static_cast<int>(sk); break;
  }
  return os;
}
/// @endcond
