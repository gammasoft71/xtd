/// @file
/// @brief Contains xtd::forms::arrange_direction enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the direction the system uses to arrange minimized windows.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags attribute attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration is used by the arrange_direction property of the system_information class.
    enum class arrange_direction {
      /// @brief Arranges vertically, from top to bottom.
      down = 0x0004,
      /// @brief Arranges horizontally, from left to right.
      left = 0x0000,
      /// @brief Arranges horizontally, from right to left.
      right = 0x0000,
      /// @brief Arranges vertically, from bottom to top.
      up = 0x0004,
    };

    /// @cond
    inline arrange_direction& operator +=(arrange_direction& lhs, arrange_direction rhs) {lhs = static_cast<arrange_direction>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline arrange_direction& operator -=(arrange_direction& lhs, arrange_direction rhs) {lhs = static_cast<arrange_direction>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline arrange_direction& operator &=(arrange_direction& lhs, arrange_direction rhs) {lhs = static_cast<arrange_direction>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline arrange_direction& operator |=(arrange_direction& lhs, arrange_direction rhs) {lhs = static_cast<arrange_direction>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline arrange_direction& operator ^=(arrange_direction& lhs, arrange_direction rhs) {lhs = static_cast<arrange_direction>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline arrange_direction operator +(arrange_direction lhs, arrange_direction rhs) {return static_cast<arrange_direction>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline arrange_direction operator -(arrange_direction lhs, arrange_direction rhs) {return static_cast<arrange_direction>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline arrange_direction operator ~(arrange_direction rhs) {return static_cast<arrange_direction>(~static_cast<long long>(rhs));}
    inline arrange_direction operator &(arrange_direction lhs, arrange_direction rhs) {return static_cast<arrange_direction>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline arrange_direction operator |(arrange_direction lhs, arrange_direction rhs) {return static_cast<arrange_direction>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline arrange_direction operator ^(arrange_direction lhs, arrange_direction rhs) {return static_cast<arrange_direction>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, arrange_direction value) {return os << to_string(value, {{arrange_direction::down, "down"}, {arrange_direction::left, "left"}, {arrange_direction::right, "right"}, {arrange_direction::up, "up"}});}
    inline std::wostream& operator<<(std::wostream& os, arrange_direction value) {return os << to_string(value, {{arrange_direction::down, L"down"}, {arrange_direction::left, L"left"}, {arrange_direction::right, L"right"}, {arrange_direction::up, L"up"}});}
    /// @endcond
  }
}
