/// @file
/// @brief Contains __opaque_console class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../console_color.h"
#include "../core_export.h"
#include "../console_key_info.h"
#include "../console_special_key.h"

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
  static bool beep(uint32_t frequency, uint32_t duration);
  static int32_t buffer_height();
  static bool buffer_height(int32_t height);
  static int32_t buffer_width();
  static bool buffer_width(int32_t width);
  static bool caps_lock();
  static bool clear();
  static int32_t cursor_left();
  static int32_t cursor_size();
  static void cursor_size(int32_t size);
  static int32_t cursor_top();
  static bool cursor_visible();
  static void cursor_visible(bool visible);
  static xtd::console_color foreground_color();
  static bool foreground_color(xtd::console_color color);
  static int32_t input_code_page();
  static bool input_code_page(int32_t codePage);
  static bool key_available();
  static int32_t largest_window_height();
  static int32_t largest_window_width();
  static bool number_lock();
  static int32_t output_code_page();
  static bool output_code_page(int32_t codePage);
  static void read_key(int32_t& key_char, int32_t& key_code, bool& alt, bool& shift, bool& ctrl);
  static bool reset_color();
  static bool set_cursor_position(int32_t left, int32_t top);
  static std::string title();
  static bool title(const std::string& title);
  static bool treat_control_c_as_input();
  static void treat_control_c_as_input(bool treat_control_c_as_input);
  static int32_t window_height();
  static void window_height(int32_t height);
  static int32_t window_left();
  static void window_left(int32_t left);
  static int32_t window_top();
  static void window_top(int32_t top);
  static int32_t window_width();
  static void window_width(int32_t width);
};
/// @endcond
