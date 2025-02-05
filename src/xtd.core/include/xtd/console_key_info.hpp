/// @file
/// @brief Contains xtd::console_key_info class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "console_key.hpp"
#include "console_modifiers.hpp"
#include "iequatable.hpp"
#include "object.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the standard keys on a console.
  /// @par Header
  /// ```cpp
  /// #include <xtd/console_key_info>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see Console
  class console_key_info final : public object, public xtd::iequatable<console_key_info> {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of console_key_info class.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The console_key_info type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info() noexcept = default;
    
    /// @brief Initializes a new instance of the console_key_info class using the specified character, console key, and modifier keys.
    /// @param keyChar The Unicode character that corresponds to the key parameter.
    /// @param key The console key that corresponds to the keyChar parameter.
    /// @param shift `true` to indicate that a SHIFT key was pressed; otherwise, `false`.
    /// @param alt `true` to indicate that an ALT key was pressed; otherwise, `false`.
    /// @param control `true` to indicate that a CTRL key was pressed; otherwise, `false`.
    /// @remarks This type is not intended to be created by users. Instead, it is returned to the user in response to calling the Console::ReadKey method.
    /// @remarks The console_key_info type does not specify whether the left or right SHIFT, ALT, or CTRL modifier key was pressed
    console_key_info(char32 key_char, console_key key, bool shift, bool alt, bool control) noexcept;
    /// @}
    
    /// @cond
    console_key_info(const console_key_info& key_info) noexcept = default;
    console_key_info& operator =(const console_key_info& key_info) noexcept = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the console key represented by the current console_key_info object.
    /// @param A console_key value that identifies the console key that was pressed
    console_key key() const noexcept;
    
    /// @brief Gets the Unicode character represented by the current console_key_info object.
    /// @param An char32 object that corresponds to the console key represented by the current console_key_info object.
    char32 key_char() const noexcept;
    
    /// @brief Gets a bitwise combination of console_modifiers values that specifies one or more modifier keys pressed simultaneously with the console key.
    /// @param A bitwise combination of console_modifiers values. There is no default value.
    console_modifiers modifiers() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override;
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const console_key_info& key_info) const noexcept override;

    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override;    
    /// @}
    
  private:
    char32 key_char_ {0};
    console_key key_ {static_cast<console_key>(0)};
    console_modifiers modifiers_ {static_cast<console_modifiers>(0)};
  };
}
