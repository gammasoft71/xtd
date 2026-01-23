/// @file
/// @brief Contains xtd::threading::tasks::task <> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_task.hpp"
#include "../../action.hpp"
#include "../thread_pool.hpp"

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
        task(const xtd::action<>& action) {
          data_->action = action;
          set_task_run();
        }
        task(const xtd::action<const xtd::any_object&>& action, const xtd::any_object& state) {
          data_->parameterized_action = action;
          basic_task<>::data_->state = &state;
          set_task_run();
        }
        /// @}

        /// @cond
        task(const std::function<void()>& action) {
          data_->action = action;
          set_task_run();
        }
        task(const std::function<void(const xtd::any_object&)>& action, const xtd::any_object& state) {
          data_->parameterized_action = action;
          basic_task<>::data_->state = &state;
          set_task_run();
        }
        /// @endcond

        
        /// @name Public Properties
        
        /// @{
        /// @}
        
        /// @name Public Methods
        
        /// @{
        auto start() -> void {
          if (basic_task<>::data_->status != xtd::threading::tasks::task_status::created || (basic_task<>::data_->milliseconds_delay == basic_task<>::timeout_none && data_->action.is_empty() && data_->parameterized_action.is_empty()))
            xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          basic_task<>::start();
        }
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        [[nodiscard]] static auto from_result() -> task {
          auto t = task {};
          t.basic_task<>::data_->status = xtd::threading::tasks::task_status::ran_to_completion;
          t.basic_task<>::data_->end_event.set();
          return t;
        }
        
        [[nodiscard]] static auto run(const xtd::action<>& action) -> task {
          auto result = task {action};
          result.start();
          return result;
        }
        /// @}

        /// @cond
        [[nodiscard]] static auto run(const std::function<void()>& action) -> task {
          auto result = task {action};
          result.start();
          return result;
        }
        /// @endcond

        /// @name Public Operators
        
        /// @{
        /// @}
        
      private:
        auto set_task_run() -> void {
          basic_task<>::data_->task_run = xtd::action<> {delegate_ {
            if (!data_->action.is_empty()) data_->action();
            else if (!data_->parameterized_action.is_empty()) data_->parameterized_action(*basic_task<>::data_->state);
          }};
        }
        
        struct data {
          xtd::action<> action;
          xtd::action<xtd::any_object> parameterized_action;
        };

        xtd::sptr<data> data_ = xtd::new_sptr<data>();
      };
    }
  }
}
