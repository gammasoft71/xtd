#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the bounds of the control to use when defining a control's size and position. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @remarks Use the members of this enumeration when calling the set_bounds_core and set_bounds methods of the control class.
    enum class bounds_specified {
      /// @brief No border.s
      none = 0,
      /// @brief Specifies that the left edge of the control is defined.
      x = 0b1,
      /// @brief Specifies that the top edge of the control is defined.
      y = 0b10,
      /// @brief Specifies that both the x and y coordinates of the control are defined.
      location = 0b11,
      /// @brief Specifies that the width of the control is defined.
      width = 0b100,
      /// @brief Specifies that the height of the control is defined.
      height = 0b1000,
      /// @brief Specifies that both the width and height property values of the control are defined.
      size = 0b1100,
      /// @brief Specifies that both the location and size property values are defined.
      all = 0b1111,
    };

    /// @cond
    inline bounds_specified& operator +=(bounds_specified& lhs, bounds_specified rhs) {lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline bounds_specified& operator -=(bounds_specified& lhs, bounds_specified rhs) {lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline bounds_specified& operator &=(bounds_specified& lhs, bounds_specified rhs) {lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline bounds_specified& operator |=(bounds_specified& lhs, bounds_specified rhs) {lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline bounds_specified& operator ^=(bounds_specified& lhs, bounds_specified rhs) {lhs = static_cast<bounds_specified>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline bounds_specified operator +(bounds_specified lhs, bounds_specified rhs) {return static_cast<bounds_specified>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline bounds_specified operator -(bounds_specified lhs, bounds_specified rhs) {return static_cast<bounds_specified>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline bounds_specified operator ~(bounds_specified rhs) {return static_cast<bounds_specified>(~static_cast<long long>(rhs));}
    inline bounds_specified operator &(bounds_specified lhs, bounds_specified rhs) {return static_cast<bounds_specified>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline bounds_specified operator |(bounds_specified lhs, bounds_specified rhs) {return static_cast<bounds_specified>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline bounds_specified operator ^(bounds_specified lhs, bounds_specified rhs) {return static_cast<bounds_specified>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, bounds_specified value) {return os << to_string(value, {{bounds_specified::none, "none"}, {bounds_specified::x, "x"}, {bounds_specified::y, "y"}, {bounds_specified::width, "width"}, {bounds_specified::height, "height"}});}
    inline std::wostream& operator<<(std::wostream& os, bounds_specified value) {return os << to_string(value, {{bounds_specified::none, L"none"}, {bounds_specified::x, L"x"}, {bounds_specified::y, L"y"}, {bounds_specified::width, L"width"}, {bounds_specified::height, L"height"}});}
    /// @endcond
  }
}
