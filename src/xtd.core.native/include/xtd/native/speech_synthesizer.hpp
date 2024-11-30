/// @file
/// @brief Contains path API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
      /// @name Protectedstatic  methods
      
      /// @{
      static intmax_t create();
      static void destroy(intmax_t handle);
      static void pause(intmax_t handle);
      static void resume(intmax_t handle);
      /// @brief Synchronously speaks the contents of a string.
      /// @return The text to speak.
      /// @warning Internal use only
      static void speak(intmax_t handle, const std::string& text_to_speak);
      static void speak_async(intmax_t handle, const std::string& text_to_speak, std::function<void()> on_speak_completed);
      static void stop(intmax_t handle);
      /// @}
    };
  }
}
