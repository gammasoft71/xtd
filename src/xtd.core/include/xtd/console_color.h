/// @file
/// @brief Contains xtd::console_color enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @enum console_color
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
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

  /// @cond
  inline std::ostream& operator<<(std::ostream& os, console_color value) {return os << to_string(value, {{console_color::black, "black"}, {console_color::dark_blue, "dark_blue"}, {console_color::dark_green, "dark_green"}, {console_color::dark_cyan, "dark_cyan"}, {console_color::dark_red, "dark_red"}, {console_color::dark_magenta, "dark_magenta"}, {console_color::dark_yellow, "dark_yellow"}, {console_color::gray, "gray"}, {console_color::dark_gray, "dark_gray"}, {console_color::blue, "blue"}, {console_color::green, "green"}, {console_color::cyan, "cyan"}, {console_color::red, "red"}, {console_color::magenta, "magenta"}, {console_color::yellow, "yellow"}, {console_color::white, "white"}});}
  inline std::wostream& operator<<(std::wostream& os, console_color value) {return os << to_string(value, {{console_color::black, L"black"}, {console_color::dark_blue, L"dark_blue"}, {console_color::dark_green, L"dark_green"}, {console_color::dark_cyan, L"dark_cyan"}, {console_color::dark_red, L"dark_red"}, {console_color::dark_magenta, L"dark_magenta"}, {console_color::dark_yellow, L"dark_yellow"}, {console_color::gray, L"gray"}, {console_color::dark_gray, L"dark_gray"}, {console_color::blue, L"blue"}, {console_color::green, L"green"}, {console_color::cyan, L"cyan"}, {console_color::red, L"red"}, {console_color::magenta, L"magenta"}, {console_color::yellow, L"yellow"}, {console_color::white, L"white"}});}
  /// @endcond
}
