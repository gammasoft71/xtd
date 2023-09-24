/// @file
/// @brief Contains xtd::console_color enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @enum console_color
  /// @par Header
  /// @code #include <xtd/console_color> @endcode
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
}

/// @cond
template<> struct xtd::enum_register<xtd::console_color> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::console_color> {{xtd::console_color::black, "black"}, {xtd::console_color::dark_blue, "dark_blue"}, {xtd::console_color::dark_green, "dark_green"}, {xtd::console_color::dark_cyan, "dark_cyan"}, {xtd::console_color::dark_red, "dark_red"}, {xtd::console_color::dark_magenta, "dark_magenta"}, {xtd::console_color::dark_yellow, "dark_yellow"}, {xtd::console_color::gray, "gray"}, {xtd::console_color::dark_gray, "dark_gray"}, {xtd::console_color::blue, "blue"}, {xtd::console_color::green, "green"}, {xtd::console_color::cyan, "cyan"}, {xtd::console_color::red, "red"}, {xtd::console_color::magenta, "magenta"}, {xtd::console_color::yellow, "yellow"}, {xtd::console_color::white, "white"}};}
};
/// @endcond
