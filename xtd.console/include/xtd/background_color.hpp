/// @file
/// @brief Contains xtd::background_color class.
#pragma once
#include "basic_console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Represent background color output manipulator class.
  /// @see xtd::basic_console<Char>::background_color(console_color color) method.
  class background_color final {
  public:
    explicit background_color(console_color color) : color(color) {}
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const background_color& color) {
      if (os.rdbuf() == __get_out_rdbuf<Char>() || os.rdbuf() == __get_err_rdbuf<Char>())
        basic_console<Char>::background_color(color.color);
      return os;
    }
    /// @endcond

  private:
    console_color color ;
  };
}
