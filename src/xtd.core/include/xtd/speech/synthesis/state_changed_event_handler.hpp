/// @file
/// @brief Contains xtd::speech::synthesis::state_changed_event_handler handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "state_changed_event_args.hpp"
#include "../../event_handler.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @brief Represents the method that will handle xtd::speech::synthesis::speech_synthesizer::speak_started event.
      /// @par Header
      /// ```cpp
      /// #include <xtd/speech/synthesis/state_changed_event_handler>
      /// ```
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      using state_changed_event_handler = delegate<void(object& sender, const state_changed_event_args& e)>;
    }
  }
}
