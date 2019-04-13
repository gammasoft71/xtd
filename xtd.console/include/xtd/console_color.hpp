/// @file
/// @brief Contains xtd::console_color enum class.
#pragma once
#include <string>
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @enum console_color
  /// @brief Specifies constants that define foreground and background colors for the console.
  /// @see console
  enum class console_color {
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
}

/// @cond
template<typename Char>
std::basic_ostream<Char>& operator<<(std::basic_ostream<Char>& os, xtd::console_color c) {
  switch (c) {
    case xtd::console_color::black: os << std::basic_string<Char> {'b', 'l', 'a', 'c', 'k'}; break;
    case xtd::console_color::dark_blue: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'b', 'l', 'u', 'e'}; break;
    case xtd::console_color::dark_green: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'g', 'r', 'e', 'e', 'n'}; break;
    case xtd::console_color::dark_cyan: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'c', 'y', 'a', 'n'}; break;
    case xtd::console_color::dark_red: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'r', 'e', 'd'}; break;
    case xtd::console_color::dark_magenta: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'm', 'a', 'g', 'e', 'n', 't', 'a'}; break;
    case xtd::console_color::dark_yellow: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'y', 'e', 'l', 'l', 'o', 'w'}; break;
    case xtd::console_color::gray: os << std::basic_string<Char> {'g', 'r', 'a', 'y'}; break;
    case xtd::console_color::dark_gray: os << std::basic_string<Char> {'d', 'a', 'r', 'k', '_', 'g', 'r', 'a', 'y'}; break;
    case xtd::console_color::blue: os << std::basic_string<Char> {'b', 'l', 'u', 'e'}; break;
    case xtd::console_color::green: os << std::basic_string<Char> {'g', 'r', 'e', 'e', 'n'}; break;
    case xtd::console_color::cyan: os << std::basic_string<Char> {'c', 'y', 'a', 'n'}; break;
    case xtd::console_color::red: os << std::basic_string<Char> {'r', 'e', 'd'}; break;
    case xtd::console_color::magenta: os << std::basic_string<Char> {'m', 'a', 'g', 'e', 'n', 't', 'a'}; break;
    case xtd::console_color::yellow: os << std::basic_string<Char> {'y', 'e', 'l', 'l', 'o', 'w'}; break;
    case xtd::console_color::white: os << std::basic_string<Char> {'w', 'h', 'i', 't', 'e'}; break;
    default: os << static_cast<int>(c); break;
  }
  return os;
}
/// @endcond
