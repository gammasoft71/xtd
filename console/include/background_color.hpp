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
    friend std::ostream& operator <<(std::ostream& os, const background_color& color) {
      if (os.rdbuf() == __cout_rdbuf)
        console::background_color(color.color);
      return os;
    }
    /// @endcond

  private:
    console_color color ;
  };
}

