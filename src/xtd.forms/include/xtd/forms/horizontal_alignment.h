/// @file
/// @brief Contains xtd::forms::horizontal_alignment enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies how an object or text in a control is horizontally aligned relative to an element of the control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used in numerous classes. A partial list of these classes is xtd::forms::checked_list_box, xtd::forms::column_header, xtd::forms::combo_box, xtd::forms::control_paint, xtd::forms::label, ListBox, xtd::forms::control, xtd::forms::rich_text_box, and xtd::forms::text_box.
    enum class horizontal_alignment {
      /// @brief The object or text is aligned on the left of the control element.
      left = 0,
      /// @brief The object or text is aligned on the right of the control element.
      right = 1,
      /// @brief The object or text is aligned in the center of the control element.
      center = 2,
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, horizontal_alignment value) {return os << to_string(value, {{horizontal_alignment::left, "left"}, {horizontal_alignment::right, "right"}, {horizontal_alignment::center, "center"}});}
    inline std::wostream& operator<<(std::wostream& os, horizontal_alignment value) {return os << to_string(value, {{horizontal_alignment::left, L"left"}, {horizontal_alignment::right, L"right"}, {horizontal_alignment::center, L"center"}});}
    /// @endcond
  }
}
