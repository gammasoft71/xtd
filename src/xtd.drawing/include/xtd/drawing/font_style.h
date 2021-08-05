/// @file
/// @brief Contains xtd::drawing::font_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies style information applied to text. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    enum class font_style {
      /// @brief Normal text.
      regular = 0,
      /// @brief Bold text.
      bold = 0b1,
      /// @brief Italic text.
      italic = 0b10,
      /// @brief Underline text.
      underline = 0b100,
      /// @brief Text with a line through the middle.
      strikeout = 0b1000
    };
    
    /// @cond
    inline font_style& operator +=(font_style& lhs, font_style rhs) {lhs = static_cast<font_style>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline font_style& operator -=(font_style& lhs, font_style rhs) {lhs = static_cast<font_style>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline font_style& operator &=(font_style& lhs, font_style rhs) {lhs = static_cast<font_style>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline font_style& operator |=(font_style& lhs, font_style rhs) {lhs = static_cast<font_style>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline font_style& operator ^=(font_style& lhs, font_style rhs) {lhs = static_cast<font_style>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline font_style operator +(font_style lhs, font_style rhs) {return static_cast<font_style>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline font_style operator -(font_style lhs, font_style rhs) {return static_cast<font_style>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline font_style operator ~(font_style rhs) {return static_cast<font_style>(~static_cast<long long>(rhs));}
    inline font_style operator &(font_style lhs, font_style rhs) {return static_cast<font_style>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline font_style operator |(font_style lhs, font_style rhs) {return static_cast<font_style>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline font_style operator ^(font_style lhs, font_style rhs) {return static_cast<font_style>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, font_style value) {return os << xtd::to_string(value, {{font_style::regular, "regular"}, {font_style::bold, "bold"}, {font_style::italic, "italic"}, {font_style::underline, "underline"}, {font_style::strikeout, "strikeout"}});}
    inline std::wostream& operator<<(std::wostream& os, font_style value) {return os << xtd::to_string(value, {{font_style::regular, L"regular"}, {font_style::bold, L"bold"}, {font_style::italic, L"italic"}, {font_style::underline, L"underline"}, {font_style::strikeout, L"strikeout"}});}
    /// @endcond
  }
}
