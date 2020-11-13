/// @file
/// @brief Contains std::foreground_color class.
#pragma once
#include "basic_console.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent foreground color output manipulator class.
  /// @see xtd::basic_console<char_t>::foreground_color(console_color color) method.
  class foreground_color final {
  public:
    explicit foreground_color(console_color color) : color_(color) {}
    
    /// @cond
    template<typename char_t>
    friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const foreground_color& color) {
      if (os.rdbuf() == __get_out_rdbuf<char_t>() || os.rdbuf() == __get_err_rdbuf<char_t>())
        basic_console<char_t>::foreground_color(color.color_);
      return os;
    }
    /// @endcond

  private:
    console_color color_;
  };
}
