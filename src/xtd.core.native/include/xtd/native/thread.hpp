/// @file
/// @brief Contains thread API.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Cancel thread with specified handle.
      /// @param handle The thread handle.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto cancel(std::intmax_t handle) -> bool;
      
      /// @brief Cancel thread with specified handle.
      /// @param start The function to run in the new thread created.
      /// @param obj The argument of the start function.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.
      /// @return The thread handle.
      /// @warning Internal use only
      [[nodiscard]] static auto create(std::function<void(std::intmax_t)> start, std::intmax_t obj, std::int32_t max_stack_size, bool suspended, std::intmax_t& id) -> std::intmax_t;
      
      /// @brief Detach thread with specified handle.
      /// @param handle The thread handle.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto detach(std::intmax_t handle) -> bool;
      
      /// @brief Gets the current thread handle.
      /// @return The current thread handle.
      /// @warning Internal use only
      [[nodiscard]] static auto get_current_thread_handle() -> std::intmax_t;
      
      /// @brief Gets the thread id.
      /// @param handle The thread handle.
      /// @return The current thread id.
      /// @warning Internal use only
      [[nodiscard]] static auto get_thread_id(std::intmax_t handle) -> std::intmax_t;
      
      /// @brief Join thread with specified handle.
      /// @param handle The thread handle.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto join(std::intmax_t handle) -> bool;
      
      /// @brief Resume thread with specified handle.
      /// @param handle The thread handle.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto resume(std::intmax_t handle) -> bool;
      
      /// @brief Sets the current thread name.
      /// @param name The current thread name.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto set_current_thread_name(const std::string& name) -> bool;
      
      /// @brief Sets the thread priority.
      /// @param handle The thread handle.
      /// @param priority The thread priority.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      /// @remarks Possible values for priority paramter :
      /// * 0 : lowest
      /// * 1 : below_normal
      /// * 2 : normal
      /// * 3 : above_normal
      /// * 4 : highest
      static auto set_priority(std::intmax_t handle, std::int32_t priority) -> bool;
      
      /// @brief Sets the processors on which the associated thread can run.
      /// @param value An std::vector<size_> that represents an array of processor numbers on which the thread can run.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto set_processor_affinity(std::intmax_t handle, const std::vector<std::size_t>& processor_affinity) -> bool;
      
      /// @brief Suspends the current thread for a specified time.
      /// @param milliseconds_timeout The number of milliseconds for which the thread is blocked. Specify zero (0) to indicate that this thread should be suspended to allow other waiting threads to execute. Specify -1 to block the thread indefinitely.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto sleep(std::int32_t milliseconds_timeout) -> void;
      
      /// @brief Suspend thread with specified handle.
      /// @param handle The thread handle.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto suspend(std::intmax_t handle) -> bool;
      
      /// @brief Causes the calling thread to yield execution to another thread that is ready to run on the current processor.
      /// @return `true` if succeed; otherwise `false`.
      /// @warning Internal use only
      static auto yield() -> bool;
      /// @}
    };
  }
}
