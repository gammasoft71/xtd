/// @file
/// @brief Contains xtd::media::system_sound class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../core_export"
#include "../iequatable"
#include "../object"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::media namespace contains classes for playing sound files and accessing sounds provided by the system.
  namespace media {
    class system_sounds;
    /// @brief Represents a system sound type.
    /// @code
    /// class core_export_ system_sound : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::media::system_sound
    /// @par Header
    /// @code #include <xtd/media/system_sound> @endcode
    /// @par Namespace
    /// xtd::media
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core media
    class core_export_ system_sound : public xtd::iequatable<system_sound>, public xtd::object {
    public:
      /// @cond
      system_sound() = default;
      /// @endcond
      
      /// @name Methods
      
      /// @{
      bool equals(const system_sound& sound) const noexcept override;
      
      /// @brief Plays the system sound type.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::asterisk property.
      /// @code
      /// // Plays the sound associated with the Asterisk system event.
      /// system_sounds.asterisk().play();
      /// @endcode
      void play() const;
      /// @}
      
    private:
      friend class system_sounds;
      explicit system_sound(uint32 type);
      uint32 type_ = 0;
    };
  }
}
