/// @file
/// @brief Contains xtd::media::system_sound class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.hpp"
#include "../object.hpp"
#include "../uint32.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::media namespace contains classes for playing sound files and accessing sounds provided by the system.
  namespace media {
    class system_sounds;
    /// @brief Represents a system sound type.
    /// ```cpp
    /// class core_export_ system_sound : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::media::system_sound
    /// @par Header
    /// ```cpp
    /// #include <xtd/media/system_sound>
    /// ```
    /// @par Namespace
    /// xtd::media
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core media
    class core_export_ system_sound : public xtd::object {
    public:
      /// @cond
      system_sound() = default;
      /// @endcond
      
      /// @name Public Methods
      
      /// @{
      /// @brief Plays the system sound type.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::asterisk property.
      /// ```cpp
      /// // Plays the sound associated with the Asterisk system event.
      /// system_sounds.asterisk().play();
      /// ```
      void play() const;
      /// @}
      
    private:
      friend class system_sounds;
      explicit system_sound(uint32 type);
      uint32 type_ = 0;
    };
  }
}
