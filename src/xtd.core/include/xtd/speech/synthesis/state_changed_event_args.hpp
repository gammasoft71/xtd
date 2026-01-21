/// @file
/// @brief Contains xtd::speech::synthesis::state_changed_event_args class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "synthesizer_state.hpp"
#include "../../optional.hpp"
#include "../../any.hpp"
#include "../../event_args.hpp"
#include "../../exception.hpp"
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @cond
      class speech_synthesizer;
      /// @endcond
      
      /// @brief Returns data from the xtd::speech::synthesis::speech_synthesizer::state_changed event.
      /// ```cpp
      /// class state_changed_event_args : public xtd::event_args
      /// ```
      /// @par Inheritance
      /// xtd::event_args → xtd::speech::synthesis::state_changed_event_args
      /// @par Header
      /// ```cpp
      /// #include <xtd/speech/synthesis/state_changed_event_args>
      /// ```
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      /// @remarks An instance of xtd::speech::synthesis::state_changed_event_args is created when the xtd::speech::synthesis::speech_synthesizer object raises the xtd::speech::synthesis::speech_synthesizer::state_changed event. To obtain the values for the new and the previous xtd::speech::synthesis::synthesizer_state, access the xtd::speech::synthesis::state_changed_event_args::state and xtd::speech::synthesis::state_changed_event_args::previous_state properties in the handler for the event.
      class state_changed_event_args : public xtd::event_args {
        friend class speech_synthesizer;
      public:
        /// @cond
        state_changed_event_args(const state_changed_event_args&) = default;
        state_changed_event_args(state_changed_event_args&&) = default;
        state_changed_event_args& operator =(const state_changed_event_args&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the state of the xtd::speech::synthesis::speech_synthesizer before the xtd::speech::synthesis::speech_synthesizer::state_changed event.
        /// @return The state of the synthesizer before the state changed.
        /// @remarks The xtd::speech::synthesis::state_changed_event_args::previous_state property represents the synthesizer state with a member of the xtd::speech::synthesis::synthesizer_state enumeration.
        [[nodiscard]] auto previous_state() const noexcept -> xtd::speech::synthesis::synthesizer_state {return previous_state_;}
        /// @brief Gets the state of the xtd::speech::synthesis::speech_synthesizer after the xtd::speech::synthesis::speech_synthesizer::state_changed event.
        /// @return The state of the synthesizer after the state changed.
        /// @remarks The xtd::speech::synthesis::state_changed_event_args::state property represents the synthesizer state with a member of the xtd::speech::synthesis::synthesizer_state enumeration.
        [[nodiscard]] auto state() const noexcept -> xtd::speech::synthesis::synthesizer_state {return state_;}
        /// @}
        
      private:
        state_changed_event_args(synthesizer_state previous_state, xtd::speech::synthesis::synthesizer_state state) : previous_state_(previous_state), state_(state)  {}
        
        xtd::speech::synthesis::synthesizer_state previous_state_;
        xtd::speech::synthesis::synthesizer_state state_;
      };
    }
  }
}
