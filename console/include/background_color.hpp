/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  class background_color final {
  public:
    explicit background_color(console_color color) : color(color) {}
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const background_color& color) {
      if (os.rdbuf() == __get_out_rdbuf<Char>() || os.rdbuf() == __get_err_rdbuf<Char>())
        console::background_color(color.color);
      return os;
    }
    /// @endcond

  private:
    console_color color ;
  };
}

