#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
  enum class lcd_style {
    seven_segment_display,
    nine_segment_display,
  };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, lcd_style value) {return os << to_string(value, {{lcd_style::seven_segment_display, "seven_segment_display"}, {lcd_style::nine_segment_display, "nine_segment_display"}});}
    inline std::wostream& operator<<(std::wostream& os, lcd_style value) {return os << to_string(value, {{lcd_style::seven_segment_display, L"seven_segment_display"}, {lcd_style::nine_segment_display, L"nine_segment_display"}});}
    /// @endcond
  }
}
