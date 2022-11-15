/// @file
/// @brief Contains xtd::console_modifiers enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

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
  add_enum_flag_operators_(xtd::console_modifiers);
  /// @endcond
}

/// @cond
template<> struct xtd::enum_register<xtd::console_modifiers> {
  void operator()(xtd::enum_collection<xtd::console_modifiers>& values, xtd::enum_attribute& attribute) {
    values = {{xtd::console_modifiers::alt, "alt"}, {xtd::console_modifiers::shift, "shift"}, {xtd::console_modifiers::control, "control"}};
    attribute = xtd::enum_attribute::flags;
  }
};
/// @endcond

