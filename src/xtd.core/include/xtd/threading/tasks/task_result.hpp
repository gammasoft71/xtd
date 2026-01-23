/// @file
/// @brief Contains xtd::threading::tasks::task <result_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "basic_task.hpp"
#include "../../func.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
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
        task(const xtd::func<result_t>& func) {
          data_->func = func;
          set_task_run();
        }
        task(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state) {
          data_->parameterized_func = func;
          basic_task<result_t>::data_->state = &state;
          set_task_run();
        }
        /// @}

        /// @cond
        task(const std::function<result_t()>& func) {
          data_->func = func;
          set_task_run();
        }
        task(const std::function<result_t(const xtd::any_object&)>& func, const xtd::any_object& state) {
          data_->parameterized_func = func;
          basic_task<result_t>::data_->state = &state;
          set_task_run();
        }
        /// @endcond

        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto result() const noexcept -> const result_t& {return data_->result;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        void start() {
          if (basic_task<result_t>::data_->status != xtd::threading::tasks::task_status::created || (basic_task<result_t>::data_->milliseconds_delay == basic_task<result_t>::timeout_none && data_->func.is_empty() && data_->parameterized_func.is_empty()))
            xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          basic_task<result_t>::start();
        }
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        [[nodiscard]] static auto run(const xtd::func<result_t>& func) -> task {
          auto result = task {func};
          result.start();
          return result;
        }
        /// @}
        
        /// @cond
        [[nodiscard]] static auto run(const std::function<result_t()>& func) -> task {
          auto result = task {func};
          result.start();
          return result;
        }
        /// @endcond

        /// @name Public Operators
        
        /// @{
        /// @}
        
      private:
        auto set_task_run() -> void {
          basic_task<result_t>::data_->task_run = xtd::action<> {delegate_ {
            if (!data_->func.is_empty()) data_->result = std::move(data_->func());
            else if (!data_->parameterized_func.is_empty()) data_->result = std::move(data_->parameterized_func(*basic_task<result_t>::data_->state));
            else xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          }};
        }
        
        struct data {
          xtd::func<result_t> func;
          xtd::func<result_t, const xtd::any_object&> parameterized_func;
          result_t result;
        };
        
        xtd::sptr<data> data_ = xtd::new_sptr<data>();
      };
      
      /// @cond
      template<class result_t>
      auto basic_task<result_t>::completed_task() -> task<result_t> {
        return from_result(result_t {});
      }

      template<class result_t>
      template<class from_result_t>
      auto basic_task<result_t>::from_result(from_result_t result) -> task<from_result_t> {
        auto task = xtd::threading::tasks::task<from_result_t> {};
        task.data_->status = xtd::threading::tasks::task_status::ran_to_completion;
        return task;
      }
      /// @endcond
    }
  }
}
