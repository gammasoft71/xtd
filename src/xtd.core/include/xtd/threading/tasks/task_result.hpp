/// @file
/// @brief Contains xtd::threading::tasks::task <result_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "basic_task.hpp"
#include <coroutine>

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
        struct promise_type {
          xtd::runtime::exception_services::exception_dispatch_info exception;
          sptr<xtd::threading::tasks::task<result_t>> task;
          std::coroutine_handle<promise_type> self;

          auto final_suspend() noexcept {
            struct final_awaiter {
              promise_type& promise;
              
              bool await_ready() noexcept {return false;}
              void await_resume() noexcept {}
              void await_suspend(std::coroutine_handle<promise_type> handle) noexcept {
                promise.task->start();
                promise.self.destroy();
              }
            };
            return final_awaiter {*this};
          }
          xtd::threading::tasks::task<result_t> get_return_object() {
            task = xtd::new_ptr<xtd::threading::tasks::task<result_t>>();
            self = std::coroutine_handle<promise_type>::from_promise(*this);
            return *task;
          }
          std::suspend_never initial_suspend() {return {};}
          void return_value(const result_t& result) {task->template basic_task<result_t>::data_->result = result;}
          void unhandled_exception() {exception = task->template basic_task<result_t>::data_->exception;}
        };
        
        struct awaiter {
          xtd::threading::tasks::task<result_t>& task;
          
          bool await_ready() const noexcept {return task.is_completed();}
          void await_suspend(std::coroutine_handle<> handle) {task.continue_with([handle] {handle.resume();});}
          result_t await_resume() {
            if (task.is_faulted()) task.rethrow_exception();
            return task.result();
          }
        };
        
        /// @cond
        task() = default;
        task(task&&) = default;
        task(const task&) = default;
        auto operator=(task&&) -> task& = default;
        auto operator=(const task&) -> task& = default;
        task(const std::coroutine_handle<typename task<result_t>::promise_type>& handle) { {*handle_ = handle;}}
        ~task() {if (handle_.is_unique() && *handle_) handle_->destroy();}

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
        
        /// @name Public Operators
        
        /// @{
        auto operator co_await() noexcept {return awaiter {*this};}
        /// @}

      private:
        xtd::ptr<std::coroutine_handle<promise_type>> handle_ = xtd::new_ptr<std::coroutine_handle<promise_type>>();
      };
    }
  }
}

#include "task_factory.hpp"

