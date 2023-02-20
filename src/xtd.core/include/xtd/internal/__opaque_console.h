/// @file
/// @brief Contains __opaque_console class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../console_color.h"
#include "../core_export.h"
#include "../console_key_info.h"
#include "../console_special_key.h"
#include "../types.h"

#include <iostream>
#include <map>
#include <string>

/// @cond
struct __console_intercept_signals;

namespace xtd {
  class console;
}

class core_export_ __opaque_console final {
  friend class xtd::console;
  friend struct ::__console_intercept_signals;
  static xtd::console_color background_color();
  static bool background_color(xtd::console_color color);
  static bool beep(xtd::uint32 frequency, xtd::uint32 duration);
  static xtd::int32 buffer_height();
  static bool buffer_height(xtd::int32 height);
  static xtd::int32 buffer_width();
  static bool buffer_width(xtd::int32 width);
  static bool caps_lock();
  static bool clear();
  static xtd::int32 cursor_left();
  static xtd::int32 cursor_size();
  static void cursor_size(xtd::int32 size);
  static xtd::int32 cursor_top();
  static bool cursor_visible();
  static void cursor_visible(bool visible);
  static xtd::console_color foreground_color();
  static bool foreground_color(xtd::console_color color);
  static xtd::int32 input_code_page();
  static bool input_code_page(xtd::int32 codePage);
  static bool key_available();
  static xtd::int32 largest_window_height();
  static xtd::int32 largest_window_width();
  static bool number_lock();
  static xtd::int32 output_code_page();
  static bool output_code_page(xtd::int32 codePage);
  static void read_key(xtd::char32& key_char, xtd::char32& key_code, bool& alt, bool& shift, bool& ctrl);
  static bool reset_color();
  static bool set_cursor_position(xtd::int32 left, xtd::int32 top);
  static std::string title();
  static bool title(const std::string& title);
  static bool treat_control_c_as_input();
  static void treat_control_c_as_input(bool treat_control_c_as_input);
  static xtd::int32 window_height();
  static void window_height(xtd::int32 height);
  static xtd::int32 window_left();
  static void window_left(xtd::int32 left);
  static xtd::int32 window_top();
  static void window_top(xtd::int32 top);
  static xtd::int32 window_width();
  static void window_width(xtd::int32 width);
};
/// @endcond
