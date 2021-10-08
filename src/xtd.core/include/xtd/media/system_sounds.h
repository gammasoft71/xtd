/// @file
/// @brief Contains xtd::media::system_sounds class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../object.h"
#include "../static.h"
#include "system_sound.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::media namespace contains classes for playing sound files and accessing sounds provided by the system.
  namespace media {
    /// @brief Retrieves sounds associated with a set of Windows operating system sound-event types. This class cannot be inherited.
    /// @par Namespace
    /// xtd::media
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core media
    class core_export_ system_sounds static_ {
    public:
      /// @brief Gets the sound associated with the Asterisk program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Asterisk program event in the current Windows sound scheme.A SystemSound associated with the Asterisk program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::system_sounds::asterisk property.
      /// @code
      /// // Plays the sound associated with the Asterisk system event.
      /// system_sounds.asterisk().play();
      /// @endcode
      static system_sound asterisk();
      
      /// @brief Gets the sound associated with the Beep program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Beep program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::system_sounds::beep property.
      /// @code
      /// // Plays the sound associated with the Beep system event.
      /// system_sounds.asterisk().play();
      /// @endcode
      static system_sound beep();
      
      /// @brief Gets the sound associated with the Exclamation program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Exclamation program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::system_sounds::exclamation property.
      /// @code
      /// // Plays the sound associated with the Exclamation system event.
      /// system_sounds.exclamation().play();
      /// @endcode
      static system_sound exclamation();
      
      /// @brief Gets the sound associated with the Hand program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Hand program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::system_sounds::hand property.
      /// @code
      /// // Plays the sound associated with the Hand system event.
      /// system_sounds.hand().play();
      /// @endcode
      static system_sound hand();
      
      /// @brief Gets the sound associated with the Question program event in the current Windows sound scheme.
      /// @return A xtd::media::system_sound associated with the Question program event in the current Windows sound scheme.
      /// @par Examples
      /// The following code example demonstrates the use of the xtd::system_sounds::questioon property.
      /// @code
      /// // Plays the sound associated with the Questioon system event.
      /// system_sounds.question().play();
      /// @endcode
      static system_sound question();
    };
  }
}
