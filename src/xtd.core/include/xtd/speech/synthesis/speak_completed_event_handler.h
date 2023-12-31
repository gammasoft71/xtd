/// @file
/// @brief Contains xtd::speech::synthesis::speak_completed_event_handler alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "speak_completed_event_args.h"
#include "../../event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @brief Represents the method that will handle xtd::speech::synthesis::speech_synthesizer::speak_completed event.
      /// @par Header
      /// @code #include <xtd/speech/synthesis/speak_completed_event_handler> @endcode
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      using speak_completed_event_handler = delegate<void(object& sender, const speak_completed_event_args& e)>;
    }
  }
}
