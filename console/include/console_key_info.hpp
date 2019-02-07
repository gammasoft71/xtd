/// @file
/// @brief Contains Switch::System::ConsoleKeyInfo class.
#pragma once

#include "console_key.hpp"
#include "console_modifiers.hpp"

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  /// @brief Specifies the standard keys on a console.
  /// @par Library
  /// Switch.Core
  /// @ingroup SwitchCore
  /// @see Console
  class console_key_info final {
  public:
    /// @brief Create a new instance of ConsoleKeyInfo class.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The ConsoleKeyInfo type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info() = default;
    
    /// @brief Create a new instance of ConsoleKeyInfo class.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The ConsoleKeyInfo type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info(const console_key_info& key_info) = default;
    
    /// @cond
    console_key_info& operator=(const console_key_info& keyInfo) = default;
    /// @endcond
    
    /// @brief Initializes a new instance of the ConsoleKeyInfo class using the specified character, console key, and modifier keys.
    /// @param keyChar The Unicode character that corresponds to the key parameter.
    /// @param key The console key that corresponds to the keyChar parameter.
    /// @param shift true to indicate that a SHIFT key was pressed; otherwise, false.
    /// @param alt true to indicate that an ALT key was pressed; otherwise, false.
    /// @param control true to indicate that a CTRL key was pressed; otherwise, false.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The ConsoleKeyInfo type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info(char32_t keyChar, console_key key, bool shift, bool alt, bool control) {
      if (shift == true)
        this->modifiers_ = (console_modifiers)((int)this->modifiers_ | (int)console_modifiers::shift);
      if (alt == true)
        this->modifiers_ = (console_modifiers)((int)this->modifiers_ | (int)console_modifiers::alt);
      if (control == true)
        this->modifiers_ = (console_modifiers)((int)this->modifiers_ | (int)console_modifiers::control);
    }
    
    /// @brief Gets the console key represented by the current ConsoleKeyInfo object.
    /// @param A System::ConsoleKey value that identifies the console key that was pressed
    console_key key() {return this->key_;}
    
    /// @brief Gets the Unicode character represented by the current ConsoleKeyInfo object.
    /// @param An char32 object that corresponds to the console key represented by the current ConsoleKeyInfo object.
    char32_t key_char() {return this->key_char_;}
    
    /// @brief Gets a bitwise combination of System::ConsoleModifiers values that specifies one or more modifier keys pressed simultaneously with the console key.
    /// @param A bitwise combination of System::ConsoleModifiers values. There is no default value.
    console_modifiers modifiers() {return this->modifiers_;}
    
  private:
    char32_t key_char_ {0};
    console_key key_ {static_cast<console_key>(0)};
    console_modifiers modifiers_ {static_cast<console_modifiers>(0)};
  };
}
