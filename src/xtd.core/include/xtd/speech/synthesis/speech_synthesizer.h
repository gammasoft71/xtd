/// @file
/// @brief Contains xtd::predicate delegate.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "../../object.h"
#include "../../ustring.h"
#include "prompt.h"

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
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core speech synthesis
      class core_export_ speech_synthesizer : public xtd::object {
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
        /// @}

        /// @name Methods
        
        /// @{
        /// @brief Synchronously speaks the contents of a string.
        /// @param text_to_speak The text to speak.
        /// @remarks To asynchronously speak the contents of a xtd::speech::synthesis::prompt_builder object, use xtd::speech::synthesis::speech_synthesizer::speak_async.
        void speak(const xtd::ustring& text_to_speak) const;
        /// @brief Synchronously speaks the contents of a xtd::speech::synthesis::prompt object.
        /// @param prompt The content to speak.
        /// @remarks To asynchronously speak the contents of a xtd::speech::synthesis::prompt_builder object, use xtd::speech::synthesis::speech_synthesizer::speak_async.
        void speak(xtd::speech::synthesis::prompt& prompt) const;
        
        /// @brief Asynchronously speaks the contents of a string.
        /// @param text_to_speak The text to speak.
        /// @return Returns the object that contains the content to speak.
        prompt speak_async(const xtd::ustring& text_to_speak) const;
        /// @brief Asynchronously speaks the contents of a xtd::speech::synthesis::prompt object.
        /// @param prompt The content to speak.
        void speak_async(xtd::speech::synthesis::prompt& prompt) const;
        /// @}

        /// @name Events
        
        /// @{
        /// @}
        
      private:
        struct data {
          intptr_t handle = 0;
          int32_t rate = 0;
          int32_t volume = 100;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
