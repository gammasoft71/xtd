/// @file
/// @brief Contains xtd::beep class.
#pragma once
#include "console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  class beep final {
  public:
    beep() = default;

    beep(unsigned int frequency, unsigned int duration) : frequency_(frequency), duration_(duration) {}
    
    /// @cond
    template<typename Char>
    friend std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const beep& b) {
      if (os.rdbuf() == __get_out_rdbuf<Char>() || os.rdbuf() == __get_err_rdbuf<Char>())
        console::beep(b.frequency_, b.duration_);
      return os;
    }
    /// @endcond
    
  private:
    unsigned int frequency_ {800};
    unsigned int duration_ {200};
  };
}
