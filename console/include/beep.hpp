/// @file
/// @brief Contains console class.
#pragma once
#include "console.hpp"

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  class beep final {
  public:
    beep() = default;

    beep(unsigned int frequency, unsigned int duration) : frequency_(frequency), duration_(duration) {}
    
    /// @cond
    friend std::ostream& operator <<(std::ostream& os, const beep& b) {
      if (os.rdbuf() == __cout_rdbuf)
        console::beep(b.frequency_, b.duration_);
      return os;
    }
    /// @endcond
    
  private:
    unsigned int frequency_ {800};
    unsigned int duration_ {200};
  };
}
