/// @file
/// @brief Contains xtd::reset_color class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
  class reset_color final : public object {
  public:
    reset_color() = default;
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const reset_color&) {
      if (!console::is_out_redireted() && os.rdbuf() == console::out.rdbuf())
        console::reset_color();
      return os;
    }
    /// @endcond
  };
}
