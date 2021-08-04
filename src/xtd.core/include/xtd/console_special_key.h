/// @file
/// @brief Contains xtd::console_special_key enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <sstream>
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies combinations of modifier and console keys that can interrupt the current process.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
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

  /// @cond
  inline std::ostream& operator<<(std::ostream& os, console_special_key value) {return os << to_string(value, {{console_special_key::control_break, "control_break"}, {console_special_key::control_c, "control_c"}, {console_special_key::control_backslash, "control_backslash"}, {console_special_key::control_z, "control_z"}});}
  inline std::wostream& operator<<(std::wostream& os, console_special_key value) {return os << to_string(value, {{console_special_key::control_break, L"control_break"}, {console_special_key::control_c, L"control_c"}, {console_special_key::control_backslash, L"control_backslash"}, {console_special_key::control_z, L"control_z"}});}
  /// @endcond
}
