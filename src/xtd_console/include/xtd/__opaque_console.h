/// @file
/// @brief Contains xtd::__opaque_console class.
#pragma once
#include "console_color.h"
#include "console_key_info.h"
#include "console_special_key.h"

#include <iostream>
#include <map>
#include <string>

/// @cond
struct __console_intercept_signals;

namespace xtd {
  template<class char_t>
  class basic_console;
}

class __opaque_console final {
  template<class char_t>
  friend class xtd::basic_console;
  friend struct ::__console_intercept_signals;
  static xtd::console_color background_color() noexcept;
  static bool background_color(xtd::console_color color) noexcept;
  static bool beep(unsigned int frequency, unsigned int duration) noexcept;
  static int buffer_height() noexcept;
  static bool buffer_height(int height) noexcept;
  static int buffer_width() noexcept;
  static bool buffer_width(int width) noexcept;
  static bool caps_lock() noexcept;
  static bool clear() noexcept;
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
  static bool key_available() noexcept;
  static int largest_window_height() noexcept;
  static int largest_window_width() noexcept;
  static bool number_lock() noexcept;
  static int output_code_page() noexcept;
  static bool output_code_page(int codePage) noexcept;
  static void read_key(int& key_char, int& key_code, bool& alt, bool& shift, bool& ctrl) noexcept;
  static bool reset_color() noexcept;
  static bool set_cursor_position(int left, int top) noexcept;
  static std::string title() noexcept;
  static bool title(const std::string& title) noexcept;
  static bool treat_control_c_as_input() noexcept;
  static void treat_control_c_as_input(bool treat_control_c_as_input);
  static int window_left() noexcept;
  static int window_height() noexcept;
  static int window_top() noexcept;
  static int window_width() noexcept;
};

/// @endcond
