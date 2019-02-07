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
    friend std::ostream& operator <<(std::ostream& os, const foreground_color& color) {
      if (os.rdbuf() == __cout_rdbuf)
        console::foreground_color(color.color_);
      return os;
    }
    /// @endcond

  private:
    console_color color_;
  };
}
