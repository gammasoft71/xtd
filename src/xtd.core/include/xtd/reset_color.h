/// @file
/// @brief Contains xtd::reset_color class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent reset color output manipulator class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::console::reset_color method.
  /// @par Examples
  /// The following example saves the values of the xtd::console_color enumeration to an array and stores the current values of the xtd::background_color and xtd::foreground_color properties to variables. It then changes the foreground color to each color in the xtd::console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the xtd::console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the xtd::reset_color class to restore the original console colors.
  /// @include console_color4.cpp
  class reset_color final : public object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new insttance of xtd::reset_coloor class.
    /// @par Examples
    /// The following example saves the values of the xtd::console_color enumeration to an array and stores the current values of the xtd::background_color and xtd::foreground_color properties to variables. It then changes the foreground color to each color in the xtd::console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the xtd::console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the xtd::reset_color class to restore the original console colors.
    /// @include console_color4.cpp
    reset_color() = default;
    /// @}
    
    /// @cond
    friend std::ostream& operator <<(std::ostream& os, const reset_color&) {
      if (!console::is_output_redirected() && os.rdbuf() == console::out.rdbuf())
        console::reset_color();
      return os;
    }
    /// @endcond
  };
}
