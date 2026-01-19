/// @file
/// @brief Contains path API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstdint>
#include <functional>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace speech::synthesis {
    class speech_synthesizer;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class file_system;
    /// @endcond
    
    /// @brief Contains path native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ speech_synthesizer final {
      speech_synthesizer() = delete;
      friend xtd::speech::synthesis::speech_synthesizer;
      
    protected:
      /// @name Protected static  methods
      
      /// @{
      /// @brief Create a speach synthesizer.
      /// @return The new speach synthesizer handle created. .
      /// @warning Internal use only
      [[nodiscard]] static auto create() -> std::intmax_t;
      /// @brief Destroys the speach synthesizer.
      /// @param handle The speach synthesizer handle.
      /// @warning Internal use only
      static auto destroy(std::intmax_t handle) -> void;
      /// @brief Pause the speach synthesizer.
      /// @param handle The speach synthesizer handle.
      /// @warning Internal use only
      static auto pause(std::intmax_t handle) -> void;
      /// @brief Resume the speach synthesizer.
      /// @param handle The speach synthesizer handle.
      /// @warning Internal use only
      static auto resume(std::intmax_t handle) -> void;
      /// @brief Synchronously speaks the contents of a string.
      /// @param handle The speach synthesizer handle.
      /// @param text_to_speack The text to speak.
      /// @warning Internal use only
      static auto speak(std::intmax_t handle, const std::string& text_to_speak) -> void;
      /// @brief Asynchronously speaks the contents of a string.
      /// @param handle The speach synthesizer handle.
      /// @param text_to_speack The text to speak.
      /// @param on_speak_completed The callback that will be invoked when speak completed.
      /// @warning Internal use only
      static auto speak_async(std::intmax_t handle, const std::string& text_to_speak, std::function<void()> on_speak_completed) -> void;
      /// @brief Stop the speach synthesizer.
      /// @param handle The speach synthesizer handle.
      /// @warning Internal use only
      static auto stop(std::intmax_t handle) -> void;
      /// @}
    };
  }
}
