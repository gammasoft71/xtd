/// @file
/// @brief Contains thread API.
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
#include <functional>
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
      /// @name Protected static methods
      
      /// @{
      /// @brief Cancel thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool cancel(intmax_t handle);
      
      /// @brief Cancel thread with specified handle.
      /// @param start The function to run in the new thread created.
      /// @param obj The argument of the start function.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.
      /// @return The thread handle.
      /// @warning Internal use only
      static intmax_t create(std::function<void(intmax_t)> start, intmax_t obj, int_least32_t max_stack_size, bool suspended, intmax_t& id);
      
      /// @brief Detach thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool detach(intmax_t handle);

      /// @brief Gets the current thread handle.
      /// @return The current thread handle.
      /// @warning Internal use only
      static intmax_t get_current_thread_handle();
      
      /// @brief Gets the thread id.
      /// @param handle The thread handle.
      /// @return The current thread id.
      /// @warning Internal use only
      static intmax_t get_thread_id(intmax_t handle);
      
      /// @brief Join thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool join(intmax_t handle);
      
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
      /// @remarks Possible values for priority paramter :
      /// * 0 : lowest
      /// * 1 : below_normal
      /// * 2 : normal
      /// * 3 : above_normal
      /// * 4 : highest
      static bool set_priority(intmax_t handle, int_least32_t priority);

      /// @brief Suspends the current thread for a specified time.
      /// @param milliseconds_timeout The number of milliseconds for which the thread is blocked. Specify zero (0) to indicate that this thread should be suspended to allow other waiting threads to execute. Specify -1 to block the thread indefinitely.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static void sleep(int_least32_t milliseconds_timeout);

      /// @brief Suspend thread with specified handle.
      /// @param handle The thread handle.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool suspend(intmax_t handle);

      /// @brief Causes the calling thread to yield execution to another thread that is ready to run on the current processor.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool yield();
      /// @}
    };
  }
}
