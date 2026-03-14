/// @file
/// @brief Contains xtd::threading::this_thread namespace.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "thread.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::this_thread namespace contains some current thread properties and sheduling methods.
    namespace this_thread {
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets the thread handle of the current thread.
      /// @return The thread handle of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      [[nodiscard]] auto handle() noexcept -> xtd::intptr;
      
      /// @brief Gets the managed thread id of the current thread.
      /// @return The managed thread id of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      [[nodiscard]] auto managed_thread_id() noexcept -> xtd::int32;
      
      /// @brief Gets the thread name of the current thread.
      /// @return The thread name of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      [[nodiscard]] auto name() noexcept -> xtd::string;
      /// @brief Sets the thread name of the current thread.
      /// @param name The thread name of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      auto name(const xtd::string& name) -> void;
      
      /// @brief Gets the thread priority of the current thread.
      /// @return The thread priority of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      [[nodiscard]] auto priority() noexcept -> xtd::threading::thread_priority;
      /// @brief Sets the thread priority of the current thread.
      /// @param priority The thread priority of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      auto priority(xtd::threading::thread_priority priority) -> void;
      
      /// @brief Gets the thread id of the current thread.
      /// @return The thread id of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      [[nodiscard]] auto thread_id() noexcept -> xtd::intptr;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Returns the thread id of the current thread.
      /// @return The thread id of the current thread.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      [[nodiscard]] auto get_id() noexcept -> xtd::intptr;
      
      /// @brief Stops the execution of the current thread for a specified time duration.
      /// @param sleep_duration The   time duration to sleep.
      /// @remarks Blocks the execution of the current thread for at least the specified `sleep_duration`.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      auto sleep_for(const xtd::time_span& sleep_duration) -> void;
      
      /// @brief Stops the execution of the current thread until a specified time point.
      /// @param sleep_time The time to block until.
      /// @remarks Blocks the execution of the current thread until specified `sleep_time` has been reached.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      auto sleep_until(const xtd::date_time& sleep_time) -> void;
      
      /// @brief Suggests that the implementation reschedule execution of threads.
      /// @return `true` if the operating system switched execution to another thread; otherwise, `false`.
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/thread>
      /// ```
      /// @par Namespace
      /// xtd
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading
      auto yield() noexcept -> bool;
      /// @}
    }
  }
}
