/// @file
/// @brief Contains xtd::foreground_color class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent foreground color output manipulator class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::console::foreground_color method.
  /// @par Examples
  /// The following example saves the values of the xtd::console_color enumeration to an array and stores the current values of the xtd::background_color and xtd::foreground_color properties to variables. It then changes the foreground color to each color in the xtd::console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the xtd::console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the xtd:::reset_color class to restore the original console colors.
  /// @include console_color4.cpp
  class foreground_color final : public object {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Sets the foreground color of the console.
    /// @param color A xtd::console_color that specifies the foreground color of the console; that is, the color of each character that is displayed.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    /// @par Examples
    /// The following example saves the values of the xtd::console_color enumeration to an array and stores the current values of the xtd::background_color and xtd::foreground_color properties to variables. It then changes the foreground color to each color in the xtd::console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the xtd::console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the xtd::reset_color class to restore the original console colors.
    /// @include console_color4.cpp
    explicit foreground_color(console_color color) : color_(color) {}
    /// @}
    
    /// @cond
    friend std::ostream& operator <<(std::ostream& os, const foreground_color& color) {
      if (!console::is_output_redirected() && os.rdbuf() == console::out.rdbuf())
        console::foreground_color(color.color_);
      return os;
    }
    /// @endcond
    
  private:
    console_color color_;
  };
}
