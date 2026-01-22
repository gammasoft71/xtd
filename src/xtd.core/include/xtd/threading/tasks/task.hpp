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
      class task<void> : public xtd::threading::tasks::basic_task<void> {
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
        task(const xtd::action<>& action) {data_->action = action;}
        task(const xtd::action<const xtd::any_object&>& action, const xtd::any_object& state) {
          data_->parameterized_action = action;
          basic_task<void>::data_->state = &state;
        }
        /// @}

        /// @cond
        task(const std::function<void()>& action) {data_->action = action;}
        task(const std::function<void(const xtd::any_object&)>& action, const xtd::any_object& state) {
          data_->parameterized_action = action;
          basic_task<void>::data_->state = &state;
        }
        /// @endcond

        
        /// @name Public Properties
        
        /// @{
        /// @}
        
        /// @name Public Methods
        
        /// @{
        auto run_synchronously() -> void {
          basic_task<void>::data_->status = xtd::threading::tasks::task_status::waiting_for_activation;
          task_proc(*basic_task<void>::data_->state, false);
          basic_task<void>::data_->status = xtd::threading::tasks::task_status::waiting_to_run;
        }
        
        auto start() -> void {
          if (basic_task<void>::data_->status != xtd::threading::tasks::task_status::created || (basic_task<void>::data_->milliseconds_delay == -2 && data_->action.is_empty() && data_->parameterized_action.is_empty()))
            xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          
          basic_task<void>::data_->status = xtd::threading::tasks::task_status::waiting_for_activation;
          thread_pool::register_wait_for_single_object(basic_task<void>::data_->start_event, task_proc, *basic_task<void>::data_->state, xtd::threading::timeout::infinite, true);
          basic_task<void>::data_->status = xtd::threading::tasks::task_status::waiting_to_run;
          basic_task<void>::data_->start_event.set();
        }
        
        auto wait() -> void {wait(xtd::threading::timeout::infinite);}
        
        auto wait(xtd::int32 milliseconds_timeout) -> bool {
          bool result = basic_task<void>::data_->end_event.wait_one(milliseconds_timeout);
          if (basic_task<void>::data_->status == xtd::threading::tasks::task_status::faulted)
            throw basic_task<void>::data_->exception;
          basic_task<void>::data_->status = xtd::threading::tasks::task_status::ran_to_completion;
          return result;
        }
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
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
        struct data {
          xtd::action<> action;
          xtd::action<xtd::any_object> parameterized_action;
        };

        xtd::threading::wait_or_timer_callback task_proc = {delegate_(const xtd::any_object& state, bool timed_out) {
          basic_task<void>::current_id_ = basic_task<void>::data_->id;
          basic_task<void>::data_->status = xtd::threading::tasks::task_status::running;
          try {
            if (basic_task<void>::data_->milliseconds_delay != -2)
              thread::sleep(basic_task<void>::data_->milliseconds_delay);
            if (!data_->action.is_empty())
              data_->action();
            else if (!data_->parameterized_action.is_empty())
              data_->parameterized_action(*basic_task<void>::data_->state);
            basic_task<void>::data_->status = xtd::threading::tasks::task_status::waiting_for_children_to_complete;
            basic_task<void>::data_->end_event.set();
          } catch (...) {
            basic_task<void>::data_->exception = aggregate_exception {}; // (array<xtd::exception_ptr> {excptr::current_exception()});
            basic_task<void>::data_->status = xtd::threading::tasks::task_status::faulted;
            basic_task<void>::data_->end_event.set();
          }
        }};

        xtd::sptr<data> data_ = xtd::new_sptr<data>();
      };
    }
  }
}
