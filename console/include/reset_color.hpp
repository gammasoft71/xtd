/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  class reset_color final {
  public:
    reset_color() = default;
    
    /// @cond
    friend std::ostream& operator <<(std::ostream& os, const reset_color&) {
      if (os.rdbuf() == __cout_rdbuf)
        console::reset_color();
      return os;
    }
    /// @endcond
  };
}
