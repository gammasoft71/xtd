/// @file
/// @brief Contains xtd::media::system_sound class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::media namespace contains classes for playing sound files and accessing sounds provided by the system.
  namespace media {
    class system_sounds;
    /// @brief Represents a system sound type.
    /// @par Namespace
    /// xtd::media
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core media
    
    class core_export_ system_sound : public object {
    public:
      /// @cond
      system_sound() = default;
      bool equals(const object& obj) const noexcept override;
      bool equals(const system_sound& sound) const noexcept;
      /// @endcond
      
      /// @brief Plays the system sound type.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::system_sounds::asterisk property.
      /// @code
      /// // Plays the sound associated with the Asterisk system event.
      /// system_sounds.asterisk().play();
      /// @endcode
      void play() const;
      
    private:
      friend class system_sounds;
      explicit system_sound(uint32_t type);
      uint32_t type_ = 0;
    };
  }
}
