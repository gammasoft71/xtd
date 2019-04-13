/// @file
/// @brief Contains xtd::console_modifiers enum.
#pragma once
#include <string>
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
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

template<typename Char>
std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, xtd::console_modifiers cm) {
  switch (cm) {
    case xtd::console_modifiers::alt: os << std::basic_string<Char> {'a', 'l', 't'}; break;
    case xtd::console_modifiers::shift: os << std::basic_string<Char> {'s', 'h', 'i', 'f', 't'}; break;
    case xtd::console_modifiers::control: os << std::basic_string<Char> {'c', 'o', 'n', 't', 'r', 'o', 'l'}; break;
    default: os << static_cast<int>(cm); break;
  }
  return os;
}
/// @endcond
