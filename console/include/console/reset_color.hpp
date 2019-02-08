/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  class reset_color final {
  public:
    reset_color() = default;
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const reset_color&) {
      if (os.rdbuf() == __get_out_rdbuf<Char>() || os.rdbuf() == __get_err_rdbuf<Char>())
        console::reset_color();
      return os;
    }
    /// @endcond
  };
}
