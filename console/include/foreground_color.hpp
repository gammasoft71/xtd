/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  class foreground_color final {
  public:
    explicit foreground_color(console_color color) : color_(color) {}
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const foreground_color& color) {
      if (os.rdbuf() == __get_out_rdbuf<Char>() || os.rdbuf() == __get_err_rdbuf<Char>())
        console::foreground_color(color.color_);
      return os;
    }
    /// @endcond

  private:
    console_color color_;
  };
}
