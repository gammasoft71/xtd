/// @file
/// @brief Contains xtd::media::system_sounds class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_sound.h"
#include "../core_export.h"
#include "../static.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::media namespace contains classes for playing sound files and accessing sounds provided by the system.
  namespace media {
    /// @brief Retrieves sounds associated with a set of Windows operating system sound-event types. This class cannot be inherited.
    /// ```cpp
    /// class core_export_ system_sounds static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::media::system_sounds
    /// @par Header
    /// ```cpp
    /// #include <xtd/media/system_sounds>
    /// ```
    /// @par Namespace
    /// xtd::media
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core media
    class core_export_ system_sounds static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets the sound associated with the Asterisk program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Asterisk program event in the current Windows sound scheme.A SystemSound associated with the Asterisk program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::asterisk property.
      /// ```cpp
      /// // Plays the sound associated with the Asterisk system event.
      /// system_sounds.asterisk().play();
      /// ```
      static system_sound asterisk();
      
      /// @brief Gets the sound associated with the Beep program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Beep program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::beep property.
      /// ```cpp
      /// // Plays the sound associated with the Beep system event.
      /// system_sounds.asterisk().play();
      /// ```
      static system_sound beep();
      
      /// @brief Gets the sound associated with the Exclamation program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Exclamation program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::exclamation property.
      /// ```cpp
      /// // Plays the sound associated with the Exclamation system event.
      /// system_sounds.exclamation().play();
      /// ```
      static system_sound exclamation();
      
      /// @brief Gets the sound associated with the Hand program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Hand program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::hand property.
      /// ```cpp
      /// // Plays the sound associated with the Hand system event.
      /// system_sounds.hand().play();
      /// ```
      static system_sound hand();
      
      /// @brief Gets the sound associated with the Question program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Question program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::media::system_sounds::question property.
      /// ```cpp
      /// // Plays the sound associated with the Question system event.
      /// system_sounds.question().play();
      /// ```
      static system_sound question();
      /// @}
    };
  }
}
