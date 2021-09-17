/// @file
/// @brief Contains xtd::background_color class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent background color output manipulator class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::console::background_color method.
  class background_color final : public object {
  public:
    /// @brief Sets the background color of the console.
    /// @param color A xtd::console_color that specifies the background color of the console; that is, the color that appears behind each character.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    explicit background_color(console_color color) : color(color) {}
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const background_color& color) {
      if (!console::is_out_redireted() && os.rdbuf() == console::out.rdbuf())
        console::background_color(color.color);
      return os;
    }
    /// @endcond

  private:
    console_color color ;
  };
}
