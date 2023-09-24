/// @file
/// @brief Contains xtd::speech::synthesis::synthesizer_state enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @brief Enumerates values for the state of the xtd::speech::synthesis::speech_synthesizer.
      /// @code
      /// enum class synthesizer_state
      /// @endcode
      /// @par Header
      /// @code #include <xtd/speech/synthesis/synthesizer_state> @endcode
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @remarks The xtd::speech::synthesis::speech_synthesizer::state property uses xtd::speech::synthesis::synthesizer_state to indicate the current state of the xtd::speech::synthesis::speech_synthesizer. See xtd::speech::synthesis::speech_synthesizer::state for an example.
      /// @remarks The xtd::speech::synthesis::speech_synthesizer::previous_state and xtd::speech::synthesis::speech_synthesizer::state properties use xtd::speech::synthesis::synthesizer_state to indicate state of the xtd::speech::synthesis::speech_synthesizer when the xtd::speech::synthesis::speech_synthesizer::state_changed event is raised.
      enum class synthesizer_state {
        /// @brief Indicates that the xtd::speech::synthesis::speech_synthesizer is ready to generate speech from a prompt.
        ready = 0,
        /// @brief Indicates that the xtd::speech::synthesis::speech_synthesizer is speaking.
        speaking = 1,
        /// @brief Indicates that the xtd::speech::synthesis::speech_synthesizer is paused.
        pause = 2,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::speech::synthesis::synthesizer_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::speech::synthesis::synthesizer_state> {{xtd::speech::synthesis::synthesizer_state::ready, "ready"}, {xtd::speech::synthesis::synthesizer_state::speaking, "speaking"}, {xtd::speech::synthesis::synthesizer_state::pause, "pause"}};}
};
/// @endcond
