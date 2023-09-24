/// @file
/// @brief Contains xtd::speech::synthesis::prompt class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../object"
#include "../../ustring"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @cond
      class speech_synthesizer;
      /// @endcond
      
      /// @brief Represents information about what can be rendered, either text or an audio file, by the xtd::speech::synthesis::speech_synthesizer.
      /// @code
      /// class core_export_ prompt : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::speech::synthesis::prompt
      /// @par Header
      /// @code #include <xtd/speech/synthesis/prompt> @endcode
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      /// @remarks A xtd::speech::synthesis::prompt object can contain plain text, text formatted with markup language, or audio files.
      /// @remarks An empty xtd::speech::synthesis::prompt object is created with each new instance of xtd::speech::synthesis::prompt_builder. The xtd::speech::synthesis::prompt_builder class provides methods for adding content, including text, SSML markup, bookmarks, and prerecorded audio files (such as .wav files), to the empty xtd::speech::synthesis::prompt object that it contains. Typically, applications will use xtd::speech::synthesis::prompt_builder, rather than a xtd::speech::synthesis::prompt object, to create prompts and populate them with content.
      /// @remarks To generate speech from the contents of a xtd::speech::synthesis::prompt object, use the xtd::speech::synthesis::speach_synthesizer::speak method.
      class core_export_ prompt : public xtd::object {
        friend class speech_synthesizer;
        struct data;
        
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::speech::synthesis::speech_synthesizer class.
        /// @remarks When you initialize a new xtd::speech::synthesis::speech_synthesizer instance, it uses the default system voice. To configure the xtd::speech::synthesis::speech_synthesizer to use one of the installed speech synthesis (text-to-speech) voices, use the xtd::speech::synthesis::speech_synthesizer::select_voice or xtd::speech::synthesis::speech_synthesizer::select_voice_by_hints method. To get information about which voices are installed, use the xtd::speech::synthesis::speech_synthesizer::get_installed_voices method and the xtd::speech::synthesis::voice_info class.
        explicit prompt(const xtd::ustring& text_to_speak);
        /// @}
        
        /// @cond
        prompt();
        prompt(const prompt&) = default;
        prompt(prompt&&) = default;
        prompt& operator =(const prompt&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        bool is_completed() const noexcept;
        /// @}
        
      private:
        xtd::ustring& text_to_speak() noexcept;
        void synthesizer(const speech_synthesizer* synthesizer) noexcept;
        std::shared_ptr<data> data_;
      };
    }
  }
}
