/// @file
/// @brief Contains xtd::forms::anchor_styles enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a control anchors to the edges of its container.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags  attribute that allows a bitwise combination of its member values.
    /// @remarks When a control is anchored to an edge of its container, the distance between the control and the specified edge remains constant when the container resizes. For example, if a control is anchored to the right edge of its container, the distance between the right edge of the control and the right edge of the container remains constant when the container resizes. A control can be anchored to any combination of control edges. If the control is anchored to opposite edges of its container (for example, to the top and bottom), it resizes when the container resizes. If a control has its anchor property set to none, the control moves half of the distance that the container of the control is resized. For example, if a button has its anchor property set to none and the form that the control is located on is resized by 20 pixels in either direction, the button will be moved 10 pixels in both directions.
    enum class anchor_styles {
      /// @brief no styles.
      none = 0b0,
      /// @brief Bind control edges to the top of its container.
      top = 0b1,
      /// @brief Bind control edges to the bottom of its container.
      bottom = 0b10,
      /// @brief Bind control edges to the left of its container.
      left = 0b100,
      /// @brief Bind control edges to the right of its container.
      right = 0b1000,
      /// @brief All flags except none.
      all = top | bottom | left | right,
    };

    /// @cond
    inline anchor_styles& operator +=(anchor_styles& lhs, anchor_styles rhs) {lhs = static_cast<anchor_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline anchor_styles& operator -=(anchor_styles& lhs, anchor_styles rhs) {lhs = static_cast<anchor_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline anchor_styles& operator &=(anchor_styles& lhs, anchor_styles rhs) {lhs = static_cast<anchor_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline anchor_styles& operator |=(anchor_styles& lhs, anchor_styles rhs) {lhs = static_cast<anchor_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline anchor_styles& operator ^=(anchor_styles& lhs, anchor_styles rhs) {lhs = static_cast<anchor_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline anchor_styles operator +(anchor_styles lhs, anchor_styles rhs) {return static_cast<anchor_styles>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline anchor_styles operator -(anchor_styles lhs, anchor_styles rhs) {return static_cast<anchor_styles>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline anchor_styles operator ~(anchor_styles rhs) {return static_cast<anchor_styles>(~static_cast<long long>(rhs));}
    inline anchor_styles operator &(anchor_styles lhs, anchor_styles rhs) {return static_cast<anchor_styles>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline anchor_styles operator |(anchor_styles lhs, anchor_styles rhs) {return static_cast<anchor_styles>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline anchor_styles operator ^(anchor_styles lhs, anchor_styles rhs) {return static_cast<anchor_styles>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, anchor_styles value) {return os << to_string(value, {{anchor_styles::none, "none"}, {anchor_styles::top, "top"}, {anchor_styles::bottom, "bottom"}, {anchor_styles::left, "left"}, {anchor_styles::right, "right"}});}
    inline std::wostream& operator<<(std::wostream& os, anchor_styles value) {return os << to_string(value, {{anchor_styles::none, L"none"}, {anchor_styles::top, L"top"}, {anchor_styles::bottom, L"bottom"}, {anchor_styles::left, L"left"}, {anchor_styles::right, L"right"}});}
    /// @endcond
  }
}
