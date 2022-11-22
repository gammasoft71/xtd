/// @file
/// @brief Contains xtd::speech::synthesis::prompt_event_args class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include <any>
#include <functional>
#include <optional>
#include "../../event_args.h"
#include "../../system_exception.h"
#include "prompt.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::speech namespace contains all classes and namespace to access speech technology.
  namespace speech {
    /// @brief Contains classes for initializing and configuring a speech synthesis engine, for creating prompts, for generating speech, for responding to events, and for modifying voice characteristics.
    namespace synthesis {
      /// @cond
      class speech_synthesizer;
      /// @endcond
      
      /// @brief Provides data for the method_name_completed event.
      /// @code
      /// class prompt_event_args : public xtd::event_args
      /// @endcode
      /// @par Inheritance
      /// xtd::event_args → xtd::speech::synthesis::prompt_event_args
      /// @par Namespace
      /// xtd::speech::synthesis
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core synthesis
      class prompt_event_args : public xtd::event_args {
        friend class speech_synthesizer;
      public:
        /// @cond
        prompt_event_args(const prompt_event_args&) = default;
        prompt_event_args(prompt_event_args&&) = default;
        prompt_event_args& operator =(const prompt_event_args&) = default;
        /// @endcond
        
        /// @brief Gets a value indicating whether an asynchronous operation has been canceled.
        /// @return true if the background operation has been canceled; otherwise false. The default is false.
        bool cancelled() const {return cancelled_;}

        /// @brief Gets a value indicating which error occurred during an asynchronous operation.
        /// @return An xtd::system_exception instance, if an error occurred during an asynchronous operation; otherwise std::nullopt.
        std::optional<std::reference_wrapper<const xtd::system_exception>> error() const {return error_ ? std::optional<std::reference_wrapper<const xtd::system_exception>>(*error_) : std::nullopt; }

        /// @brief Gets the prompt associated with the event.
        /// @return The Prompt object associated with the event.
        const xtd::speech::synthesis::prompt& prompt() const {return *prompt_;}

        /// @brief Gets the unique identifier for the asynchronous task.
        /// @return An object reference that uniquely identifies the asynchronous task.
        std::any user_state() const {return user_state_;}
        
      private:
        prompt_event_args(bool cancelled, const xtd::system_exception* error, xtd::speech::synthesis::prompt* prompt, std::any user_state) : cancelled_(cancelled), error_(error), prompt_(prompt), user_state_(user_state) {}
        prompt_event_args(bool cancelled, const xtd::system_exception* error, xtd::speech::synthesis::prompt* prompt) : cancelled_(cancelled), error_(error), prompt_(prompt){}

        bool cancelled_ = false;
        const xtd::system_exception* error_ = nullptr;
        xtd::speech::synthesis::prompt* prompt_ = nullptr;
        std::any user_state_;
      };
    }
  }
}
