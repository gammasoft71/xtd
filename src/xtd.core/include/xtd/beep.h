/// @file
/// @brief Contains xtd::beep class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent beep output manipulator class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::console::beep method.
  class beep final : public object {
  public:
    /// @brief Plays the sound of a beep through the console speaker.
    /// @remarks By default, the beep plays at a frequency of 800 hertz for a duration of 200 milliseconds
    beep() = default;

    /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
    /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
    /// @param duration The duration of the beep measured in milliseconds
    beep(uint32_t frequency, uint32_t duration) : frequency_(frequency), duration_(duration) {}
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const beep& b) {
      if (console::is_out_redirected() && os.rdbuf() == console::out.rdbuf())
        console::beep(b.frequency_, b.duration_);
      return os;
    }
    /// @endcond
    
  private:
    uint32_t frequency_ {800};
    uint32_t duration_ {200};
  };
}
