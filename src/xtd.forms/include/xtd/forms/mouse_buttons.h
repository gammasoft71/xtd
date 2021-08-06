/// @file
/// @brief Contains xtd::forms::mouse_buttons enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants that define which mouse button was pressed. This enumeration has a flag attribute that allows a bitwise combination of its member values.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by many classes, including ax_host, control, data_grid, form, radio_button, splitter, status_bar, and up_down_base.
    enum class mouse_buttons {
      /// @brief No mouse button was pressed.
      none = 0,
      /// @brief The left mouse button was pressed.
      left = 0x100000,
      /// @brief The right mouse button was pressed.
      right = 0x200000,
      /// @brief he middle mouse button was pressed.
      middle = 0x400000,
      /// @brief The first XButton (XBUTTON1) on Microsoft IntelliMouse Explorer was pressed.
      x_button1 = 0x800000,
      /// @brief The second XButton (XBUTTON2) on Microsoft IntelliMouse Explorer was pressed.
      x_button2 = 0x1000000
    };
    
    /// @cond
    inline mouse_buttons& operator +=(mouse_buttons& lhs, mouse_buttons rhs) {lhs = static_cast<mouse_buttons>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline mouse_buttons& operator -=(mouse_buttons& lhs, mouse_buttons rhs) {lhs = static_cast<mouse_buttons>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline mouse_buttons& operator &=(mouse_buttons& lhs, mouse_buttons rhs) {lhs = static_cast<mouse_buttons>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline mouse_buttons& operator |=(mouse_buttons& lhs, mouse_buttons rhs) {lhs = static_cast<mouse_buttons>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline mouse_buttons& operator ^=(mouse_buttons& lhs, mouse_buttons rhs) {lhs = static_cast<mouse_buttons>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline mouse_buttons operator +(mouse_buttons lhs, mouse_buttons rhs) {return static_cast<mouse_buttons>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline mouse_buttons operator -(mouse_buttons lhs, mouse_buttons rhs) {return static_cast<mouse_buttons>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline mouse_buttons operator ~(mouse_buttons rhs) {return static_cast<mouse_buttons>(~static_cast<int>(rhs));}
    inline mouse_buttons operator &(mouse_buttons lhs, mouse_buttons rhs) {return static_cast<mouse_buttons>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline mouse_buttons operator |(mouse_buttons lhs, mouse_buttons rhs) {return static_cast<mouse_buttons>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline mouse_buttons operator ^(mouse_buttons lhs, mouse_buttons rhs) {return static_cast<mouse_buttons>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}    
    inline std::ostream& operator<<(std::ostream& os, mouse_buttons value) {return os << to_string(value, {{mouse_buttons::none, "none"}, {mouse_buttons::left, "left"}, {mouse_buttons::right, "right"}, {mouse_buttons::middle, "middle"}, {mouse_buttons::x_button1, "x_button1"}, {mouse_buttons::x_button2, "x_button2"}});}
    inline std::wostream& operator<<(std::wostream& os, mouse_buttons value) {return os << to_string(value, {{mouse_buttons::none, L"none"}, {mouse_buttons::left, L"left"}, {mouse_buttons::right, L"right"}, {mouse_buttons::middle, L"middle"}, {mouse_buttons::x_button1, L"x_button1"}, {mouse_buttons::x_button2, L"x_button2"}});}
    /// @endcond
  }
}
