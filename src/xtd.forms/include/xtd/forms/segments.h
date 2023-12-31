/// @file
/// @brief Contains xtd::forms::segments enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how a control anchors to the edges of its container.
    /// @par Header
    /// @code #include <xtd/forms/segments> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
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
      /// @brief The h segment.
      h = 0b10000000,
      /// @brief The i segment.
      i = 0b100000000,
      /// @brief The j segment.
      j = 0b1000000000,
      /// @brief The k segment.
      k = 0b10000000000,
      /// @brief The l segment.
      l = 0b100000000000,
      /// @brief The m segment.
      m = 0b1000000000000,
      /// @brief The a1 segment.
      a1 = a,
      /// @brief The a2 segment.
      a2 = 0b10000000000000,
      /// @brief The d1 segment.
      d1 = d,
      /// @brief The d2 segment.
      d2 = 0b100000000000000,
      /// @brief The g1 segment.
      g1 = g,
      /// @brief The g2 segment.
      g2 = 0b1000000000000000,
      /// @brief The dp segment (dot point).
      dp = 0b10000000000000000,
      /// @brief The cp segment (punctuation colon).
      pc = 0b100000000000000000,
    };
  }
}

/// @cond
flags_attribute_(xtd::forms, segments);

template<> struct xtd::enum_register<xtd::forms::segments> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::segments> {{xtd::forms::segments::none, "none"}, {xtd::forms::segments::a, "a"}, {xtd::forms::segments::b, "b"}, {xtd::forms::segments::c, "c"}, {xtd::forms::segments::d, "d"}, {xtd::forms::segments::e, "e"}, {xtd::forms::segments::f, "f"}, {xtd::forms::segments::g, "g"}, {xtd::forms::segments::h, "h"}, {xtd::forms::segments::i, "i"}, {xtd::forms::segments::j, "j"}, {xtd::forms::segments::k, "k"}, {xtd::forms::segments::l, "l"}, {xtd::forms::segments::m, "m"}, {xtd::forms::segments::a2, "a2"}, {xtd::forms::segments::d2, "d2"}, {xtd::forms::segments::g2, "g2"}, {xtd::forms::segments::dp, "dp"}, {xtd::forms::segments::pc, "pc"}};}
};
/// @endcond
