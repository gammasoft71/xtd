/// @file
/// @brief Contains xtd::threading::tasks::task_status enum class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../enum.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Represents the current stage in the lifecycle of a xtd::threading::tasks::task.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/tasks/task_status>
      /// ```
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      enum class task_status {
        /// @brief The task has been initialized but has not yet been scheduled.
        created,
        /// @brief The task is waiting to be activated and scheduled internally by the Switch infrastructure.
        waiting_for_activation,
        /// @brief The task has been scheduled for execution but has not yet begun executing.
        waiting_to_run,
        /// @brief The task is running but has not yet completed.
        running,
        /// @brief The task has finished executing and is implicitly waiting for attached child tasks to complete.
        waiting_for_children_to_complete,
        /// @brief The task completed execution successfully.
        ran_to_completion,
        /// @brief The task acknowledged cancellation by throwing an OperationCanceledException with its own CancellationToken while the token was in signaled state, or the task's CancellationToken was already signaled before the task started executing. For more information, see Task Cancellation.
        canceled,
        /// @brief The task completed due to an unhandled exception.
        faulted
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::threading::tasks::task_status> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::threading::tasks::task_status> {{xtd::threading::tasks::task_status::created, "created"}, {xtd::threading::tasks::task_status::waiting_for_activation, "waiting_for_activation"}, {xtd::threading::tasks::task_status::waiting_to_run, "waiting_to_run"}, {xtd::threading::tasks::task_status::running, "running"}, {xtd::threading::tasks::task_status::waiting_for_children_to_complete, "waiting_for_children_to_complete"}, {xtd::threading::tasks::task_status::ran_to_completion, "ran_to_completion"}, {xtd::threading::tasks::task_status::canceled, "canceled"}, {xtd::threading::tasks::task_status::faulted, "faulted"}};}
};
/// @endcond
