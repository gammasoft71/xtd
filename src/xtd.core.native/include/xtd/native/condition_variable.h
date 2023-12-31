/// @file
/// @brief Contains condition_variable API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstddef>
#include <cstdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace threading {
    class monitor;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains condition_variable native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @remarks xtd::threading::semaphore does not use xtd::native::condition_variable API as it uses std::recursive_timed_mutex class.
    /// @warning Internal use only
    class core_native_export_ condition_variable final {
      condition_variable() = delete;
      friend xtd::threading::monitor;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Create condition variable.
      /// @return The handle of the created condition variable.
      /// @warning Internal use only
      static intmax_t create();
      
      /// @brief Destroy condition variable with specified condition variable handle.
      /// @param handle The condition variable handle to destroy.
      /// @warning Internal use only
      static void destroy(intmax_t handle);
      
      /// @brief Pulse wainting condition variable with specified condition variable handle.
      /// @param handle The condition variable handle to pulse.
      /// @return true if succeed; otherwhise false.
      static void pulse(intmax_t handle);

      /// @brief Pulse all waiting condition variable with specified condition variable handle.
      /// @param handle The condition variable handle to pulse all.
      /// @return true if succeed; otherwhise false.
      static void pulse_all(intmax_t handle);

      /// @brief Wait`condition variable with specified condition variable handle.
      /// @param handle The condition variable handle to release.
      /// @param critical_section_handle The critical section handle associate to the condition variable handle.
      /// @param milliseconds_timeout The timeout in milliseconds (-1 is infinite timeout).
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool wait(intmax_t handle, intmax_t critical_section_handle, int_least32_t milliseconds_timeout);
      /// @}
    };
  }
}
