/// @file
/// @brief Contains xtd::beep class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent beep output manipulator class.
  /// @par Header
  /// @code #include <xtd/beep> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::console::beep method.
  class beep final : public object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Plays the sound of a beep through the console speaker.
    /// @remarks By default, the beep plays at a frequency of 800 hertz for a duration of 200 milliseconds
    /// @par Examples
    /// The following example demonstrates the beep method. The example accepts a number from 1 through 9 as a command line argument, and plays the beep that number of times.
    /// @include console_beep3.cpp
    beep() = default;
    
    /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
    /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
    /// @param duration The duration of the beep measured in milliseconds
    /// @par Examples
    /// This example demonstrates the beep method by playing the first few notes of a song through the console speaker.
    /// @include console_song3.cpp
    beep(uint32 frequency, uint32 duration) : frequency_(frequency), duration_(duration) {}
    /// @}
    
    /// @cond
    friend std::ostream& operator <<(std::ostream& os, const beep& b) {
      if (!console::is_output_redirected() && os.rdbuf() == console::out.rdbuf())
        console::beep(b.frequency_, b.duration_);
      return os;
    }
    /// @endcond
    
  private:
    uint32 frequency_ {800};
    uint32 duration_ {200};
  };
}
