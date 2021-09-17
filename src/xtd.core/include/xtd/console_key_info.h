/// @file
/// @brief Contains xtd::console_key_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iostream>
#include "console_key.h"
#include "console_modifiers.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the standard keys on a console.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see Console
  class console_key_info final : public object {
  public:
    /// @brief Create a new instance of console_key_info class.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The console_key_info type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info() = default;
    
    /// @cond
    console_key_info(const console_key_info& key_info) noexcept = default;
    console_key_info& operator=(const console_key_info& key_info) noexcept = default;
    bool operator==(const console_key_info& key_info) const noexcept {return key_char_ == key_info.key_char_ && key_ == key_info.key_ && modifiers_ == key_info.modifiers_;}
    bool operator!=(const console_key_info& key_info) const noexcept {return !operator==(key_info);}
    /// @endcond
    
    /// @brief Initializes a new instance of the console_key_info class using the specified character, console key, and modifier keys.
    /// @param keyChar The Unicode character that corresponds to the key parameter.
    /// @param key The console key that corresponds to the keyChar parameter.
    /// @param shift true to indicate that a SHIFT key was pressed; otherwise, false.
    /// @param alt true to indicate that an ALT key was pressed; otherwise, false.
    /// @param control true to indicate that a CTRL key was pressed; otherwise, false.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The console_key_info type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info(char32_t key_char, console_key key, bool shift, bool alt, bool control) : key_char_(key_char), key_(key) {
      if (shift == true)
        modifiers_ = (console_modifiers)((int)modifiers_ | (int)console_modifiers::shift);
      if (alt == true)
        modifiers_ = (console_modifiers)((int)modifiers_ | (int)console_modifiers::alt);
      if (control == true)
        modifiers_ = (console_modifiers)((int)modifiers_ | (int)console_modifiers::control);
    }
    
    /// @brief Gets the console key represented by the current console_key_info object.
    /// @param A console_key value that identifies the console key that was pressed
    console_key key() {return key_;}
    
    /// @brief Gets the Unicode character represented by the current console_key_info object.
    /// @param An char32 object that corresponds to the console key represented by the current console_key_info object.
    char32_t key_char() {return key_char_;}
    
    /// @brief Gets a bitwise combination of console_modifiers values that specifies one or more modifier keys pressed simultaneously with the console key.
    /// @param A bitwise combination of console_modifiers values. There is no default value.
    console_modifiers modifiers() {return modifiers_;}
    
  private:
    char32_t key_char_ {0};
    console_key key_ {static_cast<console_key>(0)};
    console_modifiers modifiers_ {static_cast<console_modifiers>(0)};
  };
}
