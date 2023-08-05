/// @file
/// @brief Contains thread API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstddef>
#include <cstdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace threading {
    class thread;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains thread native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ thread final {
      thread() = delete;
      friend xtd::threading::thread;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Cancel thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool cancel(intmax_t handle);
      
      /// @brief Gets the current thread handle.
      /// @return The current thread handle.
      /// @warning Internal use only
      static intmax_t get_current_thread_handle();

      /// @brief Resume thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool resume(intmax_t handle);
      
      /// @brief Sets the current thread name.
      /// @param name The current thread name.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool set_current_thread_name(const std::string& name);

      /// @brief Sets the thread priority.
      /// @param handle The thread handle.
      /// @param priority The thread priority.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      /// @remarks
      /// * 0 : lowest
      /// * 1 : below_normal
      /// * 2 : normal
      /// * 3 : above_normal
      /// * 4 : highest
      static bool set_priority(intmax_t handle, int_least32_t priority);

      /// @brief Suspend thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool suspend(intmax_t handle);
      /// @}
    };
  }
}
