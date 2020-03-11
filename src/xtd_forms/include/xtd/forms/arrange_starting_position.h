#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the starting position that the system uses to arrange minimized windows.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a flags attribute attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration is used by the arrange_starting_position property of the systemonformation class.
    enum class arrange_starting_position {
      /// @brief Starts at the lower-left corner of the screen, which is the default position.
      bottom_left = 0,
      /// @brief Starts at the lower-right corner of the screen.
      bottom_right = 1,
      /// @brief Starts at the upper-left corner of the screen.
      top_left = 2,
      /// @brief Starts at the upper-right corner of the screen.
      top_right = 3,
      /// @brief Hides minimized windows by moving them off the visible area of the screen.
      hide = 8
    };

    /// @cond
    inline arrange_starting_position& operator +=(arrange_starting_position& lhs, arrange_starting_position rhs) {lhs = static_cast<arrange_starting_position>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline arrange_starting_position& operator -=(arrange_starting_position& lhs, arrange_starting_position rhs) {lhs = static_cast<arrange_starting_position>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline arrange_starting_position& operator &=(arrange_starting_position& lhs, arrange_starting_position rhs) {lhs = static_cast<arrange_starting_position>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline arrange_starting_position& operator |=(arrange_starting_position& lhs, arrange_starting_position rhs) {lhs = static_cast<arrange_starting_position>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline arrange_starting_position& operator ^=(arrange_starting_position& lhs, arrange_starting_position rhs) {lhs = static_cast<arrange_starting_position>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline arrange_starting_position operator +(arrange_starting_position lhs, arrange_starting_position rhs) {return static_cast<arrange_starting_position>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline arrange_starting_position operator -(arrange_starting_position lhs, arrange_starting_position rhs) {return static_cast<arrange_starting_position>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline arrange_starting_position operator ~(arrange_starting_position rhs) {return static_cast<arrange_starting_position>(~static_cast<long long>(rhs));}
    inline arrange_starting_position operator &(arrange_starting_position lhs, arrange_starting_position rhs) {return static_cast<arrange_starting_position>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline arrange_starting_position operator |(arrange_starting_position lhs, arrange_starting_position rhs) {return static_cast<arrange_starting_position>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline arrange_starting_position operator ^(arrange_starting_position lhs, arrange_starting_position rhs) {return static_cast<arrange_starting_position>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, arrange_starting_position value) {return os << to_string(value, {{arrange_starting_position::bottom_left, "bottom_left"}, {arrange_starting_position::bottom_right, "bottom_right"}, {arrange_starting_position::top_left, "top_left"}, {arrange_starting_position::top_right, "top_right"}, {arrange_starting_position::hide, "hide"}});}
    inline std::wostream& operator<<(std::wostream& os, arrange_starting_position value) {return os << to_string(value, {{arrange_starting_position::bottom_left, L"bottom_left"}, {arrange_starting_position::bottom_right, L"bottom_right"}, {arrange_starting_position::top_left, L"top_left"}, {arrange_starting_position::top_right, L"top_right"}, {arrange_starting_position::hide, L"hide"}});}
    /// @endcond
  }
}
