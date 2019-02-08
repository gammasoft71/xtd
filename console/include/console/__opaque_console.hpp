/// @file
/// @brief Contains xtd::console class.
#pragma once
#include "console_color.hpp"
#include "console_key_info.hpp"
#include "console_special_key.hpp"

#include <iostream>
#include <map>
#include <string>

/// @cond
namespace xtd {
  template<class Char>
  class basic_console;
}

class __opaque_console final {
  template<class Char>
  friend class xtd::basic_console;
  static xtd::console_color background_color() noexcept;
  static bool background_color(xtd::console_color color) noexcept;
  static bool beep(unsigned int frequency, unsigned int duration) noexcept;
  static int buffer_height() noexcept;
  static bool buffer_height(int height) noexcept;
  static int buffer_width() noexcept;
  static bool buffer_width(int width) noexcept;
  static bool caps_lock() noexcept;
  static bool clrscr() noexcept;
  static int cursor_left() noexcept;
  static int cursor_size() noexcept;
  static void cursor_size(int size) noexcept;
  static int cursor_top() noexcept;
  static bool cursor_visible() noexcept;
  static void cursor_visible(bool visible) noexcept;
  static xtd::console_color foreground_color() noexcept;
  static bool foreground_color(xtd::console_color color) noexcept;
  static int input_code_page() noexcept;
  static bool input_code_page(int codePage) noexcept;
  static int output_code_page() noexcept;
  static bool output_code_page(int codePage) noexcept;
  static bool reset_color() noexcept;
  static bool set_cursor_position(int left, int top) noexcept;
  static std::map<int, xtd::console_special_key> signal_keys() noexcept;
  static int window_left() noexcept;
  static int window_height() noexcept;
  static int window_top() noexcept;
  static int window_width() noexcept;
};
/// @endcond
