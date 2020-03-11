/// @file
/// @brief Contains xtd::beep class.
#pragma once
#include "basic_console.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent beep output manipulator class.
  /// @see xtd::basic_console<char_t>::beep(unsigned int frequency, unsigned int duration) method.
  class beep final {
  public:
    beep() = default;

    beep(unsigned int frequency, unsigned int duration) : frequency_(frequency), duration_(duration) {}
    
    /// @cond
    template<typename char_t>
    friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const beep& b) {
      if (os.rdbuf() == __get_out_rdbuf<char_t>() || os.rdbuf() == __get_err_rdbuf<char_t>())
        basic_console<char_t>::beep(b.frequency_, b.duration_);
      return os;
    }
    /// @endcond
    
  private:
    unsigned int frequency_ {800};
    unsigned int duration_ {200};
  };
}
