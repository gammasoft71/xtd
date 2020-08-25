#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class text_format_flags {
      default_format = 0b0,
      glyph_overhang_padding = 0b0,
      left = 0b0,
      top = 0b0,
      horizontal_center = 0b1,
      rigth = 0b10,
      vertical_center = 0b100,
      bottom = 0b1000,
      word_break = 0b10000,
      sign_line = 0b100000,
      expand_tabs = 0b1000000,
      no_clipping = 0b100000000,
      external_leading = 0b1000000000,
      no_prefix = 0b10000000000,
      internal = 0b1000000000000,
      text_box_control = 0b10000000000000,
      path_ellipsis = 0b100000000000000,
      end_ellipse = 0b1000000000000000,
      modify_string = 0b10000000000000000,
      right_to_left = 0b100000000000000000,
      word_ellipsis = 0b1000000000000000000,
      no_full_width_characterB_break = 0b10000000000000000000,
      hide_prefix = 0b100000000000000000000,
      prefix_only = 0b1000000000000000000000,
      preserve_graphics_clipping = 0b1000000000000000000000000,
      preserve_graphics_translate_transform = 0b10000000000000000000000000,
      no_padding = 0b10000000000000000000000000000,
      left_and_right_padding = 0b100000000000000000000000000000,
    };
    
    /// @cond
    inline text_format_flags& operator +=(text_format_flags& lhs, text_format_flags rhs) {lhs = static_cast<text_format_flags>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline text_format_flags& operator -=(text_format_flags& lhs, text_format_flags rhs) {lhs = static_cast<text_format_flags>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline text_format_flags& operator &=(text_format_flags& lhs, text_format_flags rhs) {lhs = static_cast<text_format_flags>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline text_format_flags& operator |=(text_format_flags& lhs, text_format_flags rhs) {lhs = static_cast<text_format_flags>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline text_format_flags& operator ^=(text_format_flags& lhs, text_format_flags rhs) {lhs = static_cast<text_format_flags>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline text_format_flags operator +(text_format_flags lhs, text_format_flags rhs) {return static_cast<text_format_flags>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline text_format_flags operator -(text_format_flags lhs, text_format_flags rhs) {return static_cast<text_format_flags>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline text_format_flags operator ~(text_format_flags rhs) {return static_cast<text_format_flags>(~static_cast<long long>(rhs));}
    inline text_format_flags operator &(text_format_flags lhs, text_format_flags rhs) {return static_cast<text_format_flags>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline text_format_flags operator |(text_format_flags lhs, text_format_flags rhs) {return static_cast<text_format_flags>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline text_format_flags operator ^(text_format_flags lhs, text_format_flags rhs) {return static_cast<text_format_flags>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, text_format_flags value) {return os << to_string(value, {{text_format_flags::default_format, "default_format"}});}
    inline std::wostream& operator<<(std::wostream& os, text_format_flags value) {return os << to_string(value, {{text_format_flags::default_format, L"default_format"}});}
    /// @endcond
  }
}
