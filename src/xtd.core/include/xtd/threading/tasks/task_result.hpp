/// @file
/// @brief Contains xtd::threading::tasks::task <result_t> class.
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
      template<class result_t>
      class task : public xtd::threading::tasks::basic_task<result_t> {
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
        task(const xtd::func<result_t>& func) : basic_task<result_t> {func} {}
        task(const xtd::func<result_t>& func, const xtd::threading::cancellation_token& cancellation_token) : basic_task<result_t> {func, cancellation_token} {}
        task(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state) : basic_task<result_t> {func, state} {}
        task(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) : basic_task<result_t> {func, state, cancellation_token} {}
        /// @}

        /// @cond
        task(const std::function<result_t()>& func) : basic_task<result_t> {func} {}
        task(const std::function<result_t()>& func, const xtd::threading::cancellation_token& cancellation_token) : basic_task<result_t> {func, cancellation_token} {}
        task(const std::function<result_t(const xtd::any_object&)>& func, const xtd::any_object& state) : basic_task<result_t> {func, state} {}
        task(const std::function<result_t(const xtd::any_object&)>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) : basic_task<result_t> {func, state, cancellation_token} {}
        /// @endcond

        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto result() const noexcept -> const result_t& {return basic_task<result_t>::data_->result;}
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        [[nodiscard]] static auto from_result(result_t result) -> task {
          auto t = task {};
          t.data_->result = result;
          t.basic_task<result_t>::data_->status = xtd::threading::tasks::task_status::ran_to_completion;
          t.basic_task<result_t>::data_->end_event.set();
          return t;
        }
        /// @}
      };
      
      /// @cond
      /// @endcond
    }
  }
}

#include "task_factory.hpp"
