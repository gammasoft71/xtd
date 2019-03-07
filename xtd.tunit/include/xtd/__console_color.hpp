/// @file
/// @brief Contains __demangle function.
#pragma once
#include "settings.hpp"
#include <iostream>

/// @cond
enum class __console_color {
  /// @brief The color black.
  black,
  /// @brief The color dark blue.
  dark_blue,
  /// @brief The color dark green.
  dark_green,
  /// @brief The color dark cyan (dark blue-green).
  dark_cyan,
  /// @brief The color dark red.
  dark_red,
  /// @brief The color dark magenta (dark purplish-red).
  dark_magenta,
  /// @brief The color dark yellow (ochre).
  dark_yellow,
  /// @brief The color gray.
  gray,
  /// @brief The color dark gray.
  dark_gray,
  /// @brief The color blue.
  blue,
  /// @brief The color green.
  green,
  /// @brief The color cyan (blue-green).
  cyan,
  /// @brief The color red.
  red,
  /// @brief The color magenta (purplish red).
  magenta,
  /// @brief The color yellow.
  yellow,
  /// @brief The color white.
  white
};

void __opaque_foreground_color(__console_color);
void __opaque_reset_color();

template<class Char>
inline std::basic_streambuf<Char>* __opaque_get_out_rdbuf() {return nullptr;};

template<>
inline std::basic_streambuf<char>* __opaque_get_out_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cout.rdbuf();
  return rdbuf;
};

template<>
inline std::basic_streambuf<wchar_t>* __opaque_get_out_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcout.rdbuf();
  return rdbuf;
};

class __foreground_color final {
public:
  explicit __foreground_color(__console_color color) : color_(color) {}
  
  template<typename Char>
  friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const __foreground_color& color) {
    if (os.rdbuf() == __opaque_get_out_rdbuf<Char>() && xtd::tunit::settings::default_settings().output_color())
      __opaque_foreground_color(color.color_);
    return os;
  }
  
private:
  __console_color color_;
};

class __reset_color final {
public:
  __reset_color() = default;
  
  template<typename Char>
  friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const __reset_color&) {
    if (os.rdbuf() == __opaque_get_out_rdbuf<Char>() && xtd::tunit::settings::default_settings().output_color())
      __opaque_reset_color();
    return os;
  }
};
/// @endcond
