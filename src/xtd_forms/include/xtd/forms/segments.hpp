#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a control anchors to the edges of its container.
    /// @remarks This enumeration has a flags  attribute that allows a bitwise combination of its member values.
    /// @remarks When a control is anchored to an edge of its container, the distance between the control and the specified edge remains constant when the container resizes. For example, if a control is anchored to the right edge of its container, the distance between the right edge of the control and the right edge of the container remains constant when the container resizes. A control can be anchored to any combination of control edges. If the control is anchored to opposite edges of its container (for example, to the top and bottom), it resizes when the container resizes. If a control has its anchor property set to none, the control moves half of the distance that the container of the control is resized. For example, if a button has its anchor property set to none and the form that the control is located on is resized by 20 pixels in either direction, the button will be moved 10 pixels in both directions.
    enum class segments {
      /// @brief no segment.
      none = 0,
      /// @brief The a segment.
      a = 0b1,
      /// @brief The b segment.
      b = 0b10,
      /// @brief The c segment.
      c = 0b100,
      /// @brief The d segment.
      d = 0b1000,
      /// @brief The e segment.
      e = 0b10000,
      /// @brief The f segment.
      f = 0b100000,
      /// @brief The g segment.
      g = 0b1000000,

      /// @brief The dp segment (dot point).
      dp = 0b10000000000000000,
      /// @brief The cp segment (punctuation colon).
      pc = 0b100000000000000000,
    };

    /// @cond
    inline segments& operator +=(segments& lhs, segments rhs) {lhs = static_cast<segments>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline segments& operator -=(segments& lhs, segments rhs) {lhs = static_cast<segments>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline segments& operator &=(segments& lhs, segments rhs) {lhs = static_cast<segments>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline segments& operator |=(segments& lhs, segments rhs) {lhs = static_cast<segments>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline segments& operator ^=(segments& lhs, segments rhs) {lhs = static_cast<segments>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline segments operator +(segments lhs, segments rhs) {return static_cast<segments>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline segments operator -(segments lhs, segments rhs) {return static_cast<segments>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline segments operator ~(segments rhs) {return static_cast<segments>(~static_cast<long long>(rhs));}
    inline segments operator &(segments lhs, segments rhs) {return static_cast<segments>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline segments operator |(segments lhs, segments rhs) {return static_cast<segments>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline segments operator ^(segments lhs, segments rhs) {return static_cast<segments>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, segments value) {return os << to_string(value, {{segments::none, "none"}, {segments::a, "a"}, {segments::b, "b"}, {segments::c, "c"}, {segments::d, "d"}, {segments::e, "e"}, {segments::f, "f"}, {segments::g, "g"}, {segments::dp, "dp"}, {segments::pc, "pc"}});}
    inline std::wostream& operator<<(std::wostream& os, segments value) {return os << to_string(value, {{segments::none, L"none"}, {segments::a, L"a"}, {segments::b, L"b"}, {segments::c, L"c"}, {segments::d, L"d"}, {segments::e, L"e"}, {segments::f, L"f"}, {segments::g, L"g"}, {segments::dp, L"dp"}, {segments::pc, L"pc"}});}
    /// @endcond
  }
}
