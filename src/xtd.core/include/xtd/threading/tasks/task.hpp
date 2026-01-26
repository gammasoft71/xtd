/// @file
/// @brief Contains xtd::threading::tasks::task <> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_task.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Represents an asynchronous operation.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      template<>
      class task<void> : public xtd::threading::tasks::basic_task<> {
      public:
        /// @cond
        task() = default;
        task(task&&) = default;
        task(const task&) = default;
        auto operator=(task&&) -> task& = default;
        auto operator=(const task&) -> task& = default;
        /// @endcond
        
        /// @name Public Constructors
        
        /// @{
        task(const xtd::action<>& action) : basic_task<> {action} {}
        task(const xtd::action<>& action, const xtd::threading::cancellation_token& cancellation_token) : basic_task<> {action, cancellation_token} {}
        task(const xtd::action<const xtd::any_object&>& action, const xtd::any_object& state) : basic_task<> {action, state} {}
        task(const xtd::action<const xtd::any_object&>& action, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) : basic_task<> {action, state, cancellation_token} {}
        /// @}

        /// @cond
        task(const std::function<void()>& action) : basic_task<> {action} {}
        task(const std::function<void()>& action, const xtd::threading::cancellation_token& cancellation_token) : basic_task<> {action, cancellation_token} {}
        task(const std::function<void(const xtd::any_object&)>& action, const xtd::any_object& state) : basic_task<> {action, state} {}
        task(const std::function<void(const xtd::any_object&)>& action, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) : basic_task<> {action, state, cancellation_token} {}
        /// @endcond
        
        /// @name Public Static Methods
        
        /// @{
        [[nodiscard]] static auto from_result() -> task {
          auto t = task {};
          t.basic_task<>::data_->status = xtd::threading::tasks::task_status::ran_to_completion;
          t.basic_task<>::data_->end_event.set();
          return t;
        }
        /// @}
      };
    }
  }
}

#include "task_result.hpp"
