/// @file
/// @brief Contains xtd::speech::synthesis::speech_synthesizer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "prompt.h"
#include "speak_completed_event_handler.h"
#include "speak_started_event_handler.h"
#include "state_changed_event_handler.h"
#include "synthesizer_state.h"
#include "../../event.h"
#include "../../object.h"
#include "../../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @brief Provides access to the functionality of an installed speech synthesis engine.
      /// @code
      /// class core_export_ speech_synthesizer : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::speech::synthesis::speech_synthesizer
      /// @par Header
      /// @code #include <xtd/speech/synthesis/speech_synthesizer> @endcode
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      class core_export_ speech_synthesizer : public xtd::object {
        struct data;
        
        
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::speech::synthesis::speech_synthesizer class.
        /// @remarks When you initialize a new xtd::speech::synthesis::speech_synthesizer instance, it uses the default system voice. To configure the xtd::speech::synthesis::speech_synthesizer to use one of the installed speech synthesis (text-to-speech) voices, use the xtd::speech::synthesis::speech_synthesizer::select_voice or xtd::speech::synthesis::speech_synthesizer::select_voice_by_hints method. To get information about which voices are installed, use the xtd::speech::synthesis::speech_synthesizer::get_installed_voices method and the xtd::speech::synthesis::voice_info class.
        speech_synthesizer();
        /// @}
        
        /// @cond
        ~speech_synthesizer();
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the current speaking state of the xtd::speech::speech_synthesizer object.
        /// @return Returns the current speaking state of the xtd::speech::speech_synthesizer object.
        synthesizer_state state() const noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Synchronously speaks the contents of a string.
        /// @param text_to_speak The text to speak.
        /// @remarks To asynchronously speak the contents of a xtd::speech::synthesis::prompt_builder object, use xtd::speech::synthesis::speech_synthesizer::speak_async.
        void speak(const xtd::ustring& text_to_speak);
        /// @brief Synchronously speaks the contents of a xtd::speech::synthesis::prompt object.
        /// @param prompt The content to speak.
        /// @remarks To asynchronously speak the contents of a xtd::speech::synthesis::prompt_builder object, use xtd::speech::synthesis::speech_synthesizer::speak_async.
        void speak(xtd::speech::synthesis::prompt& prompt);
        
        /// @brief Asynchronously speaks the contents of a string.
        /// @param text_to_speak The text to speak.
        /// @return Returns the object that contains the content to speak.
        xtd::speech::synthesis::prompt& speak_async(const xtd::ustring& text_to_speak);
        /// @brief Asynchronously speaks the contents of a xtd::speech::synthesis::prompt object.
        /// @param prompt The content to speak.
        void speak_async(xtd::speech::synthesis::prompt& prompt);
        /// @}
        
        /// @name Events
        
        /// @{
        /// @brief Raised when the xtd::speech::synthesis::speech_synthesizer completes the speaking of a prompt.
        /// @remarks The xtd::speech::synthesis::speech_synthesizer raises the xtd::speech::synthesis::speech_synthesizer::speak_completed event at the completion of any of the xtd::speech::synthesis::speech_synthesizer::speak, xtd::speech::synthesis::speech_synthesizer::speak_async, xtd::speech::synthesis::speech_synthesizer::speak_ssml, or xtd::speech::synthesis::speech_synthesizer::speak_ssml_async methods.
        event<speech_synthesizer, speak_completed_event_handler> speak_completed;
        
        /// @brief Raised when the xtd::speech::synthesis::speech_synthesizer begins the speaking of a prompt.
        /// @remarks The xtd::speech::synthesis::speech_synthesizer raises this event when it begins processing a prompt using any of the xtd::speech::synthesis::speech_synthesizer::speak, xtd::speech::synthesis::speech_synthesizer::speak_async, xtd::speech::synthesis::speech_synthesizer::speak_ssml, or xtd::speech::synthesis::speech_synthesizer::speak_ssml_async methods.
        event<speech_synthesizer, speak_started_event_handler> speak_started;
        
        /// @brief Raised when the state of the xtd::speech::synthesis::speech_synthesizer changes.
        /// @remarks The xtd::speech::synthesis::speech_synthesizer raises this event when its speaking xtd::speech::synthesis::speech_synthesizer::state changes. For an example and more information about data associated with the event, see xtd::speech::synthesis::state_changed_event_args.
        /// @remarks To pause and resume speech synthesis, use the xtd::speech::synthesis::speech_synthesizer::pause and xtd::speech::synthesis::speech_synthesizer::resume methods.
        event<speech_synthesizer, state_changed_event_handler> state_changed;
        /// @}
        
      private:
        void on_speak_completed();
        void on_speak_started();
        void set_state(synthesizer_state value);
        
        std::shared_ptr<data> data_;
      };
    }
  }
}
