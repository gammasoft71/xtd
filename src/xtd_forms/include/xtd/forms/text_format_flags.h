#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class text_format_flags {
      default_format =                                                      0b0,
      glyph_overhang_padding =                                              0b0,
      left =                                                                0b0,
      top =                                                                 0b0,
      horizontal_center =                                                   0b1,
      bottom =                                                           0b1000,
      expand_tabs =                                                  0b100'0000,
      no_clipping =                                               0b1'0000'0000,
      external_leading =                                         0b10'0000'0000,
      internal =                                             0b1'0000'0000'0000,
      end_ellipse =                                       0b1000'0000'0000'0000,
      modify_string =                                   0b1'0000'0000'0000'0000,
      no_full_width_characterB_break =               0b1000'0000'0000'0000'0000,
      hide_prefix =                                0b1'0000'0000'0000'0000'0000,
      no_padding =                       0b1'0000'0000'0000'0000'0000'0000'0000,
      left_and_right_padding =          0b10'0000'0000'0000'0000'0000'0000'0000,
    };
  
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, text_format_flags value) {return os << to_string(value, {{text_format_flags::default_format, "default_format"}});}
    inline std::wostream& operator<<(std::wostream& os, text_format_flags value) {return os << to_string(value, {{text_format_flags::default_format, L"default_format"}});}
    /// @endcond
  }
}
