/// @file
/// @brief Contains xtd::foreground_color class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
  class foreground_color final : public object {
  public:
    explicit foreground_color(console_color color) : color_(color) {}
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const foreground_color& color) {
      if (console::is_out_redireted() && os.rdbuf() == console::out.rdbuf())
        console::foreground_color(color.color_);
      return os;
    }
    /// @endcond

  private:
    console_color color_;
  };
}
