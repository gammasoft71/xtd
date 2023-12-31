/// @file
/// @brief Contains xtd::speech::synthesis::speak_started_event_args alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "prompt_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @brief Returns notification from the xtd::speech::synthesis::speech_synthesizer::speak_started event.
      /// @par Header
      /// @code #include <xtd/speech/synthesis/speak_started_event_args> @endcode
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      using speak_started_event_args = prompt_event_args;
    }
  }
}
