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
