#pragma once
#include <iostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class mouse_buttons {
      none = 0,
      left = 0x100000,
      right = 0x200000,
      middle = 0x400000,
      x_button1 = 0x800000,
      x_button2 = 0x1000000
    };
    
    /// @cond
    inline xtd::forms::mouse_buttons& operator +=(xtd::forms::mouse_buttons& lhs, xtd::forms::mouse_buttons rhs) {lhs = static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline xtd::forms::mouse_buttons& operator -=(xtd::forms::mouse_buttons& lhs, xtd::forms::mouse_buttons rhs) {lhs = static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline xtd::forms::mouse_buttons& operator &=(xtd::forms::mouse_buttons& lhs, xtd::forms::mouse_buttons rhs) {lhs = static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline xtd::forms::mouse_buttons& operator |=(xtd::forms::mouse_buttons& lhs, xtd::forms::mouse_buttons rhs) {lhs = static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline xtd::forms::mouse_buttons& operator ^=(xtd::forms::mouse_buttons& lhs, xtd::forms::mouse_buttons rhs) {lhs = static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline xtd::forms::mouse_buttons operator +(xtd::forms::mouse_buttons lhs, xtd::forms::mouse_buttons rhs) {return static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline xtd::forms::mouse_buttons operator -(xtd::forms::mouse_buttons lhs, xtd::forms::mouse_buttons rhs) {return static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline xtd::forms::mouse_buttons operator ~(xtd::forms::mouse_buttons rhs) {return static_cast<xtd::forms::mouse_buttons>(~static_cast<int>(rhs));}
    inline xtd::forms::mouse_buttons operator &(xtd::forms::mouse_buttons lhs, xtd::forms::mouse_buttons rhs) {return static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline xtd::forms::mouse_buttons operator |(xtd::forms::mouse_buttons lhs, xtd::forms::mouse_buttons rhs) {return static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline xtd::forms::mouse_buttons operator ^(xtd::forms::mouse_buttons lhs, xtd::forms::mouse_buttons rhs) {return static_cast<xtd::forms::mouse_buttons>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
    
    inline std::ostream& operator<<(std::ostream& os, xtd::forms::mouse_buttons value) {
      return os << std::to_string(static_cast<int>(value));
    }
    /// @endcond
  }
}
