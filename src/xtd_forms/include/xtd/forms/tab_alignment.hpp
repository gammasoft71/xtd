#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the locations of the tabs in a tab control.
    /// @remarks This enumeration is used by members such as tab_control::alignment.
    enum class tab_alignment {
      /// @brief The tabs are located across the top of the control.
      top = 0,
      /// @brief The tabs are located across the bottom of the control.
      bottom = 1,
      /// @brief The tabs are located along the left edge of the control.
      left = 2,
      /// @brief The tabs are located along the right edge of the control.
      right = 3,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, tab_alignment value) {return os << to_string(value, {{tab_alignment::top, "top"}, {tab_alignment::bottom, "bottom"}, {tab_alignment::left, "left"}, {tab_alignment::right, "right"}});}
    inline std::wostream& operator<<(std::wostream& os, tab_alignment value) {return os << to_string(value, {{tab_alignment::top, L"top"}, {tab_alignment::bottom, L"bottom"}, {tab_alignment::left, L"left"}, {tab_alignment::right, L"right"}});}
    /// @endcond
  }
}
