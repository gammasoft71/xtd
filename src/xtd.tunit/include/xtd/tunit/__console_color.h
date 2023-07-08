/// @file
/// @brief Contains __demangle function.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TUNIT_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../tunit_export.h"
#include "settings.h"
#include <iostream>

/// @cond
enum class __console_color {
  black,
  dark_blue,
  dark_green,
  dark_cyan,
  dark_red,
  dark_magenta,
  dark_yellow,
  gray,
  dark_gray,
  blue,
  green,
  cyan,
  red,
  magenta,
  yellow,
  white
};

tunit_export_ void __opaque_foreground_color(__console_color);
tunit_export_ void __opaque_reset_color();

template<class char_t>
inline std::basic_streambuf<char_t>* __opaque_get_out_rdbuf() {return nullptr;}

template<>
inline std::basic_streambuf<char>* __opaque_get_out_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cout.rdbuf();
  return rdbuf;
}

template<>
inline std::basic_streambuf<wchar_t>* __opaque_get_out_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcout.rdbuf();
  return rdbuf;
}

class __foreground_color final {
public:
  explicit __foreground_color(__console_color color) : color_(color) {}
  
  template<typename char_t>
  friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const __foreground_color& color) {
    if (os.rdbuf() == __opaque_get_out_rdbuf<char_t>() && xtd::tunit::settings::default_settings().output_color())
      __opaque_foreground_color(color.color_);
    return os;
  }
  
private:
  __console_color color_;
};

class __reset_color final {
public:
  __reset_color() = default;
  
  template<typename char_t>
  friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const __reset_color&) {
    if (os.rdbuf() == __opaque_get_out_rdbuf<char_t>() && xtd::tunit::settings::default_settings().output_color())
      __opaque_reset_color();
    return os;
  }
};
/// @endcond
