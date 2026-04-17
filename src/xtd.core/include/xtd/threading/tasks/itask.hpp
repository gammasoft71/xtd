/// @file
/// @brief Contains xtd::threading::tasks::itask interface.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#include "../cancellation_token.hpp"
#include "../../int32.hpp"
#include "../../interface.hpp"
#include "../../time_span.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Represents an interface for an asynchronous operation.
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks interface
      class itask interface_ {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets an ID for this task instance.
        /// @return The identifier that is assigned by the system to this task instance.
        [[nodiscard]] virtual auto id() const noexcept -> xtd::usize = 0;
        /// @}

        /// @name Public Methods
        
        /// @{
        /// @brief Starts the task, scheduling it for execution to the current xtd::threading::tasks::task_scheduler.
        virtual auto start() -> void = 0;
        
        /// @brief Waits for the task to complete execution.
        virtual auto wait() -> void = 0;
        /// @brief Waits for the task to complete execution with specified milliseconds timout.
        /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
        /// @return `true` if the task completed execution within the allotted time; otherwise, `false`.
        virtual auto wait(xtd::int32 milliseconds_timeout) -> bool = 0;
        /// @brief Waits for the task to complete execution with specified milliseconds timout and cancellation token.
        /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
        /// @return `true` if the task completed execution within the allotted time; otherwise, `false`.
        virtual auto wait(xtd::int32 milliseconds_timeout, xtd::threading::cancellation_token& cancellation_token) -> bool = 0;
        /// @brief Waits for the task to complete execution with specified timout.
        /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::threading::timeout::infinite_time_span that represents -1 milliseconds to wait indefinitely.
        /// @return `true` if the task completed execution within the allotted time; otherwise, `false`.
        virtual auto wait(const xtd::time_span& timeout) -> bool = 0;
        /// @brief Waits for the task to complete execution with specified timout and cancellation token.
        /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::threading::timeout::infinite_time_span that represents -1 milliseconds to wait indefinitely.
        /// @return `true` if the task completed execution within the allotted time; otherwise, `false`.
        virtual auto wait(const xtd::time_span& timeout, xtd::threading::cancellation_token& cancellation_token) -> bool = 0;
        /// @}
      };
    }
  }
}
