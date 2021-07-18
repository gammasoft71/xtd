/// @file
/// @brief Contains xtd::reset_color class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "basic_console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent reset color output manipulator class.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::basic_console<char_t>::reset_color() method.
  class reset_color final : public object {
  public:
    reset_color() = default;
    
    /// @cond
    template<typename char_t>
    friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const reset_color&) {
      if (os.rdbuf() == __get_out_rdbuf<char_t>() || os.rdbuf() == __get_err_rdbuf<char_t>())
        basic_console<char_t>::reset_color();
      return os;
    }
    /// @endcond
  };
}
