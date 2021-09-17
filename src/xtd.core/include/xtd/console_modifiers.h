/// @file
/// @brief Contains xtd::console_modifiers enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the SHIFT, ALT, and CTRL modifier keys on a keyboard.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see Console
  enum class console_modifiers {
    /// @brief The left or right ALT modifier key.
    alt = 0b1,
    /// @brief The left or right SHIFT modifier key.
    shift = 0b10,
    /// @brief The left or right CTRL modifier key.
    control = 0b100
  };

  /// @cond
  inline xtd::console_modifiers& operator^=(xtd::console_modifiers& lhs, xtd::console_modifiers rhs) {lhs = static_cast<xtd::console_modifiers>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
  inline xtd::console_modifiers& operator&=(xtd::console_modifiers& lhs, xtd::console_modifiers rhs) {lhs = static_cast<xtd::console_modifiers>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
  inline xtd::console_modifiers& operator|=(xtd::console_modifiers& lhs, xtd::console_modifiers rhs) {lhs = static_cast<xtd::console_modifiers>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
  inline xtd::console_modifiers& operator+=(xtd::console_modifiers& lhs, xtd::console_modifiers rhs) {lhs = static_cast<xtd::console_modifiers>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
  inline xtd::console_modifiers& operator-=(xtd::console_modifiers& lhs, xtd::console_modifiers rhs) {lhs = static_cast<xtd::console_modifiers>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
  inline xtd::console_modifiers operator^(xtd::console_modifiers lhs, xtd::console_modifiers rhs) {return static_cast<xtd::console_modifiers>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
  inline xtd::console_modifiers operator&(xtd::console_modifiers lhs, xtd::console_modifiers rhs) {return static_cast<xtd::console_modifiers>(static_cast<int>(lhs) & static_cast<int>(rhs));}
  inline xtd::console_modifiers operator|(xtd::console_modifiers lhs, xtd::console_modifiers rhs) {return static_cast<xtd::console_modifiers>(static_cast<int>(lhs) | static_cast<int>(rhs));}
  inline xtd::console_modifiers operator+(xtd::console_modifiers lhs, xtd::console_modifiers rhs) {return static_cast<xtd::console_modifiers>(static_cast<int>(lhs) + static_cast<int>(rhs));}
  inline xtd::console_modifiers operator-(xtd::console_modifiers lhs, xtd::console_modifiers rhs) {return static_cast<xtd::console_modifiers>(static_cast<int>(lhs) - static_cast<int>(rhs));}
  inline xtd::console_modifiers operator~(xtd::console_modifiers lhs) {return static_cast<xtd::console_modifiers>(~static_cast<int>(lhs));}  
  inline std::ostream& operator<<(std::ostream& os, console_modifiers value) {return os << to_string(value, {{console_modifiers::alt, "alt"}, {console_modifiers::shift, "shift"}, {console_modifiers::control, "control"}});}
  inline std::wostream& operator<<(std::wostream& os, console_modifiers value) {return os << to_string(value, {{console_modifiers::alt, L"alt"}, {console_modifiers::shift, L"shift"}, {console_modifiers::control, L"control"}});}
  /// @endcond
}
